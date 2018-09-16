
#ifndef __smw_unix_server_socket_h__
#define __smw_unix_server_socket_h__

#include <sys/socket.h>
#include <sys/un.h>

typedef struct sockaddr_un SocketAddress;

typedef struct {
  int _fileDescriptor;
  SocketAddress *_unixSocket;
} SMWUnixServerSocket;

SMWUnixServerSocket *smw_unix_server_socket_malloc(void);
void smw_unix_server_socket_free(SMWUnixServerSocket *socket);

#endif
