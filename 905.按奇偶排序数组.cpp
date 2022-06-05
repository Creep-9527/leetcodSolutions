/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if ((nums[l] & 1) == 1 && (nums[r] & 1) == 0) {
                swap(nums[l], nums[r]);
            }
            while (l < n && (nums[l] & 1) == 0) {
                l++;
            }
            while (r >= 0 && (nums[r] & 1) == 1) {
                r--;
            }
        }
        return nums;
    }
};
// @lc code=end

