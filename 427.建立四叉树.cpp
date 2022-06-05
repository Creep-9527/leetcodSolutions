/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */
#include<vector>
using namespace std;
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
 // @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* constructFour(vector<vector<int>>& grid, int top, int bottom, int left, int right) {
        if (top == bottom) {
            Node* node = new Node(grid[top][left], true);
            return node;
        }
        bool allSame = true;
        int last = grid[top][left];
        for (int i = top; i <= bottom; i++) {
            for (int j = left; j <= right; j++) {
                if (grid[i][j] != last) {
                    allSame = false;
                    break;
                }
                last = grid[i][j];
            }
            if (!allSame) {
                break;
            }
        }
        if (allSame) {
            Node* node = new Node(grid[top][left], true);
            return node;
        }
        else {
            Node* topLeft = constructFour(grid, top, (top + bottom) / 2, left, (left + right) / 2);
            Node* topRight = constructFour(grid, top, (top + bottom) / 2, (left + right) / 2 + 1, right);
            Node* bottomLeft = constructFour(grid, (top + bottom) / 2 + 1, bottom, left, (left + right) / 2);
            Node* bottomeRight = constructFour(grid, (top + bottom) / 2 + 1, bottom, (left + right) / 2 + 1, right);
            Node* node = new Node(true, false, topLeft, topRight, bottomLeft, bottomeRight);
            return node;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructFour(grid, 0, n - 1, 0, n - 1);
    }
};
// @lc code=end

