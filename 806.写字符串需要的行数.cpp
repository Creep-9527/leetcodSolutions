/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */
#include<vector>
#include<string>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int curWidth = 0;
        int row = 1;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            curWidth += widths[s[i] - 'a'];
            if (curWidth > 100) {
                row++;
                curWidth = widths[s[i] - 'a'];
            }
        }
        return { row,curWidth };
    }
};
// @lc code=end

