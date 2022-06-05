/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    bool isDivid(int n) {
        int k = n;
        while (k > 0) {
            int t = k % 10;
            if (t == 0 || n % t != 0) {
                return false;
            }
            k /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for (int i = left; i <= right; i++) {
            if (isDivid(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

