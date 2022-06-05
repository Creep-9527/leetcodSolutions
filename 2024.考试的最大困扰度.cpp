/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int l = 0, r = 0;
        int ans = 0;
        int count = 0;
        //统计连续T
        for (r = 0; r < n; r++) {
            if (answerKey[r] == 'F') {
                count++;
                if (count > k) {
                    while (l <= r && count > k) {
                        if (answerKey[l] == 'F') {
                            count--;
                        }
                        l++;
                    }
                }
            }

            ans = max(r - l + 1, ans);
        }
        //统计连续F
        l = 0;
        count = 0;
        for (r = 0; r < n; r++) {
            if (answerKey[r] == 'T') {
                count++;
                if (count > k) {
                    while (l <= r && count > k) {
                        if (answerKey[l] == 'T') {
                            count--;
                        }
                        l++;
                    }
                }
            }

            ans = max(r - l + 1, ans);
        }
        return ans;
    }
};
// @lc code=end

