/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int low = 0, high = n;
        vector<int>ans(n + 1);
        for (int i = 0; i < n; i++) {
            ans[i] = s[i] == 'I' ? low++ : high--;
        }
        ans[n] = low;
        return ans;
    }
};
// @lc code=end

