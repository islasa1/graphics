//////////////////////////////////////////////////////////////////////////////////////
//                                                                                  //
//     _____    ____ _       ____ _        __ _      __ _  __ _  ______ _   ___ _   //
//    / /| |]  |  __ \\     / ___ \\      / \ \\    |   \\/   |]|  _____|] / ___|]  //
//   / //| |]  | |] \ \\   | |]  \_|]    / //\ \\   | |\ / /| |]| |]___ _ ( ((_ _   //
//  / //_| |]_ | |]  ) ))  | |]  __ _   / _____ \\  | |]\_/ | |]|  _____|] \___ \\  //
// |_____   _|]| |]_/ //   | |]__/  |] / //    \ \\ | |]    | |]| |]___ _   ___) )) //
//       |_|]  |_____//     \_____/|]]/_//      \_\\|_|]    |_|]|_______|] |____//  //
//                                                                                  //
//                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////
///
///
///  \File    : GraphicsContext.cpp
///  \Author  : Anthony Islas
///  \Purpose : It is the core of the graphics
///  \Group   : Core
///
///  \todo    : None
///
///  \License : GNU GPL v3
///
////////////////////////////////////////////////////////////////////////////////////

#include "GraphicsContext.hpp"

// std
#include <iostream>
#include <cstdlib>

// gl
#include <glm/glm.hpp>

// thirdparty
#include "GLFW/glfw3.h"


namespace graphics
{

namespace core
{
  
///**********************************************************************************
///
///  \function GraphicsContext::GraphicsContext
///
///  \brief    ctor
///
///**********************************************************************************
GraphicsContext::GraphicsContext( 
                                  std::string windowName
                                  )
{

  if ( !glfwInit() )
  {
      std::cerr << "Failed to initialize GLFW" << std::endl;
      exit( EXIT_FAILURE );
  }

  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE ); // We just want to run OpenGL 
  
  // Open a window and create its OpenGL context
  
  window_ = glfwCreateWindow( 1024, 768, windowName.c_str(), NULL, NULL);
  if( window_ == NULL )
  {
      std::cerr << "Failed to open GLFW window." << std::endl 
                << "  If you have an Intel GPU, they are not 3.3 compatible." << std::endl 
                << "  Try the 2.1 version of the tutorials." << std::endl;
      glfwTerminate();
      return;
  }

  glfwMakeContextCurrent( window_ ); // Initialize GLFW
  
} // GraphicsContext::GraphicsContext


///**********************************************************************************
///
///  \function GraphicsContext::GraphicsContext
///
///  \brief    dtor
///
///**********************************************************************************
GraphicsContext::~GraphicsContext( )
{

  glfwDestroyWindow( window_ );
  glfwTerminate();

} // GraphicsContext::GraphicsContext


///**********************************************************************************
///
///  \function GraphicsContext::contextCloseRequested
///
///  \brief    Returns if a request to close the window has been made
///
///  \return   bool - true if window close is requested
///
///**********************************************************************************
bool 
GraphicsContext::contextCloseRequested()
{
  
  return glfwWindowShouldClose( window_ );

} // GraphicsContext::contextCloseRequested



} // namespace core

} // namespace graphics