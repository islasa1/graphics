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
//  File    : GsfParser.hpp
//  Author  : Anthony Islas
//  Purpose : Provide an implentation specific use of a generic C-like parser
//  Group   : Io
//
//  TODO    : None
//
//  License : None
//
////////////////////////////////////////////////////////////////////////////////////

#ifndef __IO_GSFPARSER_H__
#define __IO_GSFPARSER_H__

#include "Parser.hpp"

namespace io
{

typedef struct
{
  std::vector< graphics::Sprite& > sprites;
  std::vector< graphics::Anim&   > anims;

  graphics::Sprite& getSprite( std::string tag );
  graphics::Anim  & getAnim  ( std::string tag );

} sGsfElems_t;

class GsfParser : public components::Parser
{
  GsfParser( const char cCommentChar    = '#',
             const char cEscapeChar     = '\\',
             const char cScopeStartChar = '{',
             const char cScopeStartChar  = '}' ) 
    : components::Parser ( cCommentChar,
                           cEscapeChar,
                           cScopeStartChar,
                           cScopeStartChar );

  virtual ~GsfParser( );

  sGsfElem_t& Parse( std::string ssFile );
  void        Parse( std::string ssFile, models::PhysObj* pObj );

}

} // namespace io

#endif
