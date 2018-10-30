#include <taskwork.h>
#include "worker.hpp"
#include "config.hpp"
#include "log.hpp"

#include <stdint.h>
#include <stdbool.h>

namespace taskwork
{
namespace
{
taskwork_settings settings;
Worker workers[cfg::MAX_NUM_WORKERS];
}  // namespace

extern "C" bool taskwork_init(const taskwork_settings* const settings_p)
{
  settings = *settings_p;
  return true;
}

extern "C" bool taskwork_start(void)
{
  for (int32_t i = 0; i < cfg::MAX_NUM_WORKERS; ++i)
  {
    Worker& worker = workers[i];
    worker.start();
  }
  return true;
}

extern "C" bool taskwork_stop(void)
{
  return true;
}

extern "C" bool taskwork_cleanup(void)
{
  return true;
}

} // namespace taskwork
