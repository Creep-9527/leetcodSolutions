/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */
#include<vector>
#include<unordered_set>
using namespace std;
 // @lc code=start
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int>s;
        for (auto num : nums) {
            if (s.count(num) > 0) {
                return num;
            }
            else {
                s.insert(num);
            }
        }
        return -1;
    }
};
// @lc code=end

