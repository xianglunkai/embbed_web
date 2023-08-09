add_custom_target (tests)

set (test_name main)

include_directories(
  ../lib/glog/include
)


link_directories(
	../lib/glog/lib
)


link_libraries(
	rt
	pthread
  glog
)


add_executable (${test_name} ${test_name}.cc)

target_link_libraries(${test_name} glog)


