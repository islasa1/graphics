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

// std 
#include <fstream>
#include <sstream>
#include <iostream>

// gl
#include <glm/glm.hpp>

// thirdparty
#include "glad/glad.h"
#define GLFW_INCLUDE_GLEXT 
#include "GLFW/glfw3.h"


// A context check basically requires everything
#include "config.hpp"
#include "core/Shader.hpp"


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

    pContext_ = 0;

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
    windowSize_ = 64;
    displayBuffer_.resize( windowSize_ * windowSize_ * 3, 0.0f );

    pContext_ = new graphics::core::GraphicsContext( windowName, windowSize_, windowSize_ );
  }

  void getBuffer()
  {
    glReadPixels( 
                  static_cast< GLint    >( 0 ),
                  static_cast< GLint    >( 0 ),
                  static_cast< GLsizei  >( windowSize_ ),
                  static_cast< GLsizei  >( windowSize_ ),
                  GL_RGB,
                  GL_FLOAT,
                  static_cast< GLvoid * >( displayBuffer_.data() )
                );
  }

  void dumpBuffer()
  {
    std::cout << "RGB : " << std::endl;
    size_t stride = 3;

    for ( size_t i = 0; i < windowSize_; ++i )
    {   
      for ( size_t j = 0; j < windowSize_; ++j )
      {
        std::cout << "[ " 
                  << displayBuffer_[ i * windowSize_ * stride + j * stride + 0 ] << ", "
                  << displayBuffer_[ i * windowSize_ * stride + j * stride + 1 ] << ", "
                  << displayBuffer_[ i * windowSize_ * stride + j * stride + 2 ] << "] ";
      }
      std::cout << std::endl;
    }
  }

// I thought tests were part of the class, apparently not
// private:

  graphics::core::GraphicsContext *pContext_;
  size_t                           windowSize_;
  std::vector< float > displayBuffer_;
  
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
  for ( int32_t i = 0; i < 1; ++i )
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

    graphics::core::GraphicsContext::drawArrays( GL_TRIANGLES, 0, 3 );

    // Stop draw
    graphics::core::GraphicsContext::disableVertexArrayAttrib( 0 );

    // Swap buffer
    pContext_->makeWindowCurrent();

    sleep( 1 );

  }

}

TEST_F( TEST_CASE, DisplayOnWindowTriangleShader )
{
  // Based on :
  // http://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
  SetupContext( "Demo Triangle" );

  GLuint vao;
  GLuint vbo;

  graphics::core::GraphicsContext::genVertexArray( 1, &vao );

  GLfloat vboData[ 9 ] = 
  {
   -1.0f, -1.0f, 0.0f, // bottom left screen
    1.0f, -0.5f, 0.0f, // bottom right
    0.0f,  1.0f, 0.0f, // top middle 
  };

  graphics::core::GraphicsContext::genVertexBuffer( 1, &vbo );


  // BIND
  graphics::core::GraphicsContext::bindVertexArray( vao );
  graphics::core::GraphicsContext::bindBuffer( GL_ARRAY_BUFFER, vbo );

  graphics::core::GraphicsContext::bufferData( 
                                              GL_ARRAY_BUFFER, // vbo
                                              sizeof( vboData ),
                                              vboData,
                                              GL_STATIC_DRAW
                                              );


  // graphics::core::GraphicsContext::bindBuffer( GL_ARRAY_BUFFER, vbo );
  glVertexAttribPointer(
                        0,        // attribute 0
                        3,        // size 
                        GL_FLOAT, // type
                        GL_FALSE, // normalized or not
                        3 * sizeof( float ),       // stride
                        static_cast< void * >( 0 ) // vbo offset
                        );

  graphics::core::GraphicsContext::enableVertexArrayAttrib( 0 );

  // graphics::core::GraphicsContext::disableVertexArrayAttrib( 0 );
  
  // UNBIND
  graphics::core::GraphicsContext::bindBuffer( GL_ARRAY_BUFFER, 0 );
  graphics::core::GraphicsContext::bindVertexArray( 0 );


  // Set shader program
  graphics::core::Shader shader( 
                                graphics::SHADER_PATH + "/debug_vert.glsl",
                                "", // no geom
                                graphics::SHADER_PATH + "/debug_frag.glsl"
                                );


  shader.loadProgram();

  graphics::core::GraphicsContext::checkError( __FILE__, __LINE__ );

  // Now draw
  for ( int32_t i = 0; i < 2; ++i )
  {
    // Clear

    // Set clear color
    glClearColor( 0.1f, 0.0f, 0.4f, 1.0f );
    // glDisable( GL_CULL_FACE );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Draw operation
    shader.useProgram();
    
    // Get states
    graphics::core::GraphicsContext::bindVertexArray( vao );

    graphics::core::GraphicsContext::drawArrays( GL_TRIANGLES, 0, 3 );

    // debug
    // getBuffer();
    // dumpBuffer();
    
    // Swap buffer
    pContext_->makeWindowCurrent();

    sleep( 1 );
    
  }

  graphics::core::GraphicsContext::checkError( __FILE__, __LINE__ );

}

} // namespace gtest
