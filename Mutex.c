//
// Created by wonjin-choi on 11/2/23.
//
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdatomic.h>


// 스핀락과 뮤텍스 비교 예제
// 터미널에 ps -M $(top -l 1 | grep Mutex | awk '{print $1}') 로 프로세스의 스레드 상태 확인해보기

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int is_locked;
} mutex_t;

void mutex_init(mutex_t* mutex) {
    pthread_mutex_init(&mutex->lock, NULL);
    pthread_cond_init(&mutex->cond, NULL);
    mutex->is_locked = 0;
}

atomic_flag lock = ATOMIC_FLAG_INIT;

void spinlock_lock(atomic_flag* lock) {
    while (atomic_flag_test_and_set(lock));
}

void spinlock_unlock(atomic_flag* lock) {
    atomic_flag_clear(lock);
}


mutex_t mutex;
int shared_resource = 0;

void* thread_function(void* arg) {
//    pthread_mutex_lock(&mutex);
    spinlock_lock(&lock);

    shared_resource++;
    printf("Thread %d: %d\n", *(int*)arg, shared_resource);
    sleep(100);

    spinlock_unlock(&lock);
//    pthread_mutex_unlock(&mutex);
    return NULL;
}




int main() {
    pthread_t thread1, thread2, thread3, thread4, thread5, thread6;

//    mutex_init(&mutex);

    int id1 = 1, id2 = 2, id3 = 3, id4 = 4, id5 = 5, id6 = 6;
    pthread_create(&thread1, NULL, thread_function, &id1);
    pthread_create(&thread2, NULL, thread_function, &id2);
    pthread_create(&thread3, NULL, thread_function, &id3);
    pthread_create(&thread4, NULL, thread_function, &id4);
    pthread_create(&thread5, NULL, thread_function, &id5);
    pthread_create(&thread6, NULL, thread_function, &id6);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);

    return 0;
}
