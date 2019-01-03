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
///  \File    : GraphicsContext.hpp
///  \Author  : Anthony Islas
///  \Purpose : It is the core of the graphics
///  \Group   : Core
///
///  \todo    : None
///
///  \License : GNU GPL v3
///
////////////////////////////////////////////////////////////////////////////////////

#ifndef __CORE_GRAPHICSCONTEXT_H__
#define __CORE_GRAPHICSCONTEXT_H__

#include <string>

struct GLFWwindow;

namespace graphics 
{

namespace core
{
  

class GraphicsContext
{

public:

  GraphicsContext( 
                  std::string windowName = "",
                  size_t      width      = 1024,
                  size_t      height     = 720
                  );
  ~GraphicsContext();
  
  bool contextCloseRequested();

  size_t getWindowWidth()  { return width_;  }
  size_t getWindowHeight() { return height_; }

  //
  // Graphics abstraction layer
  //
  static void genVertexBuffer ( size_t n, uint32_t *pVao );
  static void bindVertexBuffer( uint32_t vao );

private:

  GLFWwindow   *window_;

  std::string   windowName_;
  size_t        width_;
  size_t        height_;

};


} // namespace core

} // namespace graphics

#endif // __CORE_GRAPHICSCONTEXT_H__