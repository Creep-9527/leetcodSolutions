/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == i + 1) {
                continue;
            }
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] - 1 != i) {
                ans.emplace_back(nums[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

