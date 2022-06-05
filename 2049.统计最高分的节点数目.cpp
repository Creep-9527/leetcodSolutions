/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    vector<vector<int>>children;
    long long maxScore;
    int ans;
    int n;
    int dfs(int node) {
        long long score = 1;
        int cnt = 0;
        for (auto c : children[node]) {
            int branch = dfs(c);
            score *= branch;
            cnt += branch;
        }
        if (node > 0) {
            score *= n - (cnt + 1);
        }
        if (score > maxScore) {
            ans = 1;
            maxScore = score;
        }
        else if (score == maxScore) {
            ++ans;
        }
        return cnt + 1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        children = vector<vector<int>>(n);
        for (int i = 0; i < n; ++i) {
            int p = parents[i];
            if (p != -1) {
                children[p].push_back(i);
            }
        }
        dfs(0);
        return ans;
    }
};
// @lc code=end

