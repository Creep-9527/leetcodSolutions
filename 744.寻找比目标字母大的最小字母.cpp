/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1;
        char ans = letters[0];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] > target) {
                ans = letters[mid];
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

