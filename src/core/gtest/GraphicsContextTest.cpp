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
///  \File    : GraphicsContextTest.cpp
///  \Author  : Anthony Islas
///  \Purpose : Test for GraphicsContext
///  \Group   : Gtest
///
///  \todo    : None
///
///  \License : GNU GPL v3
///
////////////////////////////////////////////////////////////////////////////////////

#include "gtest/gtest.h"

#include "core/GraphicsContext.hpp"

// 
// Direct access to things we test

// gl
#include <glm/glm.hpp>

// thirdparty
#include "glad/glad.h"
#define GLFW_INCLUDE_GLEXT 
#include "GLFW/glfw3.h"

namespace gtest
{
  

class TEST_CASE : public ::testing::Test
{

public:
  TEST_CASE() {}
  ~TEST_CASE(){}

  virtual 
  void 
  SetUp()
  {


  }

  virtual 
  void
  TearDown()
  {

    if ( pContext_ )
    {
      delete pContext_;
    }

  }

  void
  SetupContext( std::string windowName = "" )
  {
    pContext_ = new graphics::core::GraphicsContext( windowName );
  }

// I thought tests were part of the class, apparently not
// private:

  graphics::core::GraphicsContext *pContext_;
  
};



TEST_F( TEST_CASE, OpenWindowNoTitle )
{

  SetupContext( );

}



TEST_F( TEST_CASE, OpenWindowTitle )
{

  SetupContext( "FooBar" );

}



TEST_F( TEST_CASE, DisplayOnWindowTriangle )
{
  // Based on :
  // http://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
  SetupContext( "Demo Triangle" );

  GLuint vao;

  graphics::core::GraphicsContext::genVertexArray( 1, &vao );

  GLfloat vboData[ 9 ] = 
  {
   -1.0f, -1.0f, 0.0f, // bottom left screen
    1.0f, -1.0f, 0.0f, // top middle 
    0.0f,  1.0f, 0.0f, // bottom right
  };

  GLuint vbo;

  graphics::core::GraphicsContext::genVertexBuffer( 1, &vbo );

  graphics::core::GraphicsContext::bufferData( 
                                              GL_ARRAY_BUFFER, // vbo
                                              sizeof( vboData ),
                                              vboData,
                                              GL_STATIC_DRAW
                                              );

  // Now draw
  for ( int32_t i = 0; i < 2; ++i )
  {
    // Clear
    glClear( GL_COLOR_BUFFER_BIT );

    // Draw operation
    graphics::core::GraphicsContext::enableVertexArrayAttrib( 0 );

    graphics::core::GraphicsContext::bindBuffer( GL_ARRAY_BUFFER, vbo );

    glVertexAttribPointer(
                          0,        // attribute 0
                          3,        // size 
                          GL_FLOAT, // type
                          GL_FALSE, // normalized or not
                          0,        // stride
                          static_cast< void * >( 0 ) // vbo offset
                          );

    glDrawArrays( GL_TRIANGLES, 0, 3 );

    // Stop draw
    graphics::core::GraphicsContext::disableVertexArrayAttrib( 0 );

    // Swap buffer
    pContext_->makeWindowCurrent();

    sleep( 1 );
  }


}



} // namespace gtest
