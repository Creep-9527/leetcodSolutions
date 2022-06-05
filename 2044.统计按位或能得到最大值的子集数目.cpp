/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */
#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxVal = INT_MIN;
    int ans = 0;
    int n;
    vector<int>nums;
    void traversal(int start, int cur) {
        if (start >= n) {
            return;
        }
        for (int i = start; i < n; ++i) {
            int OR = cur | nums[i];
            if (OR > maxVal) {
                ans = 1;
                maxVal = OR;
            }
            else if (OR == maxVal) {
                ++ans;
            }
            traversal(i + 1, OR);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        traversal(0, 0);
        return ans;
    }
};
// @lc code=end

