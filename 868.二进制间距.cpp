/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */
#include<algorithm>
using namespace std;
 // @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int ans = 0;
        for (int i = 0; n > 0; i++) {
            if (n % 2) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
            n = n >> 1;
        }
        return ans;
    }
};
// @lc code=end

