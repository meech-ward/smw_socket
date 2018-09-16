#ifndef __smw_unix_client_socket_connect_h__
#define __smw_unix_client_socket_connect_h__

#include "smw_unix_socket.h"

typedef enum {
  SMWUnixClientSocketConnectErrorNone = 0,
  SMWUnixClientSocketConnectErrorConnecting
} SMWUnixClientSocketConnectError;

SMWUnixClientSocketConnectError smw_unix_client_socket_connect(SMWUnixSocket *socket);

#endif