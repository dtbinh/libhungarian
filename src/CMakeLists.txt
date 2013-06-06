cmake_minimum_required(VERSION 2.6)
project(LIBHUNGARIAN)

set(CMAKE_BUILD_TYPE Release)

set(MATLAB_MEXFILE_EXT mexa64)

set(CMAKE_CXX_FLAGS "-g -Wall")

  IF((NOT DEFINED MATLAB_ROOT)
      OR ("${MATLAB_ROOT}" STREQUAL ""))
    # get path to the Matlab root directory
    EXECUTE_PROCESS(
      COMMAND which matlab
      COMMAND xargs readlink
      COMMAND xargs dirname
      COMMAND xargs dirname
      COMMAND xargs echo -n
      OUTPUT_VARIABLE MATLAB_ROOT
      )
  ENDIF((NOT DEFINED MATLAB_ROOT)
    OR ("${MATLAB_ROOT}" STREQUAL ""))

set(MATLAB_MEX_LIBS
  libmex.so
  libmx.so
  libmat.so )
foreach(item ${MATLAB_MEX_LIBS} )
  configure_file(${MATLAB_ROOT}/bin/glnxa64/${item} 
${CMAKE_CURRENT_BINARY_DIR}/${item} COPYONLY )
endforeach(item)

include_directories(${LIBHUNGARIAN_SOURCE_DIR}/libhungarian)
include_directories(${LIBHUNGARIAN_SOURCE_DIR}/utils)
link_directories(${LIBHUNGARIAN_BINARY_DIR}/libhungarian)
link_directories(${LIBHUNGARIAN_BINARY_DIR}/utils)

include_directories(${MATLAB_ROOT}/extern/include)
link_directories(${MATLAB_ROOT}/bin/glnxa64)

add_subdirectory(libhungarian)
add_subdirectory(utils)
add_subdirectory(bindings)

