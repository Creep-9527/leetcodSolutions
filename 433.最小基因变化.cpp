/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */
#include<string>
#include<vector>
#include<queue>
using namespace std;
 // @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size();
        int m = start.size();
        vector<vector<int>>adj(n);
        int endIdx = -1;
        for (int i = 0; i < n; i++) {
            if (bank[i] == end) {
                endIdx = i;
            }
            for (int j = i + 1; j < n; j++) {
                int dif = 0;
                for (int k = 0; k < m; k++) {
                    if (bank[i][k] != bank[j][k]) {
                        dif++;
                    }
                    if (dif > 1) {
                        break;
                    }
                }
                if (dif == 1) {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }
        if (endIdx == -1) {
            return -1;
        }

        queue<int>q;
        vector<bool>vis(n, false);
        for (int i = 0; i < n; i++) {
            int dif = 0;
            for (int j = 0; j < m; j++) {
                if (bank[i][j] != start[j]) {
                    dif++;
                }
                if (dif > 1) {
                    break;
                }
            }
            if (dif == 1) {
                q.emplace(i);
                vis[i] = true;
            }
        }

        int step = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                if (bank[q.front()] == end) {
                    return step;
                }
                for (auto next : adj[q.front()]) {
                    if (vis[next]) {
                        continue;
                    }
                    q.push(next);
                    vis[next] = true;
                }
                q.pop();
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

