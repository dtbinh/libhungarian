add_executable(csvtest test.c)
add_executable(gencsv gencsv.c)

add_library(readcsv readcsv.c)

target_link_libraries(csvtest ${CORELIBS} readcsv)
