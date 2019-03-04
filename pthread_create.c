//gcc pthread3.c -o thread -lpthread

#include <pthread.h>
#include <stdio.h>

/* For safe condition variable usage, must use a boolean predicate and   */
/* a mutex with the condition.                                           */
int                 conditionMet = 0;
pthread_cond_t      cond  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;

#define NTHREADS    2

/*
线程之间共享一个用户空间，我们这样传递的是i的地址过去，然后在运行线程主函数的时候依据地址找i的值,
i的值发生改变了。
*/
void *threadfunc(void *parm)
{
    int i = (int)parm;
    printf("这里是线程 %d\n", i);
    printf("我是线程，我的ID = %lu\n", pthread_self());

    int           rc;
    rc = pthread_mutex_lock(&mutex);
    while (!conditionMet) {
        printf("等待，我是线程，我的ID = %lu\n", pthread_self());
        rc = pthread_cond_wait(&cond, &mutex);
        printf("处理，我是线程，我的ID = %lu\n", pthread_self());

    }

    rc = pthread_mutex_unlock(&mutex);

    return NULL;
}
int main(int argc, char **argv)
{
    int                   rc=0;
    int                   i;
    pthread_t             threadid[NTHREADS];

    printf("Enter Testcase - %s\n", argv[0]);

    for(i=0; i<NTHREADS; ++i) {
        printf("---%d---\n", i);
        rc = pthread_create(&threadid[i], NULL, threadfunc, (void*)i);
    }

    sleep(5);  /* Sleep is not a very robust way to serialize threads */
    rc = pthread_mutex_lock(&mutex);
    //checkResults("pthread_mutex_lock()\n", rc);

    /* The condition has occured. Set the flag and wake up any waiting threads */
    conditionMet = 1;
    printf("Wake up all waiting threads...\n");
    rc = pthread_cond_broadcast(&cond);
    //checkResults("pthread_cond_broadcast()\n", rc);

    rc = pthread_mutex_unlock(&mutex);
    //checkResults("pthread_mutex_unlock()\n", rc);

    printf("Wait for threads and cleanup\n");
    for (i=0; i<NTHREADS; ++i) {
        rc = pthread_join(threadid[i], NULL);
        //checkResults("pthread_join()\n", rc);
    }
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);

    printf("Main completed\n");
    return 0;
}

