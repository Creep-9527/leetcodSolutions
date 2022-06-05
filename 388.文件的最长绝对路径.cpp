/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */
#include<string>
#include<stack>
using namespace std;
 // @lc code=start
class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0;
        stack<int>s;
        int pos = 0;
        int n = input.size();
        while (pos < n) {
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                pos++;
                depth++;
            }
            /*计算文件名长度*/
            int len = 0;
            bool isFile = false;
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.') {
                    isFile = true;
                }
                len++;
                pos++;
            }
            
            pos++;

            while (s.size() >= depth) {
                s.pop();
            }

            if (!s.empty()) {
                len += s.top() + 1;
            }
            if (isFile) {
                ans = max(ans, len);
            }
            else {
                s.push(len);
            }
        }
        return ans;
    }
};
// @lc code=end

