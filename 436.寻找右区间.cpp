/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */
#include<vector>
#include<algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& inter1, const vector<int>& inter2) {
        return inter1[0] != inter2[0] ? inter1[0] < inter2[0] : inter1[1] < inter2[1];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>startIdx;
        for (int i = 0; i < n; i++) {
            startIdx.push_back({ intervals[i][0], i });
        }
        vector<int>ans(n);
        sort(startIdx.begin(), startIdx.end(), cmp);
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (startIdx[mid][0] >= end) {
                    r = mid - 1;//r右边都大于等于mid
                }
                else {
                    l = mid + 1;//l左边都小于mid
                }
            }
            ans[i] = l == n ? -1 : startIdx[l][1];
        }
        return ans;
    }
};
// @lc code=end

