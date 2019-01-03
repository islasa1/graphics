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

private:

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
  SetupContext( );

  GLuint vao;

  graphics::core::GraphicsContext::genVertexBuffer( 1, &vao );

}



} // namespace gtest
