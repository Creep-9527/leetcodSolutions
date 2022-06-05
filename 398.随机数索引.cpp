/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */
#include<vector>
#include<stdlib.h>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int>nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int n = nums.size();
        int cnt = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                cnt++;
                if ((rand() % cnt) == 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

