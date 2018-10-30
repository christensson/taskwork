#ifndef _TASKWORK_H_
#define _TASKWORK_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct taskwork_settings
{
  int32_t numWorkers;
} taskwork_settings;

bool taskwork_init(const taskwork_settings* const settings_p);
bool taskwork_start(void);
bool taskwork_stop(void);
bool taskwork_cleanup(void);

#ifdef __cplusplus
}
#endif

#endif
