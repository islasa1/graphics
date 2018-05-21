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
//  File    : Anim.cpp
//  Author  : Anthony Islas
//  Purpose : Animation graphics for wrapper graphics library to use NCurses
//  Group   : Primitives
//
//  TODO    : None
//
//  License : None
//
////////////////////////////////////////////////////////////////////////////////////


#include "Anim.hpp"

#include "Sprite.hpp"

namespace graphics
{

//**********************************************************************************
//
//  Anim::Anim
//
//  \brief Ctor
//
//  \param ssTag is the tag identifier for the animation
//
//  \return Anim
//
//**********************************************************************************
Anim::Anim( std::string ssTag ) 
  : ssTag_            ( ssTag )
  , ulCurSpriteFrame_ ( 0   )
{
  
} // Anim::Anim

//**********************************************************************************
//
//  Anim::~Anim
//
//  \brief Dtor
//
//  \return none
//
//**********************************************************************************
Anim::~Anim( )
{
  
} // Anim::~Anim

//**********************************************************************************
//
//  Anim::addSprite
//
//  \brief Adds a sprite to the reel sequentially
// 
//  \param rSprite is a reference to a fully created Sprite
// 
//  Puts an animation in the back of the sprite reel
//
//  \return none
//
//**********************************************************************************
void Anim::addSprite( Sprite& rSprite )
{
  
  vReel_.push_back( rSprite );

} // Anim::addSprite


//**********************************************************************************
//
//  Anim::play
//
//  \brief Plays the animation
// 
// 
//  Iterates through the Sprites in the reel and draws each
//
//  \return true if anim has not finished its frames
//
//**********************************************************************************
bool Anim::play( )
{

  if ( !vReel_.[ ulCurSpriteFrame_ ].draw( ) )
  {
    //
    // The current sprite has completed its alloted ticks
    //
    ulCurSpriteFrame_++;

  }

  if ( ulCurSpriteFrame_ == vReel_.size( ) )
  {
    //
    // restart the animation for the next play through
    //
    ulCurSpriteFrame_ = 0;

    return false;
  }

  return true;

} // Anim::play

} // namespace graphics