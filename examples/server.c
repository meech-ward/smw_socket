#include <stdio.h>

#include "smw_unix_server.h"

void onConnect(SMWUnixSocket *socket) {
  printf("Accepted a connection\n");
}

void onData(SMWUnixSocket *socket, int dataSize, char *data) {
  printf("Data: %s\n", data);
  // Echo Server
  smw_unix_socket_send_data(socket, dataSize, data);
}

void onClose(SMWUnixSocket *socket) {
  printf("Connection Closed\n");
}

int main() {
  SMWUnixSocket *socket;
  char *filePath = "/tmp/socket_server";
  if (smw_unix_server_socket_create(filePath, &socket) != SMWUnixServerSocketConnectErrorNone) {
    printf("Error creating socket");
    return 0;
  }

  if (smw_unix_server_socket_accept_connections(socket, 100, onConnect, onData, onClose) != SMWUnixServerSocketConnectErrorNone) {
    printf("Error accepting connections");
    return 0;
  }

  return 0;
}
