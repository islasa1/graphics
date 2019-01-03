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
///  \File    : TextureUnit.hpp
///  \Author  : Anthony Islas
///  \Purpose : Keeps the specifics of a texture
///  \Group   : Core
///
///  \todo    : None
///
///  \License : GNU GPL v3
///
////////////////////////////////////////////////////////////////////////////////////

#include <GL/gl.h>

namespace graphics
{

namespace core
{

// type of texture
class TextureUnit : public Uniform< GLuint >
{

public:

  TextureUnit( );

  ~TextureUnit();

  GLuint createTexImage1D(
                          GLenum  target,                      // Specific type
                          GLsizei width,                       // size width
                          const GLvoid *data                   // data
                          GLenum  type           = GL_FLOAT,   // data type
                          GLint   internalFormat = GL_RGBA32F, // texture color components
                          GLenum  format         = GL_RGBA,    // pixel data format
                          GLint   level          = 0,          // mipmap level
                          );

  GLuint createTexImage2D(
                          GLenum  target,                      // Specific type
                          GLsizei width,                       // size width
                          GLsizei height,                      // size height
                          const GLvoid *data                   // data
                          GLenum  type           = GL_FLOAT,   // data type
                          GLint   internalFormat = GL_RGBA32F, // texture color components
                          GLenum  format         = GL_RGBA,    // pixel data format
                          GLint   level          = 0,          // mipmap level
                          );

  GLuint createTexImage3D(
                          GLenum  target,                      // Specific type
                          GLsizei width,                       // size width
                          GLsizei height,                      // size height
                          GLsizei depth,                       // size depth
                          const GLvoid *data                   // data
                          GLenum  type           = GL_FLOAT,   // data type
                          GLint   internalFormat = GL_RGBA32F, // texture color components
                          GLenum  format         = GL_RGBA,    // pixel data format
                          GLint   level          = 0,          // mipmap level
                          );

  GLuint texture() { return texture_; }

  virtual
  void*       getAddress()

private:

  bool        initialized_; // Prevent re-creation
  GLuint      texture_;     // Don't collide with uniform variables


};


} // namespace core

} // namespace graphics