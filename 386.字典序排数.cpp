/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans(n);
        int number = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = number;
            if (number * 10 <= n) {
                number *= 10;
            }
            else{
                while (number % 10 == 9 || number + 1 > n) {
                    number /= 10;
                }
                number++;
            }
        }
        return ans;
    }
};
// @lc code=end

