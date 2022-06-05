/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
// @lc code=start
static const string Morse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>s;
        for (auto word : words) {
            string code;
            for (auto ch : word) {
                code += Morse[ch - 'a'];
            }
            s.insert(code);
        }
        return s.size();
    }
};
// @lc code=end

