/**
 * @copyright  Andreas Dirmeier (C) 2015
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
 * @date       2015-10
 * @par        Language   C++ ANSI V3
 * @file     CcHttpServer.cpp
 * @brief    Implementation of Class CcHttpServer
 *           Protocol: http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html
 */
#include "CcKernel.h"
#include "CcThread.h"
#include "CcHttpServer.h"

CcApp* CcHttpServer::main(CcStringList *Arg)
{
  CcApp* ret = new CcHttpServer(Arg);
  return ret;
}

CcHttpServer::CcHttpServer( uint16 Port ) :
  m_Port(Port)
{
}

CcHttpServer::CcHttpServer(CcStringList *Arg) :
  m_Port(80)
{
  CC_UNUSED(Arg);
}

CcHttpServer::~CcHttpServer( void )
{
}

void CcHttpServer::setWorkingDir(CcString &Wd){
  m_WD = Wd;
}

CcString &CcHttpServer::getWorkingDir(void){
  return m_WD;
}

void CcHttpServer::registerReceiver(CcHttpReceiver *toAdd){
  m_ReceiverList.append(toAdd);
}

void CcHttpServer::deregisterReceiver(CcHttpReceiver *toRemove){
  m_ReceiverList.deleteItem(toRemove);
}

CcVector<CcHttpReceiver*> CcHttpServer::getReceiverList(void){
  return m_ReceiverList;
}

void CcHttpServer::run(void){
  m_Socket = Kernel.getSocket(eTCP);
  ipv4_t localhost = { 127, 0, 0, 1 };
  m_Socket->bind(localhost, m_Port);
  m_Socket->listen();
  CcSocket *temp;
  while (getThreadState() == CCTHREAD_RUNNING){
    temp = m_Socket->accept();
    CcHttpServerWorker *worker = new CcHttpServerWorker(this, temp);
    worker->start();
  }
}
