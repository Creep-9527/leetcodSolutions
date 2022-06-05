/*
 * @lc app=leetcode.cn id=1195 lang=cpp
 *
 * [1195] 交替打印字符串
 */
#include<functional>
#include<iostream>
using namespace std;
// @lc code=start
#include<semaphore.h>

class FizzBuzz {
private:
    int n;
    sem_t semFizz, semBuzz, semFizzBuzz, semNum;

public:
    FizzBuzz(int n) {
        this->n = n;
        sem_init(&semNum, 0, 1);
        sem_init(&semFizz, 0, 0);
        sem_init(&semBuzz, 0, 0);
        sem_init(&semFizzBuzz, 0, 0);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
       
    }
};
// @lc code=end

