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
///  \File    : Uniform.hpp
///  \Author  : Anthony Islas
///  \Purpose : Localize uniform values
///  \Group   : Core
///
///  \todo    : None
///
///  \License : GNU GPL v3
///
////////////////////////////////////////////////////////////////////////////////////

namespace graphics
{

namespace core
{
  
template< typename U >
class Uniform
{
public:

  enum UniformType
  {

    INT,
    UINT,
    FLOAT,
    TEX1D,
    TEX2D,
    TEX3D,
    MATRIX

  };

  template< typename U >
  Uniform(
          U           value
          UniformType uniform,
          std::string location,
          size_t      size     = 1,
          size_t      rows      = 0,      // Specific to MATRIX
          size_t      cols      = 0       // Specific to MATRIX
          );

  ~Uniform();

  virtual void setUniform();
  

  UniformType uniformType() { return uniformType_; }
  std::string location()    { return location_;    } 
  size_t      size()        { return size_;        }

  size_t      rows()        { return rows_;        }
  size_t      cols()        { return cols_;        }
  
  U           getValue()                { return uniform_;  }
  U           operator=  ( const U &u ) { uniform_ = u; return uniform_; }

private:

  U           uniform_;

  UniformType uniformType_;
  std::string location_;
  size_t      size_;

  size_t      rows_;
  size_t      cols_;

};


} // namespace core

} // namespace graphics