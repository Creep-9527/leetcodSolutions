/*
 * @lc app=leetcode.cn id=2039 lang=cpp
 *
 * [2039] 网络空闲的时刻
 */
#include<vector>
#include<queue>
using namespace std;
 // @lc code=start
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>>graph(n);
        vector<bool>visited(n, false);
        for (auto edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        vector<int>dists(n, 0);
        queue<int>q;
        q.push(0);
        visited[0] = true;
        int len = 1;
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int cur = q.front();
                q.pop();
                for (auto v : graph[cur]) {
                    if (visited[v]) {
                        continue;
                    }
                    else {
                        q.push(v);
                        dists[v] = dists[cur] + 1;
                        visited[v] = true;
                    }
                    int di = dists[v] * 2;
                    int t = patience[v];
                    int wait = t * ((di - 1) / t) + di + 1;
                    ans = max(ans, wait);
                }
            }
            len++;
        }
        return ans;
    }
};
// @lc code=end

