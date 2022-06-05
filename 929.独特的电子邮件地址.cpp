/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
 // @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>domains;
        for (auto email : emails) {
            string local;
            for (char c : email) {
                if (c == '@' || c == '+') {
                    break;
                }
                if (c != '.') {
                    local += c;
                }
            }
            domains.insert(local+email.substr(email.find('@')));
        }
        return domains.size();
    }
};
// @lc code=end

