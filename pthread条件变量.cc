pthread_mutex_t mutex;  ///< 互斥锁
pthread_cond_t  cond;   ///< 条件变量
bool test_cond = false;
/// TODO 初始化mutex和cond
 
/// thread 1:
pthread_mutex_lock(&mutex);            ///< 1
while (!test_cond)
{
    pthread_cond_wait(&cond, &mutex);  ///< 2,3
}
pthread_mutex_unlock(&mutex);          ///< 4
RunThread1Func();
 
/// thread 2:
pthread_mutex_lock(&mutex);            ///< 5
test_cond = true;
pthread_cond_signal(&cond);
pthread_mutex_unlock(&mutex);          ///< 6
 
/// TODO 销毁mutex和cond
