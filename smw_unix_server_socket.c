#include <stdlib.h>

#include "smw_unix_server_socket.h"

SMWUnixServerSocket *smw_unix_server_socket_malloc() {
  SMWUnixServerSocket *socket = malloc(sizeof(SMWUnixServerSocket));

  socket->_unixSocket = malloc(sizeof(SocketAddress));
  
  return socket;
}
void smw_unix_server_socket_free(SMWUnixServerSocket *socket) {
  free(socket->_unixSocket);
  free(socket);
}