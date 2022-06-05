/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 */
#include<random>
#include<ctime>
using namespace std;
 // @lc code=start
class Solution {
private:
    double x, y, r;
public:
    Solution(double radius, double x_center, double y_center):x(x_center),y(y_center),r(radius) {
        
    }
    
    vector<double> randPoint() {
        while (true) {
            double dx = 2 * (double)rand() / RAND_MAX - 1;
            double dy = 2 * (double)rand() / RAND_MAX - 1;
            if (dx * dx + dy * dy <= 1) {
                return { dx * r + x,dy * r + y};
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

