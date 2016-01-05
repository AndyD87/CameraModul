########
# Add Source Files
########
file (GLOB SOURCE_FILES
      "CcVideo/src/*.c"
      "CcVideo/src/*.cpp"
      "CcImage/src/*.c"
      "CcImage/src/*.cpp")


########
# Add Source Files
########
file (GLOB HEADER_FILES
      "CcVideo/*.h"
      "CcImage/*.h")


include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
                     
add_library(CcMedia STATIC ${SOURCE_FILES} ${HEADER_FILES} )

link_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../lib )

set_property( TARGET CcMedia PROPERTY FOLDER "CcLib")

target_link_libraries ( CcMedia LINK_PUBLIC
                              CcKernel
                              CcCore )

target_include_directories( CcMedia PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
