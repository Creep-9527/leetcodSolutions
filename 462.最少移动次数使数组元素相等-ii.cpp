/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */
#include<vector>
#include<algorithm>
using namespace std;
 // @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = 0;
        sort(nums.begin(), nums.end());
        while (l < r) {
            ans += nums[r] - nums[l];
            r--;
            l++;
        }
        return ans;
    }
};
// @lc code=end

