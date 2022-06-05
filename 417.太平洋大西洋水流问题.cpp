/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& vis, int x, int y) {
        if (vis[x][y]) {
            return;
        }
        vis[x][y]++;
        if (x < n - 1 && heights[x + 1][y] >= heights[x][y]) {
            dfs(heights, vis, x + 1, y);
        }
        if (x > 0 && heights[x - 1][y] >= heights[x][y]) {
            dfs(heights, vis, x - 1, y);
        }
        if (y < m - 1 && heights[x][y + 1] >= heights[x][y]) {
            dfs(heights, vis, x, y + 1);
        }
        if (y > 0 && heights[x][y - 1] >= heights[x][y]) {
            dfs(heights, vis, x, y - 1);
        }
        
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>>pacific(n, vector<int>(m, 0));
        vector<vector<int>>atlantic(n, vector<int>(m, 0));
        vector<vector<int>>ans;
        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.emplace_back(vector<int>{i,j});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

