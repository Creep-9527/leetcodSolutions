/*
 * @lc app=leetcode.cn id=2043 lang=cpp
 *
 * [2043] 简易银行系统
 */
#include<vector>
using namespace std;

 // @lc code=start
class Bank {
public:
    vector<long long>balances;
    int n;
    Bank(vector<long long>& balance) {
        balances = balance;
        n = balances.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1<1 || account1>n) {
            return false;
        }
        if (account2<1 || account2>n) {
            return false;
        }
        if (balances[account1 - 1] < money) {
            return false;
        }
        balances[account1 - 1] -= money;
        balances[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account<1 || account>n) {
            return false;
        }
        balances[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {    
        if (account<1 || account>n || balances[account - 1] < money) {
            return false;
        }
        balances[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end

