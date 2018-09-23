
#ifndef __smw_unix_socket_h__
#define __smw_unix_socket_h__

#include <sys/socket.h>
#include <sys/un.h>

typedef struct sockaddr_un SocketAddress;

typedef struct {
  int _fileDescriptor;
  SocketAddress *_unixSocket;
} SMWUnixSocket;

SMWUnixSocket *smw_unix_socket_malloc(void);
void smw_unix_socket_free(SMWUnixSocket *socket);

#endif
