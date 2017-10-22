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

#include "GsfParser.hpp"

namespace io
{

//**********************************************************************************
//
//  GsfParser::GsfParser
//
//  \brief Ctor
// 
//  See Parser for param descriptions
//  
//  GSF Specific parser
//
//  \return GsfParser
//
//**********************************************************************************
GsfParser::GsfParser( const char cCommentChar,
                           const char cEscapeChar,
                           const char cScopeStartChar,
                           const char cScopeStopChar 
                           )
{
  
} // GsfParser::GsfParser

//**********************************************************************************
//
//  GsfParser::~GsfParser
//
//  \brief Dtor
//
//  \return none
//
//**********************************************************************************
GsfParser::~GsfParser( )
{
  
} // GsfParser::~GsfParser

//**********************************************************************************
//
//  GsfParser::Parse
//
//  \brief Parse a GSF file
// 
//  \param ssFile 
// 
//  Parse the given *.gsf file into Sprites and Anims to be used by user
//
//  \return gsfElem reference containing all gsf file contents
//
//**********************************************************************************
sGsfElem_t& GsfParser::Parse( std::string ssFile )
{
  


} // GsfParser::Parse

//**********************************************************************************
//
//  GsfParser::Parse
//
//  \brief Parses a GSF file into a PhysObj
// 
//  \param ssFile 
//  \param pObj 
// 
//  Parse the given *.gsf file, putting the Sprites and animations into a PhysObj
//
//  \return none
//
//**********************************************************************************
void GsfParser::Parse( std::string ssFile, models::PhysObj* pObj )
{
  
  //
  // Get the elements
  //
  sGsfElem_t sGsfElem = Parse( ssFile );

  //
  // Push them into the PhysObj
  //

} // GsfParser::Parse


} // namespace io
