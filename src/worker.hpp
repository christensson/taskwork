#ifndef _WORKER_HPP_
#define _WORKER_HPP_

#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

namespace taskwork
{
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
  pthread_t m_thread;
  int32_t m_id;
};
}  // namespace taskwork
#endif
