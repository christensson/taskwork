#include <taskwork.h>
#include <cstdio>

int main()
{
  printf("Demo started\n");
  taskwork_settings settings = {};
  settings.numWorkers = 8;
  taskwork_init(&settings);
  taskwork_start();
  taskwork_stop();
  taskwork_cleanup();
  printf("Demo finished\n");
}
