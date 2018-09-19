#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "smw_unix_socket_create.h"

static const int backlog = 5;

int smw_socket_file_descriptor() {
  return socket(AF_UNIX, SOCK_STREAM, 0);
}

void smw_setup_socket_address(SocketAddress *socketAddress, const char *path) {
  memset(socketAddress, 0, sizeof(SocketAddress));
  
  socketAddress->sun_family = AF_UNIX;
  
  strncpy(socketAddress->sun_path, path, sizeof(socketAddress->sun_path) - 1);
}

int smw_remove_socket_path(const char *path) {
  if (remove(path) == -1 && errno != ENOENT) {
    return -1;
  }
  return 0;
}

int smw_bind_socket(int fileDescriptor, SocketAddress *socketAddress) {
  return bind(fileDescriptor, (struct sockaddr *) socketAddress, sizeof(SocketAddress));
}

int smw_connect_socket(int fileDescriptor, SocketAddress *socketAddress) {
  return connect(fileDescriptor, (struct sockaddr *) socketAddress, sizeof(SocketAddress));
}

SMWUnixServerSocketCreateError smw_unix_server_socket_create(const char *filePath, SMWUnixSocket **s) {
  SMWUnixSocket *socket = smw_unix_socket_malloc();

  socket->_fileDescriptor = smw_socket_file_descriptor();
  if (socket->_fileDescriptor == -1) {
    return SMWUnixServerSocketCreateErrorCreatingSocket;
  }

  smw_setup_socket_address(socket->_unixSocket, filePath);

  if (smw_remove_socket_path(filePath) == -1) {
    return SMWUnixServerSocketCreateErrorRemoving;
  }

  if (smw_bind_socket(socket->_fileDescriptor, socket->_unixSocket) == -1) {
    return SMWUnixServerSocketCreateErrorBinding;
  }
  
  if (listen(socket->_fileDescriptor, backlog) == -1) {
    return SMWUnixServerSocketCreateErrorListening;
  }
  
  *s = socket;

  return SMWUnixServerSocketCreateErrorNone;
}

SMWUnixClientSocketCreateError smw_unix_client_socket_create(const char *filePath, SMWUnixSocket **s) {
  SMWUnixSocket *socket = smw_unix_socket_malloc();

  socket->_fileDescriptor = smw_socket_file_descriptor();
  if (socket->_fileDescriptor == -1) {
    return SMWUnixClientSocketCreateErrorCreatingSocket;
  }

  smw_setup_socket_address(socket->_unixSocket, filePath);
  
  *s = socket;

  return SMWUnixClientSocketCreateErrorNone;
}

