/*
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
 // @lc code=start
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        cout << n << endl;
        bool lower = false, upper = false, digit = false;
        for (auto ch : password) {
            if (islower(ch)) {
                lower = true;
            }
            else if (isupper(ch)) {
                upper = true;
            }
            else if (isdigit(ch)) {
                digit = true;
            }
        }
        int category = lower + upper + digit;
        if (n < 6) {
            cout << "!" << endl;
            return max(6 - n, 3 - category);
        }
        else if (n <= 20) {
            int replace = 0;
            int cnt = 0;
            char cur = '#';
            for ( auto ch : password) {
                if (ch == cur) {
                    cnt++;
                }
                else {
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            replace += cnt / 3;
            return max(replace, 3 - category);
        }
        else {
            int replace = 0, remove = n - 20;
            int cnt = 0;
            char cur = '#';
            int rem2 = 0;
            for (const auto& ch : password) {
                if (ch == cur) {
                    cnt++;
                }
                else {
                    if (remove > 0 && cnt >= 3) {
                        if (cnt % 3 == 0) {
                            --remove;
                            --replace;
                        }
                        else if (cnt % 3 == 1) {
                            rem2++;
                        }
                    }
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            if (remove > 0 && cnt >= 3) {
                if (cnt % 3 == 0) {
                    remove--;
                    replace--;
                }
                else if (cnt % 3 == 1) {
                    rem2++;
                }
            }
            replace += cnt / 3;
            int use2 = min({ replace, rem2, remove / 2 });
            replace -= use2;
            remove -= use2 * 2;
            int use3 = min(replace, remove / 3);
            replace -= use3;
            remove -= use3;
            return n - 20 + max(replace, 3 - category);

        }
    }
};
// @lc code=end

