#ifndef _WORKER_HPP_
#define _WORKER_HPP_

#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

namespace taskwork
{
enum WorkerState
{
  WORKER_CREATED = 0,
  WORKER_RUNNING = 1,
  WORKER_EXITED = 2
};

class Worker
{
public:
  Worker();
  ~Worker();
  bool start();
  bool kill();
  int32_t getId() const
  {
    return m_id;
  }
private:
  static void* threadMain(void*);
  pthread_t m_thread;
  int32_t m_id;
  WorkerState m_state;
};
}  // namespace taskwork
#endif
