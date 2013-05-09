add_executable(hungarian_test hungarian_test.c)

add_library(hungarian SHARED hungarian.c)

target_link_libraries(hungarian_test ${CORELIBS} libhungarian readcsv)
