/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> increase(n);
        vector<int> decrease(n);
        for (int i = 1; i < n; ++i){
            if(security[i] <= security[i-1]){
                increase[i] = increase[i - 1] + 1;
            }
            else{
                increase[i] = 0;
            }
        }
        for (int i = n - 2; i >= 0; --i){
            if(security[i] <= security[i+1]){
                decrease[i] = decrease[i + 1] + 1;
            }
            else{
                decrease[i] = 0;
            }
        }
        vector<int> ans;
        for (int i = time; i < n - time; ++i){
            if(increase[i] >= time && decrease[i] >= time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

