add_library(bar
  SHARED
  bar.cpp)

target_include_directories(bar PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS bar LIBRARY DESTINATION lib)
