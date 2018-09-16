#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smw_unix_client_socket_connect.h"

SMWUnixClientSocketConnectError smw_unix_client_socket_connect(SMWUnixSocket *socket) {
  if (connect(socket->_fileDescriptor, (struct sockaddr *) socket->_unixSocket, sizeof(SocketAddress)) == -1) {
    return SMWUnixClientSocketConnectErrorConnecting;
  }
  return SMWUnixClientSocketConnectErrorNone;
}