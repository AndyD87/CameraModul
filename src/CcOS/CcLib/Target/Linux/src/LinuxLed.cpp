/**
 * @author     Andreas Dirmeier
 * @copyright  Andreas Dirmeier (c) 2015
 * @version    0.01
 * @date       2015-08
 * @par        Language   C++ ANSI V3
 */
/**
 * @file     LinuxLed.cpp
 * @brief    Class LinuxLed
 */

#include "LinuxLed.h"
#include "CcFile.h"
#include "stdio.h"

LinuxLed::LinuxLed(CcString Path) :
  m_Path(Path)
{
  CcString filename("max_brightness");
  CcFile file(m_Path.calcPathAppend(filename));
  if(file.open(Open_Read)){
    CcString Temp;
    char buf[20];
    size_t read;
    read = file.read(buf, 20);
    file.close();
    Temp.append(buf, read);
    m_MaxBrightness = Temp.toUint16();
  }
}

LinuxLed::~LinuxLed() {
  // TODO Auto-generated destructor stub
}

void LinuxLed::setMaxBirghtness(uint16 brightness){
  CcString filename("brightness");
  CcFile file(m_Path.calcPathAppend(filename));
  if(file.open(Open_Write)){
    CcString Temp;
    Temp.appendNumber(brightness);
    file.write(Temp.getCharString(), Temp.length());
    file.close();
  }
}

void LinuxLed::setToggleTime(uint16 onTime, uint16 offTime){
  CcString filename("delay_on");
  CcFile fileOn(m_Path.calcPathAppend(filename));
  if(fileOn.open(Open_Write)){
    CcString Temp;
    Temp.appendNumber(onTime);
    fileOn.write(Temp.getCharString(), Temp.length());
    fileOn.close();
  }
  filename = "delay_off";
  CcFile fileOff(m_Path.calcPathAppend(filename));
  if(fileOff.open(Open_Write)){
    CcString Temp;
    Temp.appendNumber(offTime);
    fileOff.write(Temp.getCharString(), Temp.length());
    fileOff.close();
  }
}

void LinuxLed::on(uint16 brightness){
  CcString filename("brightness");
  if(brightness == 0){
    CcFile file(m_Path.calcPathAppend(filename));
    if(file.open(Open_Write)){
      CcString Temp;
      Temp.appendNumber(m_MaxBrightness);
      file.write(Temp.getCharString(), Temp.length());
      file.close();
    }
  }
  else{
    CcFile file(m_Path.calcPathAppend(filename));
    if(file.open(Open_Write)){
      CcString Temp;
      Temp.appendNumber(brightness);
      file.write(Temp.getCharString(), Temp.length());
      file.close();
    }
  }
}

void LinuxLed::off(void){
  CcString filename("brightness");
  CcFile file(m_Path.calcPathAppend(filename));
  if(file.open(Open_Write)){
    CcString Temp("0");
    file.write(Temp.getCharString(), Temp.length());
    file.close();
  }
}

void LinuxLed::toggle(uint16 brightness){
  CcString filename("toggle");
  CcFile file(m_Path.calcPathAppend(filename));
  if(file.open(Open_Write)){
    CcString Temp("1");
    file.write(Temp.getCharString(), Temp.length());
    file.close();
  }
}
