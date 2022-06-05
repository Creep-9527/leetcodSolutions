/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = x1 - points[j][0];
                    int y2 = y1 - points[j][1];
                    int x3 = x1 - points[k][0];
                    int y3 = y1 - points[k][1];
                    double curArea = 0.5 * (abs(x2 * y3 - x3 * y2));
                    maxArea = max(curArea, maxArea);
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end

