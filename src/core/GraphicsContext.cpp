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
#include <iomanip>
#include <cstdlib>
#include <stdexcept>

// gl
#include <glm/glm.hpp>

// thirdparty
// Gets OpenGL 3.1+ extensions
#include "glad/glad.h"
#define GLFW_INCLUDE_GLEXT 
#include "GLFW/glfw3.h"

// must be done after glfw / glad bc it's dumb
#include <GL/glu.h>

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
                                  std::string windowName,
                                  size_t      width,
                                  size_t      height
                                  )
: windowName_( windowName  )
, width_     ( width       )
, height_    ( height      )
{

  if ( !glfwInit() )
  {
      std::cerr << "Failed to initialize GLFW" << std::endl;
      throw std::runtime_error( "" );
  }

  // We want OpenGL 3.3
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 ); 
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 5 );

  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE ); // We just want to run OpenGL 
  
  // Open a window and create its OpenGL context
  
  window_ = glfwCreateWindow( width_, height_, windowName_.c_str(), NULL, NULL );
  
  if( window_ == NULL )
  {
      std::cerr << "Failed to open GLFW window." << std::endl 
                << "  If you have an Intel GPU, they are not 3.3 compatible." << std::endl 
                << "  Try the 2.1 version of the tutorials." << std::endl;
      glfwTerminate();
      return;
  }

  glfwMakeContextCurrent( window_ ); // Initialize GLFW

  // Load extensions - we need a valid context before
  // we can do this
  if ( !gladLoadGLLoader( ( GLADloadproc ) glfwGetProcAddress ) )
  {
    std::cerr << "Failed to initialize GLAD GL Loader!" << std::endl;
    throw std::runtime_error( "" );
  }

  if ( !glfwExtensionSupported( "GL_ARB_debug_output" ) )
  {
    // The extension is not supported by the current context
    std::cerr << "Unsupported OpenGL extensions" << std::endl;
    throw std::runtime_error( "" );

  }
  
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



///**********************************************************************************
///
///  \function GraphicsContext::makeWindowCurrent
///
///  \brief    I think this is maybe how we should swap buffers (?)
///
///  \return   void - just updates the window
///
///**********************************************************************************
void 
GraphicsContext::makeWindowCurrent( )
{

  glfwSwapBuffers( window_ );

} // GraphicsContext::makeWindowCurrent



///**********************************************************************************
///
///  \function GraphicsContext::checkError
///
///  \brief    Checks graphics errors
///
///  \return   void - throws on error
///
///**********************************************************************************
void 
GraphicsContext::checkError( 
                            const char *file, 
                            uint32_t    line 
                            )
{
  
  GLenum err = glGetError();

  if ( err != GL_NO_ERROR )
  {

    std::cerr << "OpengGL error at " << file << ":" << line << std::endl;
    std::cerr << "err 0x" << std::hex << err << " : " 
              << gluErrorString( err ) << std::endl;

    throw std::runtime_error( "" );

  }

} // GraphicsContext::checkError


///**********************************************************************************
///
///  \function GraphicsContext::genVertexArray
///
///  \brief    Brief Description
///
///  \return   void - 
///
///**********************************************************************************
void 
GraphicsContext::genVertexArray( 
                                size_t    n, 
                                uint32_t *pVao 
                                )
{
  
  glGenVertexArrays( n, static_cast< GLuint * >( pVao ) );

} // GraphicsContext::genVertexArray



///**********************************************************************************
///
///  \function GraphicsContext::bindVertexArray
///
///  \brief    Brief Description
///
///  \return   void - 
///
///**********************************************************************************
void
GraphicsContext::bindVertexArray( 
                                  uint32_t vao 
                                  )
{
  
  glBindVertexArray( static_cast< GLuint >( vao ) );

} // GraphicsContext::bindVertexArray





void 
GraphicsContext::enableVertexArrayAttrib ( 
                                          uint32_t index 
                                          )
{
  
  glEnableVertexAttribArray( index );

}

// void 
// GraphicsContext::enableVertexArrayAttrib ( 
//                                           uint32_t vao, 
//                                           uint32_t index 
//                                           )
// {
  
//   glEnableVertexArrayAttrib( vao, index );

// }

void 
GraphicsContext::disableVertexArrayAttrib( 
                                          uint32_t index 
                                          )
{
  
  glDisableVertexAttribArray( index );

}

// void 
// GraphicsContext::disableVertexArrayAttrib( 
//                                           uint32_t vao, 
//                                           uint32_t index 
//                                           )
// {
  
//   glDisableVertexArrayAttrib( vao, index );

// }


///**********************************************************************************
///
///  \function GraphicsContext::genVertexBuffer
///
///  \brief    Brief Description
///
///  \return   void - 
///
///**********************************************************************************
void 
GraphicsContext::genVertexBuffer( 
                                  size_t    n, 
                                  uint32_t *pVbo 
                                  )
{
  
  glGenBuffers( n, static_cast< GLuint * >( pVbo ) );

} // GraphicsContext::genVertexBuffer



///**********************************************************************************
///
///  \function GraphicsContext::bindVertexBuffer
///
///  \brief    Brief Description
///
///  \return   void - 
///
///**********************************************************************************
void
GraphicsContext::bindBuffer( 
                            int32_t  target,
                            uint32_t buffer 
                            )
{
  
  glBindBuffer( static_cast< GLenum >( target ), static_cast< GLuint >( buffer ) );

} // GraphicsContext::bindVertexBuffer


///**********************************************************************************
///
///  \function GraphicsContext::bufferData
///
///  \brief    Brief Description
///
///  \return   void - 
///
///**********************************************************************************
void 
GraphicsContext::bufferData(
                            int32_t       target,
                            size_t        size,
                            void         *data,
                            int32_t       usage
                            )
{
  
  glBufferData( 
                static_cast< GLenum >( target ),
                static_cast< GLsizeiptr >( size ),
                static_cast< const GLvoid * >( data ),
                static_cast< GLenum >( usage )
              );

} // GraphicsContext::bufferData


///**********************************************************************************
///
///  \function GraphicsContext::drawArrays
///
///  \brief    render primitives from array data
///
///  \return   void - 
///
///**********************************************************************************
void 
GraphicsContext::drawArrays(
                            int32_t mode,
                            int32_t first,
                            size_t  count 
                            )
{
  
  glDrawArrays( 
                static_cast< GLenum  >( mode ),
                static_cast< GLint   >( first ),
                static_cast< GLsizei >( count ) 
              );

} // GraphicsContext::drawArrays


// ///**********************************************************************************
// ///
// ///  \function GraphicsContext::bufferData
// ///
// ///  \brief    Brief Description
// ///
// ///  \return   void - 
// ///
// ///**********************************************************************************
// void 
// GraphicsContext::bufferData(
//                             uint32_t      buffer,
//                             size_t        size,
//                             void         *data,
//                             int32_t       usage
//                             )
// {
  
//   glNamedBufferData( 
//                     static_cast< GLuint >( buffer ),
//                     static_cast< GLsizeiptr >( size ),
//                     static_cast< const GLvoid * >( data ),
//                     static_cast< GLenum >( usage )
//                     );

// } // GraphicsContext::bufferData


///**********************************************************************************
///
///  \function GraphicsContext::bufferSubData
///
///  \brief    Brief Description
///
///  \return   void - 
///
///**********************************************************************************
void 
GraphicsContext::bufferSubData(
                                int32_t       target,
                                size_t        offset,
                                size_t        size,
                                void         *data
                                )
{
  
  glBufferSubData( 
                  static_cast< GLenum >( target ),
                  static_cast< GLintptr >( offset ),
                  static_cast< GLsizeiptr >( size ),
                  static_cast< const GLvoid * >( data )
                  );

} // GraphicsContext::bufferSubData


// ///**********************************************************************************
// ///
// ///  \function GraphicsContext::bufferSubData
// ///
// ///  \brief    Brief Description
// ///
// ///  \return   void - 
// ///
// ///**********************************************************************************
// void 
// GraphicsContext::bufferSubData(
//                                 uint32_t      buffer,
//                                 size_t        offset
//                                 size_t        size,
//                                 void         *data
//                                 )
// {
  
//   glNamedBufferData( 
//                     static_cast< GLuint >( buffer ),
//                     static_cast< Glintptr >( offset ),
//                     static_cast< GLsizeiptr >( size ),
//                     static_cast< const GLvoid * >( data )
//                     );

// } // GraphicsContext::bufferSubData


} // namespace core

} // namespace graphics