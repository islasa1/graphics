////////////////////////////////////////////////////////////////////////////////////
//
//     _____    ____ _       ____ _        __ _      __ _  __ _  ______ _   ___ _
//    / /| |]  |  __ \\     / ___ \\      / \ \\    |   \\/   |]|  _____|] / ___|]
//   / //| |]  | |] \ \\   | |]  \_|]    / //\ \\   | |\ / /| |]| |]___ _ ( ((_ _
//  / //_| |]_ | |]  ) ))  | |]  __ _   / _____ \\  | |]\_/ | |]|  _____|] \___ \\
// |_____   _|]| |]_/ //   | |]__/  |] / //    \ \\ | |]    | |]| |]___ _   ___) ))
//       |_|]  |_____//     \_____/|]]/_//      \_\\|_|]    |_|]|_______|] |____//
// 
//
////////////////////////////////////////////////////////////////////////////////////
//
//
//  File    : Sprite.cpp
//  Author  : Anthony Islas
//  Purpose : Sprite graphics for wrapper graphics library to use NCurses
//  Group   : Graphics
//
//  TODO    : None
//
//  License : None
//
////////////////////////////////////////////////////////////////////////////////////

#include "Sprite.hpp"

namespace graphics
{

//**********************************************************************************
//
//  Sprite::Sprite
//
//  \brief Ctor
// 
//  \param rvTextureMap is the sprite img data
//  \param ulTicks is how many ticks the sprite should last
//  \param ssTag is the tag identifier for the sprite
//
//  \return Sprite
//
//**********************************************************************************  
Sprite::Sprite( std::vector< unsigned long >& rvTextureMap,
                unsigned long ulTicks,
                std::string ssTag 
                ) 
  : ssTag_        ( ssTag )
  , ulTicks_      ( ulTicks      )
  , ulTickCount_  ( 0          )
  , rvTextureMap_ ( rvTextureMap )
{
  
} // Sprite::Sprite



//**********************************************************************************
//
//  Sprite::~Sprite
//
//  \brief Dtor
// 
//
//  \return none
//
//**********************************************************************************
Sprite::~Sprite( )
{
  
} // Sprite::~Sprite

//**********************************************************************************
//
//  Sprite::draw
//
//  \brief Draw the image data
// 
//  Draws the internal image data to the current graphics handler using ncurses
//
//  \return true if sprite has not finished its ticks
//
//**********************************************************************************
bool Sprite::draw( )
{
  //
  //\todo Finish the ncurses impementation here
  //

  //
  // ~~ Magic ~~
  //

  //
  // Increase counter
  // 
  ulTickCount_++;

  //
  // Check sprite tick count
  //
  if ( ulTickCount_ > ulTicks_ )
  {
    //
    // Reset ticks
    //
    ulTickCount_ = 0;

    return false;

  }

  return true;

} // Sprite::draw

} // namespace graphics
