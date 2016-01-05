/**
 * @copyright  Andreas Dirmeier (C) 2016
 *
 * This file is part of CcOS.
 *
 * CcOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CcOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CcOS.  If not, see <http://www.gnu.org/licenses/>.
 **/
/**
 * @author     Andreas Dirmeier
 * @version    0.01
 * @date       2016-01
 * @par        Language   C++ ANSI V3
 * @file     LinuxLed.h
 * @brief    Class LinuxLed
 */

#ifndef LinuxLed_H_
#define LinuxLed_H_

#include "CcBase.h"
#include "CcString.h"
#include "dev/CcLed.h"

/**
 * @brief Control the Input and Outputports on device
 */
class LinuxLed : public CcLed {
public:
  /**
   * @brief Constructor
   */
  LinuxLed(CcString Path);

  /**
   * @brief Destructor
   */
  virtual ~LinuxLed();

  void setMaxBirghtness(uint16 brightness);

  void setToggleTime(uint16 onTime, uint16 offTime);

  void on(uint16 brightness = 0);

  void off(void);

  void toggle(uint16 brightness = 0);

private:
  CcString m_Path;
  uint16 m_MaxBrightness;
};

#endif /* LinuxLed_H_ */
