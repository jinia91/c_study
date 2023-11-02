//
// Created by wonjin-choi on 11/2/23.
//

#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>
#include <unistd.h>

atomic_flag lock = ATOMIC_FLAG_INIT;

void spinlock_lock(atomic_flag* lock) {
    while (atomic_flag_test_and_set(lock));
}

void spinlock_unlock(atomic_flag* lock) {
    atomic_flag_clear(lock);
}

void* worker(void* arg) {
    for (int i = 0; i < 5; ++i) {
        spinlock_lock(&lock);
        printf("Thread %d, %d working...\n", (int)(size_t)arg, i);
        spinlock_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    const int num_threads = 5;
    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; ++i) {
        printf("thread init %d\n", i);
        pthread_create(&threads[i], NULL, worker, (void*)(size_t)i);
    }

    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
