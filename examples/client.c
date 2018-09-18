#include <stdio.h>

//#include <smw_unix_socket/smw_unix_server.h>
//#include "smw_unix_socket.h"
#include "smw_unix_server.h"

void onConnect(SMWUnixSocket *socket) {
  printf("Made a connection\n");

  // Immediately send a message
  int dataSize = 20;
  char data[20] =  "hello";
  smw_unix_socket_send_data(socket, dataSize, data);
}

void onData(SMWUnixSocket *socket, int dataSize, char *data) {
  printf("Data: %s\n", data);
}

void onClose(SMWUnixSocket *socket) {
  printf("Connection Closed\n");
}

static void *connectToServer(void *arg) {
  SMWUnixSocket *socket = (SMWUnixSocket *)arg;
  
  return NULL;
}

int main() {
  SMWUnixSocket *socket;
  char *filePath = "/tmp/socket_server";
  if (smw_unix_client_socket_create(filePath, &socket) != SMWUnixClientSocketConnectErrorNone) {
    printf("Error creating socket");
    return 0;
  }

  if (smw_unix_client_socket_connect(socket, 100, onConnect, onData, onClose) != SMWUnixClientSocketConnectErrorNone) {
    printf("Error creating connection");
    return 0;
  }

  return 0;
}
