#include <stdlib.h>

#include "smw_unix_socket.h"

SMWUnixSocket *smw_unix_socket_malloc() {
  SMWUnixSocket *socket = malloc(sizeof(SMWUnixSocket));

  socket->_unixSocket = malloc(sizeof(SocketAddress));
  
  return socket;
}
void smw_unix_socket_free(SMWUnixSocket *socket) {
  free(socket->_unixSocket);
  free(socket);
}