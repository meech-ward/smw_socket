#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smw_unix_server_socket_connect.h"

int handle_data_from_incomming_socket(
  SMWUnixServerSocket *incommingSocket, 
  int bufferSize, 
  void (*data)(SMWUnixServerSocket *socket, int dataSize, char *data)) {

  char buffer[bufferSize];
  ssize_t numRead = 0;
  ssize_t numReadTotal = 0;
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
  SMWUnixServerSocket *socket, 
  int bufferSize,
  void (*connect)(SMWUnixServerSocket *socket), 
  void (*data)(SMWUnixServerSocket *socket, int dataSize, char *data), 
  void (*close)(SMWUnixServerSocket *socket)) {

  // Handle client connections iteratively
  // Blocking!
  for (;;) {
    SMWUnixServerSocket *incommingSocket = smw_unix_server_socket_malloc();

    incommingSocket->_fileDescriptor = accept(socket->_fileDescriptor, NULL, NULL);

    if (incommingSocket->_fileDescriptor == -1) {
      return SMWUnixServerSocketConnectErrorBadIncommingSocket;
    }

    connect(incommingSocket);
    int handleDataResult = handle_data_from_incomming_socket(incommingSocket, bufferSize, data);
    close(incommingSocket);
    smw_unix_server_socket_free(incommingSocket);
    if (handleDataResult < 0) {
      return SMWUnixServerSocketConnectErrorBadData;
    }
  }

  return SMWUnixServerSocketConnectErrorNone;

}

