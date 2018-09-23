#ifndef __smw_unix_server_socket_connect_h__
#define __smw_unix_server_socket_connect_h__

#include "smw_unix_socket.h"

typedef enum {
  SMWUnixServerSocketConnectErrorNone = 0,
  SMWUnixServerSocketConnectErrorBadIncommingSocket,
  SMWUnixServerSocketConnectErrorBadData
} SMWUnixServerSocketConnectError;

SMWUnixServerSocketConnectError smw_unix_server_socket_accept_connections(
  SMWUnixSocket *socket, 
  int bufferSize,
  void (*onConnect)(SMWUnixSocket *socket), 
  void (*onData)(SMWUnixSocket *socket, int dataSize, char *data), 
  void (*onClose)(SMWUnixSocket *socket));

typedef enum {
  SMWUnixClientSocketConnectErrorNone = 0,
  SMWUnixClientSocketConnectErrorConnecting,
  SMWUnixClientSocketConnectErrorBadData
} SMWUnixClientSocketConnectError;

SMWUnixClientSocketConnectError smw_unix_client_socket_connect(
  SMWUnixSocket *socket,
  int bufferSize,
  void (*onConnect)(SMWUnixSocket *socket), 
  void (*onData)(SMWUnixSocket *socket, int dataSize, char *data), 
  void (*onClose)(SMWUnixSocket *socket));

#endif