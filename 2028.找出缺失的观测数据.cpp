/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        for (auto roll : rolls) {
            sum -= roll;
        }
        vector<int>ans;
        if (sum > 6 * n || sum < n) {
            return ans;
        }
        ans = vector<int>(n, 1);
        sum -= n;
        for (auto& i : ans) {
            if (sum == 0) {
                break;
            }
            else if (sum <= 5) {
                i += sum;
                sum = 0;
            }
            else {
                i += 5;
                sum -= 5;
            }
        }
        return ans;
    }
};
// @lc code=end

