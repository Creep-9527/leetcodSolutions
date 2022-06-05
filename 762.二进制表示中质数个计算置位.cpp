/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
public:
    int countOne(int n) {
        int ans = 0;
        while (n > 0) {
            n &= n - 1;
            ans++;
        }
        return ans;
    }
    //int mask = 1010 0010 1000 1010 1100
    int countPrimeSetBits(int left, int right) {
        int mask = 0xA28AC;
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (1<<countOne(i) & mask) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

