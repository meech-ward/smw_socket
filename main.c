
#include <stdio.h>
#include <errno.h>

#include "smw_unix_server.h"

void onConnect(SMWUnixServerSocket *socket) {
  printf("Accepted a connection\n");
}

void onData(SMWUnixServerSocket *socket, int dataSize, char *data) {
  printf("Data: %s\n", data);
  // Echo
  smw_unix_server_socket_send_data(socket, dataSize, data);
}

void onClose(SMWUnixServerSocket *socket) {
  printf("Connection Closed\n");
}

int main() {
  SMWUnixServerSocket *socket;
  SMWUnixServerSocketCreateError error = smw_unix_server_socket_create("/tmp/sam6", &socket);
  if (error != SMWUnixServerSocketConnectErrorNone) {
    printf("Error %i %i", error, errno);
    return 0;
  }

  smw_unix_server_socket_accept_connections(socket, 100, onConnect, onData, onClose);

  printf("hello\n");

  return 0;
}