/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */
#include<string>
using namespace std;
 // @lc code=start
class Solution {
public:
    bool winnerOfGame(string colors) {
        int bCount = 0, aCount = 0;
        int n = colors.size();
        for (int i = 2; i < n; i++) {
            if (colors[i - 2] == 'A' && colors[i - 1] == 'A' && colors[i] == 'A') {
                aCount++;
            }
            if (colors[i - 2] == 'B' && colors[i - 1] == 'B' && colors[i] == 'B') {
                bCount++;
            }
        }
        return aCount > bCount;
    }
};
// @lc code=end

