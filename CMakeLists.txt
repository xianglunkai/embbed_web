cmake_minimum_required(VERSION 3.5)

project(webapp VERSION 1.0)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

if (NOT DEFINED CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Release CACHE STRING "Build type")
endif ()

# set build attributions
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-w)
    add_compile_options(-std=c++11)
    add_compile_options(-Wall -O2 -c -fpermissive -g) #g
    add_compile_options(-D _GLIBCXX_USE_NANOSLEEP)
    message(STATUS "optional:-std=c++11")
endif(CMAKE_COMPILER_IS_GNUCXX)


include_directories(
  ./webapp
  ./lib/glog/include
  ./lib/uorb/include
  ./msg/
  ./msg/uorb/
  ./msg/uorb/topics
)

link_directories(
	./lib/glog/lib
  ./lib/uorb/lib
)


link_libraries(
  glog
  uorb
)

# generate uORB messages
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/msg)

# build executable files
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/webapp MAIN_SRC)
add_executable(${PROJECT_NAME} ${MAIN_SRC})

# target link uorb_msg
target_link_libraries(${PROJECT_NAME} PRIVATE rt pthread uorb_msgs)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()

add_custom_target(upload
    COMMAND rsync -arh --progress
          ${CMAKE_CURRENT_SOURCE_DIR}/bin/* # source
          root@192.178.111.46:/mnt/mmc/algorithms/ # destination
    COMMENT "uploading algorithm"
    USES_TERMINAL
)
