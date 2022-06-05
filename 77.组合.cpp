/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<vector<int>> List;
    vector<int> path;
    void traversal(int n, int start, int k) {
        if (path.size() == k) {
            List.push_back(path);
            return;
        }
        for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            traversal(n, i + 1, k);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        traversal(n, 1, k);
        return List;
    }
};
// @lc code=end

