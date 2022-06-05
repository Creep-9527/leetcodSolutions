/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */
#include<vector>
#include<string>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int>preSum(n);
        vector<int>left(n), right(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                ++sum;
            }
            preSum[i] = sum;
        }
        int cur = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') {
                cur = i;
            }
            left[i] = cur;
        }
        cur = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '|') {
                cur = i;
            }
            right[i] = cur;
        }
        vector<int>ans;
        for (auto& query : queries) {
            int x = right[query[0]], y = left[query[1]];
            if (x != -1 && y != -1 && x < y) {
                ans.push_back(preSum[y] - preSum[x]);
            }
            else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};
// @lc code=end

