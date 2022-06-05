/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxVal = nums[0];
        int minVal = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }
        return maxVal - minVal - 2 * k <= 0 ? 0 : maxVal - minVal - 2 * k;
    }
};
// @lc code=end

