/**
* @author     Andreas Dirmeier
* @copyright  Andreas Dirmeier (c) 2015
* @version    0.01
* @date       2015-09
* @par        Language   C++ ANSI V3
*/
/**
* @file     main.cpp
* @brief    Development default CLI-Application for testing new Implementations
*/

#include "CcBase.h"
#include "CcKernel.h"
#include "CcFtpServer.h"
#include "CcHttpServer.h"
#include "dev/CcLed.h"
#include "stdio.h"


// Application entry point. 
int main(int argc, char **argv)
{
  Kernel.setArg(argc, argv);
  Kernel.initCLI();

  /*CCcFtpServer FtpServer(27521);
  FtpServer.start();*/
  CcHttpServer HttpServer(27580);
  HttpServer.start();

  CcLed *temp = (CcLed*)(Kernel.getDevice(eLed, "wps_led"));

  Kernel.stop();
  return 0;
}
