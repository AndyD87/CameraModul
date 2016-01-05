########
# Add Source Files
########
file (GLOB SOURCE_FILES
      "*.c"
      "*.cpp")


########
# Add Source Files
########
file (GLOB HEADER_FILES
      "*.h")

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

add_executable( LamoboApp ${SOURCE_FILES} ${HEADER_FILES} )

link_directories( ${LIBRARY_OUTPUT_PATH} )

target_link_libraries ( LamoboApp LINK_PUBLIC
                              CcKernel
                              CcCore
                              CcTarget
                              CcHttp
                              CcFtp )

