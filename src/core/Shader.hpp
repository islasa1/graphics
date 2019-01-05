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
///  \File    : Shader.hpp
///  \Author  : Anthony Islas
///  \Purpose : Encapsulate shader compilation and such
///  \Group   : Core
///
///  \todo    : None
///
///  \License : GNU GPL v3
///
////////////////////////////////////////////////////////////////////////////////////

#ifndef __CORE_SHADER_H__
#define __CORE_SHADER_H__

#include <string>

namespace graphics
{

namespace core
{
  

class Shader
{
public:
  Shader( );
  Shader( 
          std::string vert, 
          std::string geom, 
          std::string frag
          );

  ~Shader( ) {}

  void setVertShader( std::string file ) { vert_ = file; }
  void setGeomShader( std::string file ) { geom_ = file; }
  void setFragShader( std::string file ) { frag_ = file; }

  // We can use this class as an alias to the actual program 
  operator uint32_t() const { return programID_; } 

  void loadProgram();

  void useProgram();

private:

  // try to stick to sharing a common shader instead of copying
  Shader( const Shader & ) = delete;

  void compileShader( uint32_t shaderID, std::string shaderFile );

  uint32_t programID_;
  bool     loaded_;    ///< Need to keep track since 0 is perfectly valid for program ID

  std::string vert_;
  std::string geom_;
  std::string frag_;

};



} // namespace core

} // namespace graphics

#endif // __CORE_SHADER_H__