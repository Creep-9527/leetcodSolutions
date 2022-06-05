/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()){
            return s;
        }
        string ans = "";
        int t = 2 * numRows - 2;
        for (int i = 0; i < numRows;++i){
            for (int j = 0; j + i< s.size();j+=t){
                ans += s[i + j];
                if(i>0 && i<numRows - 1 && j+t-i < s.size()){
                    ans += s[j + t - i];
                }
            }
        }
        return ans;
    }
};
// @lc code=end
int main(){
    
    return 0;
}
