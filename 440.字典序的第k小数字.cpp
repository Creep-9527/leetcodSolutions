/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */
#include<algorithm>
using namespace std;
 // @lc code=start
class Solution {
public:
    long getSteps(int cur, long limit) {
        long first = cur;
        long last = cur;
        long step = 0;
        while (first <= limit) {
            step += min(limit, last) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }
        return step;
    }
    int findKthNumber(int n, int k) {
        long cur = 1;
        k--;
        while (k > 0) {
            long step = getSteps(cur, n);
            if (step <= k) {
                k -= step;
                cur++;
            }
            else {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }
};
// @lc code=end

