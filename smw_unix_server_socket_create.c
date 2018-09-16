#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smw_unix_server_socket_create.h"

static const int backlog = 5;

int smw_socket_file_descriptor() {
  return socket(AF_UNIX, SOCK_STREAM, 0);
}

void smw_setup_socket_address(SocketAddress *socketAddress, const char *path) {
  memset(socketAddress, 0, sizeof(SocketAddress));
  
  socketAddress->sun_family = AF_UNIX;
  
  strncpy(socketAddress->sun_path, path, sizeof(socketAddress->sun_path) - 1);
}

int smw_bind_socket(int fileDescriptor, SocketAddress *socketAddress) {
  return bind(fileDescriptor, (struct sockaddr *) socketAddress, sizeof(SocketAddress));
}

SMWUnixServerSocketCreateError smw_unix_server_socket_create(const char *filePath, SMWUnixSocket **s) {
  SMWUnixSocket *socket = smw_unix_socket_malloc();

  socket->_fileDescriptor = smw_socket_file_descriptor();
  if (socket->_fileDescriptor == -1) {
    return SMWUnixServerSocketCreateErrorCreatingSocket;
  }

  smw_setup_socket_address(socket->_unixSocket, filePath);

  if (smw_bind_socket(socket->_fileDescriptor, socket->_unixSocket) == -1) {
    return SMWUnixServerSocketCreateErrorBinding;
  }
  
  if (listen(socket->_fileDescriptor, backlog) == -1) {
    return SMWUnixServerSocketCreateErrorListening;
  }
  
  *s = socket;

  return SMWUnixServerSocketCreateErrorNone;
}

