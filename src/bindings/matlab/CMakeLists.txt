add_library(m_hungarian SHARED hungarian_matlab.c ${CMAKE_SOURCE_DIR}/mexFunction.def)
#add_library(hungarian ${LIBHUNGARIAN_BINARY_DIR}/libhungarian/hungarian.c)
target_link_libraries(m_hungarian ${MATLAB_MEX_LIBS} hungarian)

set_target_properties(m_hungarian PROPERTIES
    PREFIX ""
    SUFFIX  ".${MATLAB_MEXFILE_EXT}"
)
