/*
 * @lc app=leetcode.cn id=1117 lang=cpp
 *
 * [1117] H2O 生成
 */
#include<functional>
using namespace std;

// @lc code=start
#include<semaphore.h>
class H2O {
private:
    sem_t semHyd, semOxy;
    int hydCount;

public:
    H2O() {
        sem_init(&semHyd, 0, 2);
        sem_init(&semOxy, 0, 0);
        hydCount = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        sem_wait(&semHyd);
        releaseHydrogen();
        hydCount++;
        if (hydCount >= 2) {
            sem_post(&semOxy);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        sem_wait(&semOxy);
        releaseOxygen();
        hydCount -= 2;
        sem_post(&semHyd);
        sem_post(&semHyd);
    }
};
// @lc code=end

