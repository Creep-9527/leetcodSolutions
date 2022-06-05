/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */
#include<string>
#include<unordered_set>
using namespace std;
 // @lc code=start
class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char>vowels{ 'a','e','i','o','u','A','E','I','O','U' };
        string ans;
        int n = sentence.size();
        int i = 0;
        int cnt = 1;
        while (i < n) {
            int j = i;
            while (j < n && sentence[j] != ' ') {
                j++;
            }
            cnt++;
            /*开头是元音*/
            if (vowels.count(sentence[i])) {
                ans += sentence.substr(i, j - i) + 'm' + string(cnt, 'a');
            }
            /*开头不是元音*/
            else {
                ans += sentence.substr(i + 1, j - (i + 1)) + sentence[i] + 'm' + string(cnt, 'a');
            }
            if (j < n) {
                ans += ' ';
            }
            i = j + 1;
        }
        return ans;
    }
};
// @lc code=end

