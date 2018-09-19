#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smw_unix_socket_connect.h"

int handle_data_from_incomming_socket(
  SMWUnixSocket *incommingSocket, 
  int bufferSize, 
  void (*data)(SMWUnixSocket *socket, int dataSize, char *data)) {

  char buffer[bufferSize];
  ssize_t numRead = 0;
  while ((numRead = read(incommingSocket->_fileDescriptor, buffer, bufferSize)) > 0) {
    data(incommingSocket, numRead, buffer);
  }
  
  if (numRead == -1) {
    // error
    return -1;
  }
  if (close(incommingSocket->_fileDescriptor) == -1) {
    // Error
    return -1;
  }
  
  return 0;
}

SMWUnixServerSocketConnectError smw_unix_server_socket_accept_connections(
  SMWUnixSocket *socket, 
  int bufferSize,
  void (*onConnect)(SMWUnixSocket *socket), 
  void (*onData)(SMWUnixSocket *socket, int dataSize, char *data), 
  void (*onClose)(SMWUnixSocket *socket)) {

  // Handle client connections iteratively
  // Blocking!
  for (;;) {
    SMWUnixSocket *incommingSocket = smw_unix_socket_malloc();

    incommingSocket->_fileDescriptor = accept(socket->_fileDescriptor, NULL, NULL);

    if (incommingSocket->_fileDescriptor == -1) {
      return SMWUnixServerSocketConnectErrorBadIncommingSocket;
    }

    onConnect(incommingSocket);
    int handleDataResult = handle_data_from_incomming_socket(incommingSocket, bufferSize, onData);
    onClose(incommingSocket);
    smw_unix_socket_free(incommingSocket);
    if (handleDataResult < 0) {
      return SMWUnixServerSocketConnectErrorBadData;
    }
  }

  return SMWUnixServerSocketConnectErrorNone;

}


SMWUnixClientSocketConnectError smw_unix_client_socket_connect(
  SMWUnixSocket *socket,
  int bufferSize,
  void (*onConnect)(SMWUnixSocket *socket), 
  void (*onData)(SMWUnixSocket *socket, int dataSize, char *data), 
  void (*onClose)(SMWUnixSocket *socket)) {

  if (connect(socket->_fileDescriptor, (struct sockaddr *) socket->_unixSocket, sizeof(SocketAddress)) == -1) {
    return SMWUnixClientSocketConnectErrorConnecting;
  }

  onConnect(socket);
  int handleDataResult = handle_data_from_incomming_socket(socket, bufferSize, onData);
  onClose(socket);
  smw_unix_socket_free(socket);
  if (handleDataResult < 0) {
    return SMWUnixClientSocketConnectErrorBadData;
  }

  return SMWUnixClientSocketConnectErrorNone;
}