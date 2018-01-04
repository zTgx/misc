#ifndef _LP_SPIN_LOCK_H
#define _LP_SPIN_LOCK_H

/**
基本上摘自skynet中关于spinlock的实现。
spinlock vs.mutex 区别
看spinlock实现，它会while的去获取锁。so...
自旋锁适用于那些仅需要阻塞很短时间的场景，而互斥锁适用于那些可能会阻塞很长时间的场景。
*/

#define SPIN_INIT(q) spinlock_init(&(q)->lock);
#define SPIN_LOCK(q) spinlock_lock(&(q)->lock);
#define SPIN_UNLOCK(q) spinlock_unlock(&(q)->lock);
#define SPIN_DESTROY(q) spinlock_destroy(&(q)->lock);

class spinlock
{
public:
	int lock;
};

static inline void 
spinlock_init(spinlock *lock)
{
	lock->lock = 0;
}

static inline void
spinlock_lock(spinlock *lock)
{
	while(__sync_lock_test_and_set(&lock->lock, 1))
		;
}

static inline int
spinlock_unlock(spinlock *lock)
{
	__sync_lock_release(&lock->lock);
}

static inline void
spinlock_destroy(spinlock *lock)
{
}









#endif
