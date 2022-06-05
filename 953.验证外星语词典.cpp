/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
 // @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>mp;
        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        int n = words.size();
        for (int i = 1; i < n; i++) {
            string str1 = words[i - 1];
            string str2 = words[i];
            int n1 = str1.size();
            int n2 = str2.size();
            int idx = 0;
            while (idx < n1 && idx < n2) {
                if (mp[str1[idx]] > mp[str2[idx]]) {
                    return false;
                }
                else if (mp[str1[idx]] < mp[str2[idx]]) {
                    break;
                }
                else {
                    idx++;
                }
            }
            if (idx < n1 && idx >= n2) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

