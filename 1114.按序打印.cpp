/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

#include<functional>
using namespace std;
// @lc code=start
#include<semaphore.h>
class Foo {
public:
    sem_t semSec;
    sem_t semThi;
    Foo() {
        sem_init(&semSec, 0, 0);
        sem_init(&semThi, 0, 0);
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&semSec);
    }

    void second(function<void()> printSecond) {
        sem_wait(&semSec);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&semThi);
    }

    void third(function<void()> printThird) {
        sem_wait(&semThi);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
    
};
// @lc code=end

