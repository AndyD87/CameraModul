/**
 * @author     Andreas Dirmeier
 * @copyright  Andreas Dirmeier (c) 2015
 * @version    0.01
 * @date       2015-10
 * @par        Language   C++ ANSI V3
 */
/**
 * @file     CcHttpReceiver.cpp
 * @brief    Implementation of Class CcHttpReceiver
 */
#include "CcHttpReceiver.h"

CcHttpReceiver::CcHttpReceiver( void )
{
}

CcHttpReceiver::~CcHttpReceiver( void )
{
}

CcCharArray CcHttpReceiver::execGet(CcString &Url, CcVector<CcStringPair> *IncomeData){
  CC_UNUSED(Url);
  CC_UNUSED(IncomeData);
  CcCharArray caRet;
  return caRet;
}

CcCharArray CcHttpReceiver::execPost(CcString &Url, CcVector<CcStringPair> *IncomeData, CcStringList *Files ){
  CC_UNUSED(Url);
  CC_UNUSED(IncomeData);
  CC_UNUSED(Files);
  return execGet(Url);
}
