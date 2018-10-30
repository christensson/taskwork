#include "worker.hpp"
#include "config.hpp"
#include "log.hpp"

#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

#define WORKER_ID_FMT "Worker[%d]"

namespace taskwork
{
namespace
{
int32_t nextId = 0;

void* workerMain(void* arg)
{
  Worker* const worker = static_cast<Worker*>(arg);
  LOG_INFO(WORKER_ID_FMT ": Begin\n", worker->getId());
  LOG_INFO(WORKER_ID_FMT ": End\n", worker->getId());
}

}  // namespace

Worker::Worker()
  : m_thread(0), m_id(nextId)
{
  ++nextId;
}

Worker::~Worker()
{
}

bool Worker::start()
{
  pthread_attr_t attr;
  const int attrInitStatus = pthread_attr_init(&attr);  
  if (attrInitStatus != 0)
  {
    LOG_ERROR(WORKER_ID_FMT ": Failed to start, pthread_attr_init failed with status %d\n",
        this->m_id, attrInitStatus);
    return false;
  }

  const int createStatus = pthread_create(&this->m_thread, &attr, &workerMain, static_cast<void*>(this));
  if (createStatus != 0)
  {
    LOG_ERROR(WORKER_ID_FMT ": Failed to start, pthread_create failed with status %d\n",
        this->m_id, createStatus);

  }
}

}  // namespace taskwork
