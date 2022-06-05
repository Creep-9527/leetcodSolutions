/*
 * @lc app=leetcode.cn id=587 lang=cpp
 *
 * [587] 安装栅栏
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& x, const vector<int>& y) {
        return x[0] != y[0] ? x[0] < y[0] : x[1] < y[1];
    }
    vector<int> substract(const vector<int>& a, const vector<int>& b) {
        return { b[0] - a[0],b[1] - a[1] };
    }
    int cross(const vector<int>& a, const vector<int>& b) {
        return a[0] * b[1] - a[1] * b[0];
    }
    int getArea(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        return cross(substract(a, b), substract(a, c));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end(), cmp);
        int n = trees.size();
        vector<int>st(n + 10);
        st[0] = 0;
        int top = 0;
        vector<bool>vis(n, false);
        for (int i = 1; i < n; i++) {
            vector<int>c = trees[i];
            while (top >= 1) {
                vector<int>a = trees[st[top - 1]];
                vector<int>b = trees[st[top]];
                if (getArea(a, b, c) <= 0) {
                    //顺时针
                    break;
                }
                else {
                    //逆时针
                    vis[st[top--]] = false;
                }
            }
            st[++top] = i;
            vis[i] = true;
        }
        int m = top;
        for (int i = n - 1; i >= 0; i--) {
            if (vis[i]) {
                continue;
            }
            vector<int>c = trees[i];
            while (top > m ) {
                vector<int>a = trees[st[top - 1]];
                vector<int>b = trees[st[top]];
                if (getArea(a, b, c) <= 0) {
                    //顺时针
                    break;
                }
                else {
                    //逆时针
                    top--;
                }          
            }
            st[++top] = i;
        }
        vector<vector<int>>ans(top);
        for (int i = 0; i < top ; i++) {
            ans[i] = trees[st[i]];
        }
        return ans;
    }
};
// @lc code=end

