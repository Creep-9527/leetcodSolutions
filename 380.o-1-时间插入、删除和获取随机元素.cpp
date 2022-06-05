/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
#include<vector>
#include<unordered_map>
using namespace std;
 // @lc code=start
class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int, int>indices;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (indices.count(val) > 0) {
            return false;
        }
        int idx = nums.size();
        nums.push_back(val);
        indices.insert({ val,idx });
        return true;
    }
    
    bool remove(int val) {
        if (indices.count(val) == 0) {
            return false;
        }
        int valIdx = indices[val];
        int tail = nums.size() - 1;
        indices[nums[tail]] = valIdx;
        indices.erase(val);
        swap(nums[valIdx], nums[tail]);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int n = nums.size();
        return nums[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

