/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return { 0 };
        }
        vector<vector<int>>graph(n);
        vector<int>degree(n);
        queue<int>q;
        vector<int>ans;
        for (auto edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        int remain = n;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (remain > 2) {
            int sz = q.size();
            remain -= sz;
            for (int i = 0; i < sz; i++) {
                int cur = q.front();
                q.pop();
                for (auto node : graph[cur]) {
                    if (--degree[node] == 1) {
                        q.emplace(node);
                    }
                }
            }
        }
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

