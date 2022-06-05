/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
 // @lc code=start
class Solution {
public:
    static bool cmp(const int& a, const int& b) {
        return abs(a) < abs(b);
    }
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int>cnt;
        int zeroCnt = 0;
        for (auto& num : arr) {
            if (num == 0) {
                zeroCnt++;
            }
            else {
                cnt[num]++;
            }
        }
        if ((zeroCnt & 1) != 0) {
            return false;
        }
        vector<int>nums;
        nums.reserve(cnt.size());
        for (auto& ele : cnt) {
            nums.push_back(ele.first);
        }
        sort(nums.begin(), nums.end(), cmp);
        for (auto& e : nums) {
            if (cnt[2 * e] < cnt[e]) {
                return false;
            }
            cnt[2 * e] -= cnt[e];
        }
        return true;
    }
};
// @lc code=end

