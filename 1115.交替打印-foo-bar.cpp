/*
 * @lc app=leetcode.cn id=1115 lang=cpp
 *
 * [1115] 交替打印 FooBar
 */
#include<functional>
using namespace std;
 // @lc code=start
#include<semaphore.h>

class FooBar {
private:
    int n;
    sem_t semFoo;
    sem_t semBar;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&semFoo, 0, 1);
        sem_init(&semBar, 0, 0);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&semFoo);
        	// printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem_post(&semBar);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&semBar);
        	// printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&semFoo);
        }
    }
};
// @lc code=end

