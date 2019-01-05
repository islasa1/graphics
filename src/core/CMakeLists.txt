######################################################################################
##                                                                                  ##
##     _____    ____ _       ____ _        __ _      __ _  __ _  ______ _   ___ _   ##
##    / /| |]  |  __ \\     / ___ \\      / \ \\    |   \\/   |]|  _____|] / ___|]  ##
##   / //| |]  | |] \ \\   | |]  \_|]    / //\ \\   | |\ / /| |]| |]___ _ ( ((_ _   ##
##  / //_| |]_ | |]  ) ))  | |]  __ _   / _____ \\  | |]\_/ | |]|  _____|] \___ \\  ##
## |_____   _|]| |]_/ //   | |]__/  |] / //    \ \\ | |]    | |]| |]___ _   ___) )) ##
##       |_|]  |_____//     \_____/|]]/_//      \_\\|_|]    |_|]|_______|] |____//  ##
##                                                                                  ##
##                                                                                  ##
######################################################################################
##
##
##  File    : CMakeLists.txt
##  Author  : Anthony Islas
##  Purpose : Core graphis implementations
##  Group   : Core
##
##  TODO    : None
##
##  License : GNU GPL v3
##
####################################################################################


#
# Includes
#
target_include_directories( ${TARGET} 
                            PUBLIC
                              ${CMAKE_CURRENT_SOURCE_DIR}
                              ${PROJECT_SOURCE_DIR}
                            )

#
# Sources
#
target_sources( ${TARGET}
                PRIVATE 
                  ${CMAKE_CURRENT_SOURCE_DIR}/GraphicsContext.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/Shader.cpp
              )


####################################################################################
#
# UNIT TESTS
#
####################################################################################
if ( UNIT_TEST )

  if ( NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/gtest )

    message( STATUS "No tests to build for ${TARGET}" )

    return()

  else()

  add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/gtest )  
  set (   
        TEST_SOURCES  
        ${TEST_SOURCES}  
        PARENT_SCOPE 
        )

  set ( 
        TEST_INCLUDES 
        ${TEST_INCLUDES} 
        PARENT_SCOPE 
        )

  set ( RESOURCE_FILES
        ${RESOURCE_FILES}
        PARENT_SCOPE
        )

  endif()

endif()
