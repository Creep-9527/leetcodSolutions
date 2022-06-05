/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */
#include<vector>
#include<string>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int>ans(n);
        for (int i = 0, idx = -n; i < n; i++) {
            if (s[i] == c) {
                idx = i;
            }
            ans[i] = i - idx;
        }
        for (int i = n - 1, idx = 2 * n; i >= 0; i--) {
            if (s[i] == c) {
                idx = i;
            }
            ans[i] = min(ans[i], idx - i);
        }
        return ans;
    }
};
// @lc code=end

