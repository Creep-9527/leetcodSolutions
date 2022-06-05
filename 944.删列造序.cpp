/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs.size();
        int m = strs[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

