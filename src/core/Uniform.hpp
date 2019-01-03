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
#ifndef __CORE_UNIFORM_H__
#define __CORE_UNIFORM_H__


namespace graphics
{

namespace core
{

  
template< typename U >
class Uniform : public UniformBase
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
          size_t      size      = 1,
          size_t      rows      = 0,      // Specific to MATRIX
          size_t      cols      = 0       // Specific to MATRIX
          );

  ~Uniform();

  virtual
  void*       getAddress();
  void        setUniform();
  
  UniformType uniformType() { return uniformType_; }
  std::string location()    { return location_;    } 
  size_t      size()        { return size_;        }

  size_t      rows()        { return rows_;        }
  size_t      cols()        { return cols_;        }

  // This a nifty container class to do this
  U getValue()                { return uniform_;  }
  U operator=  ( const U &u ) { uniform_ = u; return uniform_; }

private:

  U           uniform_;
  
  UniformType uniformType_;
  std::string location_;
  size_t      size_;

  size_t      rows_;
  size_t      cols_;

};


///**********************************************************************************
///
///  \function Uniform::Uniform
///
///  \brief    ctor
///
///  \return   N/A
///
///**********************************************************************************
template< typename U >
Uniform::Uniform(
                 U           value,
                 UniformType uniform,
                 std::string location,
                 size_t      size,
                 size_t      rows,
                 size_t      cols
                 )
: uniform_    ( value )
, uniformType_( uniform  )
, location_   ( location )
, size_       ( size     )
, rows_       ( rows     )
, cols_       ( cols     )
{} // Uniform::Uniform

///**********************************************************************************
///
///  \function Uniform::~Uniform
///
///  \brief    dtor
///
///  \return   N/A
///
///**********************************************************************************  
Uniform::~Uniform()
{} // Uniform::~Uniform

///**********************************************************************************
///
///  \function Uniform::getAddress
///
///  \brief    Virtual function to determine value when assigning the uniform. Helpful
///            for getting glm::value_ptr and things like that
///
///  \return   void* - The raw pointer to the value
///
///**********************************************************************************
void* 
Uniform::getAddress()
{
  
  return static_cast< void * >( &uniform_ );

} // Uniform::getAddress




} // namespace core

} // namespace graphics

#endif // __CORE_UNIFORM_H__