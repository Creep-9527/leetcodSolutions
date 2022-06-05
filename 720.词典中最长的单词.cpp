/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(string& a, string& b) {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        }
        else {
            return a > b;
        }
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        string ans = "";
        unordered_set<string>pre;
        pre.emplace("");
        for (auto word : words) {
            if (pre.count(word.substr(0, word.size() - 1))) {
                ans = word;
                pre.emplace(word);
            }
        }
        return ans;
    }
};
// @lc code=end

