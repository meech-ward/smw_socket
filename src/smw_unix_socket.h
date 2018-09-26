
#ifndef __smw_unix_socket_h__
#define __smw_unix_socket_h__

#include <sys/socket.h>
#include <sys/un.h>

typedef struct sockaddr_un SocketAddress;

typedef struct {
  int _fileDescriptor;
  SocketAddress *_unixSocket;
} SMWUnixSocket;

/**
 * Malloc a new SMWUnixSocket.
 * When done with the socket, smw_unix_socket_free should always be called.
 * Never call this directly. See smw_unix_server_socket_create and smw_unix_client_socket_create.
 * 
 * @return A new SMWUnixSocket pointer;
 */
SMWUnixSocket *smw_unix_socket_malloc(void);

/**
 * free a SMWUnixSocket.
 * The inverse of smw_unix_socket_malloc.
 * Never call this directly. See smw_unix_socket_close.
 * 
 * @param socket The socket to free.
 */
void smw_unix_socket_free(SMWUnixSocket *socket);

#endif
