#ifndef __smw_unix_server_socket_create_h__
#define __smw_unix_server_socket_create_h__

#include "smw_unix_socket.h"

typedef enum {
  SMWUnixServerSocketCreateErrorNone = 0,
  SMWUnixServerSocketCreateErrorCreatingSocket,
  SMWUnixServerSocketCreateErrorBinding,
  SMWUnixServerSocketCreateErrorAllocatingSocket,
  SMWUnixServerSocketCreateErrorListening
} SMWUnixServerSocketCreateError;

SMWUnixServerSocketCreateError smw_unix_server_socket_create(const char *filePath, SMWUnixSocket **s);

typedef enum {
  SMWUnixClientSocketCreateErrorNone = 0,
  SMWUnixClientSocketCreateErrorCreatingSocket,
  SMWUnixClientSocketCreateErrorBinding,
  SMWUnixClientSocketCreateErrorAllocatingSocket,
  SMWUnixClientSocketCreateErrorListening
} SMWUnixClientSocketCreateError;

SMWUnixClientSocketCreateError smw_unix_client_socket_create(const char *filePath, SMWUnixSocket **s);

#endif