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
##  Purpose : Directions for CMake to auto-generate Makefiles
##  Group   : Graphics
##
##  License : GNU GPL v3
##
####################################################################################

#
# Dependencies
#
cmake_minimum_required ( VERSION 3.5.0 )
project ( KomorebiGraphics )

set ( CMAKE_BUILD_TYPE debug )


####################################################################################
#
# Options
#
####################################################################################
option( UNIT_TEST         "Enable Google Test Framework"                    OFF )
option( BUILD_THIRDPARTY  "Perform steps to checkout and build thirdparty"  OFF )
option( XX_LIB            "Set to compile XX LIB"                           OFF )

set   ( THIRDPARTY 
        "${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty" 
        CACHE STRING 
        "Thirdparty directory" )

set   ( COMPONENTS 
        "${CMAKE_CURRENT_SOURCE_DIR}/../components" 
        CACHE STRING 
        "Components directory" 
        )


#
# Get our modules after options
#
list( APPEND 
      CMAKE_MODULE_PATH
      ${COMPONENTS}/cmake 
      )

set( GLFW_GRAPHICS ON )

include( ExternalProject )
include( GoogleTestSetup )
include( GLFWSetup       )
include( OptionPrinter   )
include( VersionExtract  )

####################################################################################
#
# Project setup
#
####################################################################################
version_extract_str( ${CMAKE_CURRENT_SOURCE_DIR}/versions.txt PROJECT_VERSION )

message ( "Configuring " ${PROJECT_NAME} )
detailed_print( "PROJECT VERSION" CLR_MAGENTA ${PROJECT_VERSION} CLR_CYAN 14 LEFT )

#
# Flags
#
set( CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra" )

#
# Debug flags
#
if ( ${CMAKE_BUILD_TYPE} MATCHES debug )

  message( STATUS "${CLR_BOLDGREEN}Setting debug flags${CLR_RESET}" )

  add_definitions( -DDEBUG )

endif()



#
# Install locations
#
set( RUNTIME_INSTALL ${PROJECT_SOURCE_DIR}/bin )
set( LIBRARY_INSTALL ${PROJECT_SOURCE_DIR}/lib )


#
# Declare target
#
set        (   TARGET ${PROJECT_NAME}  )
add_library( ${TARGET} SHARED ""       )

target_include_directories ( 
                            ${TARGET}
                            PUBLIC
                              ${PROJECT_BINARY_DIR}
                              )


####################################################################################
#
# Configuration stuff
#
####################################################################################
configure_file ( ${PROJECT_SOURCE_DIR}/src/common/config.hpp.in
                 ${PROJECT_BINARY_DIR}/config.hpp 
                 @ONLY 
                )


####################################################################################
#
# Regression test variable
#
####################################################################################
set ( TEST_SOURCES
      "" 
    )
set ( TEST_INCLUDES
      ""
    )
set ( TEST_RESOURCES
      ${CMAKE_BINARY_DIR}/gtest_resources/
    )


####################################################################################
#
# Necessary packages
#
####################################################################################
find_package ( Threads )
find_package ( OpenGL  )

#
# Depend on thirdparty target ( added by setup module )
#
add_dependencies( ${TARGET} glfw )

# Additional config for glfw / OpenGL extension support
target_sources( ${TARGET}
                PUBLIC
                  ${GLFW_DEPS}
              )

find_library( COMPONENTS_TIMING KomorebiComponentsTiming ${COMPONENTS}/lib )
find_library( COMPONENTS_STRING KomorebiComponentsString ${COMPONENTS}/lib )

set( COMPONENTS_LIBRARIES 
     ${COMPONENTS_TIMING}
     ${COMPONENTS_STRING}
     )

target_include_directories ( 
                            ${TARGET}
                            PUBLIC
                              ${OPEN_GL_INCLUDE_DIRS} 
                              ${COMPONENTS}
                              ${GLFW_ROOT}/include
                              ${GLFW_ROOT}/deps
                              )


####################################################################################
#
# Source directories
#
####################################################################################
message ( "Configuring ${PROJECT_NAME}")
add_subdirectory ( src )



####################################################################################
#
# Regression test
#
####################################################################################
if ( UNIT_TEST )

  message ( "Current Tests: " ) 
  foreach (test_file ${TEST_SOURCES} )
    message ( '${test_file}' )
  endforeach ()

  message ( "Resources located in : '${TEST_RESOURCES}'" )

  # Builds all tests
  create_gtest( 
                TARGET 
                  ${TARGET}Tests

                INSTALL
                  ${RUNTIME_INSTALL}

                SOURCES
                  ${TEST_SOURCES}

                INSTALL_RPATH
                  ${LIBRARY_INSTALL}

                LIBS
                  ${TARGET}

                INCLUDES
                  ${TEST_INCLUDES}

                RESOURCES
                  ${RESOURCE_FILES}

                # PRINT_INC_DIR # Including this makes it true
                )

endif()


####################################################################################
#
# Link Libraries
#
####################################################################################
target_link_libraries( ${TARGET}
                       ${OPENGL_LIBRARIES}
                       ${COMPONENTS_LIBRARIES}
                       ${GLFW_LIBS}
                       )


####################################################################################
#
# Install rules
#
####################################################################################
#
# RPATH
#
set( 
    TARGET_RPATH
    ${COMPONENTS}/lib
    ${GLFW_ROOT}/lib
    )

set_target_properties( ${TARGET}
                       PROPERTIES
                         INSTALL_RPATH 
                         "${TARGET_RPATH}"
                         )


install( TARGETS ${TARGET} 
         RUNTIME DESTINATION ${RUNTIME_INSTALL}
         LIBRARY DESTINATION ${LIBRARY_INSTALL}
         )
