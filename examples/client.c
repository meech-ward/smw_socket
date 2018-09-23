#include <stdio.h>

#include "smw_socket.h"

void send_input_to_socket(SMWUnixSocket *socket) {
  char data[100];
  printf("Data:\n");
  fgets(data, 100, stdin);

  smw_unix_socket_send_data(socket, 100, data);
}

void on_connect(SMWUnixSocket *socket) {
  // When the client has connected to the server, prompt the user for input and send it to the server.
  send_input_to_socket(socket);
}

void on_data(SMWUnixSocket *socket, int dataSize, char *data) {
  // Wait for a response from the server, then prompt the user for input and send it to the server.
  send_input_to_socket(socket);
}

void on_close(SMWUnixSocket *socket) {
  printf("Connection Closed\n");
}

int main() {
  SMWUnixSocket *socket;
  char *filePath = "/tmp/socket_server";
  if (smw_unix_client_socket_create(filePath, &socket) != SMWUnixClientSocketConnectErrorNone) {
    fprintf(stderr, "Error creating socket\n");
    return 1;
  }

  if (smw_unix_client_socket_connect(socket, 100, on_connect, on_data, on_close) != SMWUnixClientSocketConnectErrorNone) {
    fprintf(stderr, "Error creating connection\n");
  }

  return 0;
}
