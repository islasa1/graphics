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
//  File    : Anim.hpp
//  Author  : Anthony Islas
//  Purpose : Animation graphics for wrapper graphics library to use NCurses
//  Group   : Primitives
//
//  TODO    : None
//
//  License : None
//
////////////////////////////////////////////////////////////////////////////////////

#ifndef __PRIMITIVES_ANIM_HPP__
#define __PRIMITIVES_ANIM_HPP__

namespace graphics
{

class Sprite;

class Anim
{

public:

  Anim( std::string ssTag );

  ~Anim( );

  void addSprite( Sprite& rSprite );

  bool play( );

  const std::string tag( ) { return  ssTag_; }

private:

  std::string            &ssTag_
  std::vector< Sprite& >  vReel_;
  unsigned long           ulCurSpriteFrame_;
  
};


}

#endif // __PRIMITIVES_ANIM_HPP__