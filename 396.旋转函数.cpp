/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */
#include<vector>
#include<iostream>
using namespace std;
 // @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int sum = 0;
        int f = 0;
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
            sum += nums[i];
        }
        ans = f;
        for (int i = 1; i < n; i++) {
            f = f + sum - n * nums[n - i];
            ans = max(ans, f);
        }
        return ans;
    }
};
// @lc code=end

