/**
 * @author     Andreas Dirmeier
 * @copyright  Andreas Dirmeier (c) 2015
 * @version    0.01
 * @date       2015-10
 * @par        Language   C++ ANSI V3
 */
/**
 * @file     CcHttpReceiver.h
 * @brief    Class CcHttpReceiver
 */
#ifndef CcHttpReceiver_H_
#define CcHttpReceiver_H_

#include "CcBase.h"
#include "CcCharArray.h"
#include "CcStringList.h"

/**
 * @brief Button for GUI Applications
 */
class CcHttpReceiver {
public:
  /**
   * @brief Constructor
   */
  CcHttpReceiver( void );

  /**
   * @brief Destructor
   */
  virtual ~CcHttpReceiver( void );

  virtual CcString getUrl(void);
  virtual CcCharArray execGet(CcString &Url, CcVector<CcStringPair> *IncomeData = 0);
  virtual CcCharArray execPost(CcString &Url, CcVector<CcStringPair> *IncomeData = 0, CcStringList *Files = 0);

};

#endif /* CcHttpReceiver_H_ */
