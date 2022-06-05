/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto acount : accounts) {
            int temp = 0;
            for (auto i : acount) {
                temp += i;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};
// @lc code=end

