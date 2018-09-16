
#include <stdio.h>
#include <errno.h>

#include "smw_unix_server.h"

void onConnect(SMWUnixSocket *socket) {
  printf("Accepted a connection\n");
}

void onData(SMWUnixSocket *socket, int dataSize, char *data) {
  printf("Data: %s\n", data);
  // Echo
  smw_unix_server_socket_send_data(socket, dataSize, data);
  smw_unix_server_socket_close(socket);
}

void onClose(SMWUnixSocket *socket) {
  printf("Connection Closed\n");
}

int main() {
  SMWUnixSocket *socket;
  SMWUnixServerSocketCreateError error = smw_unix_server_socket_create("/tmp/sam6", &socket);
  if (error != SMWUnixServerSocketConnectErrorNone) {
    printf("Error %i %i", error, errno);
    return 0;
  }

  smw_unix_server_socket_accept_connections(socket, 100, onConnect, onData, onClose);

  return 0;
}