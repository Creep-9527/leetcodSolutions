/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>busy;
        set<int>available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }
        vector<int>requests(k);
        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) {
                continue;
            }
            auto p = available.lower_bound(i % k);
            if (p == available.end()) {
                p = available.begin();
            }
            
            busy.emplace(arrival[i] + load[i],*p );
            requests[*p]++;
            available.erase(p);
        }
        int maxVal = *max_element(requests.begin(), requests.end());
        vector<int>ans;
        for (int i = 0; i < k; i++) {
            if (requests[i] == maxVal) {
                ans.push_back(i);
            }
        }
        return ans;

    }
};
// @lc code=end

