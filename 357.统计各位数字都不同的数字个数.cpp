/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 统计各位数字都不同的数字个数
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        vector<int>counts(n + 1);
        counts[0] = 1;
        counts[1] = 10;
        for(int i = 2; i <= n; i++) {
            counts[i] = counts[i - 1] + (counts[i - 1] - counts[i - 2]) * (11 - i);
        }
        return counts[n];
    }
};
// @lc code=end

