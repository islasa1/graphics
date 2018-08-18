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

  // glfwWindowHint( GLFW_SAMPLES, 4 ); // 4x antialiasing
  // glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 ); // We want OpenGL 3.3
  // glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
  glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE ); // To make MacOS happy; should not be needed
  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE ); // We don't want the old OpenGL 
  
  // Open a window and create its OpenGL context
  GLFWwindow* window; 
  window = glfwCreateWindow( 1024, 768, windowName.c_str(), NULL, NULL);
  if( window == NULL )
  {
      std::cerr << "Failed to open GLFW window." << std::endl 
                << "  If you have an Intel GPU, they are not 3.3 compatible." << std::endl 
                << "  Try the 2.1 version of the tutorials." << std::endl;
      glfwTerminate();
      return;
  }

  glfwMakeContextCurrent( window ); // Initialize GLEW
  
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
} // GraphicsContext::GraphicsContext


} // namespace core

} // namespace graphics