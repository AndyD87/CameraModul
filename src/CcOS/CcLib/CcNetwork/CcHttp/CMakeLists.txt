########
# Add Source Files
########
file (GLOB SOURCE_FILES
      "src/*.c"
      "src/*.cpp")


########
# Add Source Files
########
file (GLOB HEADER_FILES
      "*.h")


include_directories( ${CMAKE_CURRENT_SOURCE_DIR}
                     ${CMAKE_CURRENT_SOURCE_DIR}/../../CcKernel
                     ${CMAKE_CURRENT_SOURCE_DIR}/../../CcCore
                     ${CMAKE_CURRENT_SOURCE_DIR}/../../CcGui
                     ${CMAKE_CURRENT_SOURCE_DIR}/../../CcTarget
                     ${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdParty )

add_library( CcHttp STATIC ${SOURCE_FILES} ${HEADER_FILES} )

link_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../lib )

set_property( TARGET CcHttp PROPERTY FOLDER "CcLib/CcNetwork")

target_link_libraries ( CcHttp LINK_PUBLIC
                              CcKernel
                              CcCore )

target_include_directories( CcHttp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})