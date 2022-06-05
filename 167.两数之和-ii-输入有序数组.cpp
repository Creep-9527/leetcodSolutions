/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include<vector>
#include<unordered_map>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>mp;
        int n = numbers.size();
        for (int i = 0; i < n; ++i) {
            if (mp.count(target - numbers[i])) {
                return { mp[target - numbers[i]] + 1,i + 1 };
            }
            else {
                mp[numbers[i]] = i;
            }
        }
        return { -1,-1 };
    }
};
// @lc code=end

