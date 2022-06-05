/*
 * @lc app=leetcode.cn id=1116 lang=cpp
 *
 * [1116] 打印零与奇偶数
 */
#include<functional>
using namespace std;
// @lc code=start
#include<semaphore.h>
class ZeroEvenOdd {
private:
    int n;
    sem_t semZero;
    sem_t semEven;
    sem_t semOdd;
    int curIdx = 0;
    int curEven = 2;
    int curOdd = 1;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&semZero, 0, 1);
        sem_init(&semEven, 0, 0);
        sem_init(&semOdd, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            sem_wait(&semZero);
            printNumber(0);
            if ((i % 2) == 0) {
                sem_post(&semEven);
            }
            else {
                sem_post(&semOdd);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&semEven);
            printNumber(i);
            sem_post(&semZero);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&semOdd);
            printNumber(i);
            sem_post(&semZero);
        }
    }
};
// @lc code=end

