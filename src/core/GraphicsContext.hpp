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

  void   makeWindowCurrent();

  //
  // Graphics abstraction layer
  //
  static void checkError( 
                          const char *file, 
                          uint32_t    line 
                          );

  static void genVertexArray   ( size_t n, uint32_t *pVao );
  static void bindVertexArray  ( uint32_t vao );

  
  static void enableVertexArrayAttrib ( uint32_t index );
  static void disableVertexArrayAttrib( uint32_t index );


  static void genVertexBuffer ( size_t n, uint32_t *pVao );

  static void bindBuffer( int32_t target, uint32_t buffer );

  static void bufferData( 
                          int32_t       target,
                          size_t        size,
                          void         *data,
                          int32_t       usage
                        );

  static void bufferSubData( 
                            int32_t       target,
                            size_t        offset,
                            size_t        size,
                            void         *data
                          );

  static void drawArrays( 
                          int32_t mode,
                          int32_t first,
                          size_t  count 
                          );

  // Named extensions don't exist until OpenGL 4.5
  // which is not part of NVIDIA 384.130 drivers
  //
  // static void enableVertexArrayAttrib ( uint32_t vao, uint32_t index );
  // static void disableVertexArrayAttrib( uint32_t vao, uint32_t index );
  //
  // static void bufferData( 
  //                         uint32_t      buffer,
  //                         size_t        size,
  //                         void         *data,
  //                         int32_t       usage
  //                       );
  // static void bufferSubData( 
  //                           uint32_t      buffer,
  //                           size_t        offset,
  //                           size_t        size,
  //                           void         *data
  //                         );
  

private:

  GLFWwindow   *window_;

  std::string   windowName_;
  size_t        width_;
  size_t        height_;

};


} // namespace core

} // namespace graphics

#endif // __CORE_GRAPHICSCONTEXT_H__