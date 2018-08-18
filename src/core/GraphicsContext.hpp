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
///  \File    : GraphicsContext.hpp
///  \Author  : Anthony Islas
///  \Purpose : It is the core of the graphics
///  \Group   : Core
///
///  \todo    : None
///
///  \License : GNU GPL v3
///
////////////////////////////////////////////////////////////////////////////////////

#ifndef __CORE_GRAPHICSCONTEXT_H__
#define __CORE_GRAPHICSCONTEXT_H__

#include <string>

namespace graphics 
{

namespace core
{
  

class GraphicsContext
{

public:

  GraphicsContext( 
                  std::string windowName = "" 
                  );
  ~GraphicsContext();
  

private:

  

};


} // namespace core

} // namespace graphics

#endif // __CORE_GRAPHICSCONTEXT_H__