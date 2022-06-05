#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int k = 0;
        for (auto x : data) {
            if (k == 0) {
                if ((x >> 5) == 0b110) {
                    k = 1;
                }
                else if ((x >> 4) == 0b1110) {
                    k = 2;
                }
                else if ((x >> 3) == 0b11110) {
                    k = 3;
                }
                else if ((x >> 7) == 1) {
                    return false;
                }
            }
            else {
                if ((x >> 6) == 0b10) {
                    --k;
                }
                else {
                    return false;
                }
            }
        }
        return k==0;
    }
    
};
// @lc code=end

