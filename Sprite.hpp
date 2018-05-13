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
//  File    : Sprite.hpp
//  Author  : Anthony Islas
//  Purpose : Sprite graphics for wrapper graphics library to use NCurses
//  Group   : Graphics
//
//  TODO    : None
//
//  License : None
//
////////////////////////////////////////////////////////////////////////////////////

#ifndef __GRAPHICS_SPRITE_H__
#define __GRAPHICS_SPRITE_H__

namespace graphics
{

const unsigned long TRANS_CHAR = 0;

class Sprite
{

public:

  Sprite( std::vector< unsigned long >& rvTextureMap, unsigned long ulTicks, std::string ssTag );
  ~Sprite( );

#ifdef USE_COLOR
  void setColorMap( std::vector< unsigned long > vColorMap );
#endif

  bool draw( );

  const std::string tag( ) { return  ssTag_; }

private:

  std::string                  &ssTag_;

  const unsigned long           ulTicks_;
  unsigned long                 ulTickCount_;

  std::vector< unsigned long > &rvTextureMap_;

#ifdef USE_COLOR
  std::vector< unsigned long > vColorMap_;
#endif // USE_COLOR

};

}

#endif // __GRAPHICS_SPRITE_H__
