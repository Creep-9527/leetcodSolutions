/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = mid / n * n;
            for (int i = mid / n + 1; i <= m; i++) {
                count += mid / i;
            }
            if (count >= k) {
                right = mid - 1;//right右边的数大于等于k
            }
            else {
                left = mid + 1;//left左边的数小于k
            }
        }
        return left;
    }
};
// @lc code=end

