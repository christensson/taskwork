cmake_minimum_required (VERSION 2.8.11)
project(taskwork)
set(TASKWORK_SRCS
  src/taskwork.cpp
  src/worker.cpp
)

add_library(taskwork ${TASKWORK_SRCS})
target_include_directories(taskwork PUBLIC include)
target_compile_definitions(taskwork PRIVATE ENABLE_LOGGING)

add_executable(demo test/demo_main.cpp)
target_link_libraries(demo taskwork pthread)
