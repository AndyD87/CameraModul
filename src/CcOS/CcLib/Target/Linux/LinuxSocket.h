/**
* @author     Andreas Dirmeier
* @copyright  Andreas Dirmeier (c) 2015
* @version    0.01
* @date       2015-10
* @par        Language   C++ ANSI V3
*/
/**
* @file     LinuxSocket.h
* @brief    Class LinuxSocket
*/
#ifndef LinuxSocket_H_
#define LinuxSocket_H_

#include "CcBase.h"
#include "com/CcSocket.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/**
* @brief Create a Socket on Linux Systems
*/
class LinuxSocket : public CcSocket{
public:
  /**
  * @brief Constructor
  */
  LinuxSocket( eSocketType type = eTCP );

  LinuxSocket(int socket, sockaddr sockAddr, int sockAddrlen);
  /**
   * @brief Destructor
   */
  virtual ~LinuxSocket( void );

  bool open(uint16){ return true; }
  bool close();
  bool cancel();

  /**
   * @brief connect to Host with known IP-Address and Port
   * @param ipAdress: IpAddress of Host
   * @param Port:     Port where host ist waiting for connection
   * @return true if connection was successfully established
   */
  bool bind(ipv4_t ipAddress, uint16 Port);

  /**
   * @brief connect to Host with known Name in Network and Port
   * @param hostName: Name of Host to connect to
   * @param Port:     Port where host ist waiting for connection
   * @return true if connection was successfully established
   */
  bool connect(ipv4_t ipAddress, uint16 Port);

  /**
  * @brief connect to Host with known Name in Network and Port
  * @param hostName: Name of Host to connect to
  * @param Port:     Port where host ist waiting for connection
  * @return true if connection was successfully established
  */
  bool connect(CcString& hostName, CcString &hostPort);

  /**
   * @brief Socket becomes a Host and listen on Port
   * @return true if port is successfully initiated.
   */
  bool listen(void);

  /**
   * @brief Waiting for an incoming connection.
   * @return Valid socket if connection established, otherwise 0.
   */
  CcSocket* accept(void);

  /**
   * @brief Send data to established socket-connection
   * @param buf: Buffer of data to be send
   * @param bufSize: size of buffer to send
   * @return return true if transmission succeeded.
   */
  size_t write(char *buf, size_t bufSize);

  /**
   * @brief Receive incoming data from socket
   * @param buf: Buffer to store received data.
   * @param bufSize: maximum size of buffer;
   * @return Size of data read from socket.
   */
  size_t read(char *buf, size_t bufSize);

  /**
   * @brief read with timeout
   */
  size_t readTimeout(char *buf, size_t bufSize, time_t timeout = 10);

  /**
   * @brief Get ip-address of Hostname
   * @param hostname: Hostname as String to search for
   * @param addr [out]: found ip-address or 0.0.0.0 if failed
   * @return
   */
  bool getHostByName(CcString &hostname, ipv4_t *addr);

  static void startWSA(void);
private:
  eSocketType   m_Type;
  int           m_ClientSocket;      ///< ClientSocket generated by InitSocket
  sockaddr      m_sockAddr;
  int           m_sockAddrlen;
};

#endif /* LinuxSocket_H_ */