/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int>m;
        for (int i = 0; i < list1.size(); ++i) {
            m[list1[i]] = i;
        }
        int minVal = INT_MAX;
        vector<string>ans;
        for (int i = 0; i < list2.size(); ++i) {
            if (m.find(list2[i])!=m.end()) {
                int idx = i + m[list2[i]];
                if (idx < minVal) {
                    ans.clear();
                    ans.push_back(list2[i]);
                    minVal = idx;
                }
                else if (idx == minVal) {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

