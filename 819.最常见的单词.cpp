/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
using namespace std;
 // @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ans;
        int mostCount = 0;
        unordered_set<string>ban;
        for (auto word : banned) {
            ban.insert(word);
        }
        unordered_map<string, int>wordCount;
        int n = paragraph.size();
        string curWord;
        for (int i = 0; i <= n; i++) {
            if (i < n && isalpha(paragraph[i])) {
                curWord.push_back(tolower(paragraph[i]));
            }
            else if (curWord.size() > 0) {
                if (!ban.count(curWord)) {
                    wordCount[curWord]++;
                }
                 curWord.clear();
            }
           
        }
        for (auto [word, count] : wordCount) {
            if (count > mostCount) {
                ans = word;
                mostCount = count;
            }
        }
        return ans;
    }
};
// @lc code=end

