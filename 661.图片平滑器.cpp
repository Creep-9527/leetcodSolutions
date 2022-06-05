/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>>ans(n, vector<int>(m));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                long long sum = 0;
                int top = max(0, row - 1);
                int bottom = min(n - 1, row + 1);
                int left = max(0, col - 1);
                int right = min(m - 1, col + 1);
                int count = 0;
                for (int i = top; i <= bottom; i++) {
                    for (int j = left; j <= right; j++) {
                        sum += img[i][j];
                        count++;
                    }
                }
                ans[row][col] = sum / count;
            }
        }
        return ans;
    }
};
// @lc code=end

