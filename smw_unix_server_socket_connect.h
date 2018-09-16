#ifndef __smw_unix_server_socket_connect_h__
#define __smw_unix_server_socket_connect_h__

#include "smw_unix_server_socket.h"

typedef enum {
  SMWUnixServerSocketConnectErrorNone = 0,
  SMWUnixServerSocketConnectErrorBadIncommingSocket
} SMWUnixServerSocketConnectError;

SMWUnixServerSocketConnectError smw_unix_stream_socket_accept_connections(
  SMWUnixServerSocket *socket, 
  int bufferSize,
  void (*connect)(SMWUnixServerSocket *socket), 
  void (*data)(SMWUnixServerSocket *socket, char *data), 
  void (*close)(SMWUnixServerSocket *socket));

#endif