/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */
#include<vector>
using namespace std;
 // @lc code=start
class NumArray {
public:
    int n;
    vector<int>segemtTree;
    void build(int Node, int s, int e, vector<int>& nums) {
        if (s == e) {
            segemtTree[Node] = nums[s];
            return;
        }
        int m = s + (e - s) / 2;
        build(Node * 2 + 1, s, m, nums);
        build(Node * 2 + 2, m + 1, e, nums);
        segemtTree[Node] = segemtTree[Node * 2 + 1] + segemtTree[Node * 2 + 2];
        return;
    }
    void change(int index, int val,int s,int e,int node) {
        if (s == e) {
            segemtTree[node] = val;
            return;
        }
        int m = s + (e - s) / 2;
        if (index <= m) {
            change(index, val, s, m, node * 2 + 1);
        }
        else {
            change(index, val, m + 1, e, node * 2 + 2);
        }
        segemtTree[node] = segemtTree[node * 2 + 1] + segemtTree[node * 2 + 2];
        return;
    }
    int range(int node, int s, int e, int l, int r) {
        if (l == s && r == e) {
            return segemtTree[node];
        }
        int m = s + (e - s) / 2;
        if (r <= m) {
            return range(node * 2 + 1, s, m, l, r);
        }
        else if (l > m) {
            return range(node * 2 + 2, m + 1, e, l, r);
        }
        else {
            return range(node * 2 + 1, s, m, l, m) + range(node * 2 + 2, m + 1, e, m + 1, r);
        }
    }
    NumArray(vector<int>& nums) :n(nums.size()), segemtTree(nums.size() * 4) {
        build(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        change(index, val, 0, n - 1, 0);
    }
    
    int sumRange(int left, int right) {
        return range(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

