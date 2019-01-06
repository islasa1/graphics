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
///  \File    : Shader.cpp
///  \Author  : Anthony Islas
///  \Purpose : Implementation for shader class
///  \Group   : Core
///
///  \todo    : None
///
///  \License : GNU GPL v3
///
////////////////////////////////////////////////////////////////////////////////////

#include "Shader.hpp"

// std
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>

// gl
#include <glm/glm.hpp>

// thirdparty
// Gets OpenGL 3.1+ extensions
#include "glad/glad.h"
#define GLFW_INCLUDE_GLEXT 
#include "GLFW/glfw3.h"


namespace graphics
{

namespace core
{
  
///**********************************************************************************
///
///  \function Shader::Shader
///
///  \brief    ctor
///
///  \return   blank instance of shader
///
///**********************************************************************************
Shader::Shader( )
: programID_( 0 )
, loaded_   ( false )
, vert_     (   )
, geom_     (   )
, frag_     (   )
{
} // Shader::Shader

///**********************************************************************************
///
///  \function Shader::Shader
///
///  \brief    explicit ctor
///
///  \return    shader instance ready to be loaded
///
///**********************************************************************************
Shader::Shader(
               std::string vert,
               std::string geom,
               std::string frag
               )
: programID_( 0 )
, loaded_   ( false )
, vert_     ( vert )
, geom_     ( geom )
, frag_     ( frag )
{
} // Shader::Shader

///**********************************************************************************
///
///  \function Shader::loadProgram
///
///  \brief    Loads the shader program
///
///  \return   void - Will throw if runtime compilation fails
///
///**********************************************************************************
void 
Shader::loadProgram( )
{
  // Mostly taken from :
  // http://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/

  if ( loaded_ ) 
  {
    std::cerr << "Program has already been loaded" << std::endl;
    return; 
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  // vertex shader
  //
  // Create the shaders
  GLuint vertexShaderID = glCreateShader( GL_VERTEX_SHADER );

  compileShader( vertexShaderID, vert_ );


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  // geometry shader
  //
  GLuint geometryShaderID;
  if ( !geom_.empty() )
  {
    // Create the shaders
    geometryShaderID = glCreateShader( GL_GEOMETRY_SHADER );

    compileShader( geometryShaderID, geom_ );

  }


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  // fragment shader
  //
  // Create the shaders
  GLuint fragmentShaderID = glCreateShader( GL_FRAGMENT_SHADER );

  compileShader( fragmentShaderID, frag_ );


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  // Link the program
  //
  std::cout << "Linking program" << std::endl;

  programID_ = glCreateProgram();

  glAttachShader( programID_, vertexShaderID );
  if ( !geom_.empty() )
  {
    glAttachShader( programID_, geometryShaderID );
  }
  glAttachShader( programID_, fragmentShaderID );

  glLinkProgram( programID_ );


  // Check program
  GLint result;
  GLint infoLength;

  glGetProgramiv( programID_, GL_LINK_STATUS,     &result     );
  glGetProgramiv( programID_, GL_INFO_LOG_LENGTH, &infoLength );

  if ( infoLength > 0 || !result )
  {
    //
    std::cerr << "Failed to link program " << std::endl;
    std::vector< char > err( infoLength + 1 );

    glGetProgramInfoLog( programID_, infoLength, NULL, &err[ 0 ] );

    std::cerr << std::string( err.data() ) << std::endl;
    throw std::runtime_error( "" );

  }

  
  glDetachShader( programID_, vertexShaderID );
  if ( !geom_.empty() ) 
  {
    glDetachShader( programID_, geometryShaderID );
  }
  glDetachShader( programID_, fragmentShaderID );
  
  glDeleteShader( vertexShaderID );
  if ( !geom_.empty() ) 
  {
    glDeleteShader( geometryShaderID );
  }
  glDeleteShader( fragmentShaderID );

  // Woohoo we did it
  loaded_ = true;

} // Shader::loadProgram


///**********************************************************************************
///
///  \function Shader::useProgram
///
///  \brief    Just lets you quickly use the shader program
///
///  \return   void - 
///
///**********************************************************************************
void 
Shader::useProgram()
{
  if ( !loaded_ )
  {
  
    std::cerr << "Shader program has not been loaded" << std::endl;
    throw std::runtime_error( "" );

  }

  glUseProgram( programID_ );

} // Shader::useProgram



///**********************************************************************************
///
///  \function Shader::compileShader
///
///  \brief    Compiles a shader file
///
///  \return   void - will throw on failure
///
///**********************************************************************************
void 
Shader::compileShader(
                      uint32_t    shaderID,
                      std::string shaderFile
                      )
{

  // Read the shader code from the file
  std::string   shaderCode;
  std::ifstream inStream( shaderFile, std::ios::in );

  if ( inStream.is_open() )
  {
    // Read in file
    std::stringstream sstr;
    sstr << inStream.rdbuf();
    shaderCode = sstr.str();
    inStream.close();

  }
  else
  {

    std::cerr << "Could not open : " << shaderFile << std::endl;
    throw std::runtime_error( "" );

  }

  // Compile shader
  std::cout << "Compiling shader : " << shaderFile << std::endl;
  
  // Can't take the address of a rhs temporary
  char const *rawShader = shaderCode.c_str();
  glShaderSource( 
                  shaderID, 
                  1, 
                  &rawShader, 
                  NULL // Look to replace NULL with c++11 std
                  );

  glCompileShader( shaderID );

  // Check shader
  GLint result;
  GLint infoLength;

  glGetShaderiv( shaderID, GL_COMPILE_STATUS,  &result     );
  glGetShaderiv( shaderID, GL_INFO_LOG_LENGTH, &infoLength );

  if ( infoLength > 0 || !result )
  {
    //
    std::cerr << "Failed to compile shader : " << shaderFile << std::endl;
    std::vector< char > err( infoLength + 1 );

    glGetShaderInfoLog( shaderID, infoLength, NULL, &err[ 0 ] );

    std::cerr << std::string( err.data() ) << std::endl;
    throw std::runtime_error( "" );

  }

} // Shader::compileShader



} // namespace core

} // namespace graphics
