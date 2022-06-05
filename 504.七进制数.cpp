/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        bool nagtive = false;
        if(num<0){
            num = -num;
            nagtive = true;
        }
        string ans;
        while (num>0){
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        if(nagtive){
            ans = "-" + ans;
        }
        return ans;
    }
};
// @lc code=end

