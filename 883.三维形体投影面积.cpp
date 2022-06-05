/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */
#include<vector>
#include<algorithm>
using namespace std;
 // @lc code=start
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        vector<int>x(n);
        vector<int>y(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                x[i] = max(x[i], grid[i][j]);
                y[j] = max(y[j], grid[i][j]);
                if (grid[i][j]) {
                    ans++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            ans += x[i] + y[i];
        }
        return ans;
    }
};
// @lc code=end

