/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>nums;
        for (auto& op : ops) {
            int n = nums.size();
            if (op == "+") {
                int t = nums[n - 2] + nums[n - 1];
                nums.push_back(t);
            }
            else if (op == "D") {
                int t = 2 * nums[n - 1];
                nums.push_back(t);
            }
            else if (op == "C") {
                nums.pop_back();
            }
            else {
                nums.push_back(stoi(op));
            }
        }
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
    
        return sum;
    }
};
// @lc code=end

