#ifndef __smw_unix_server_socket_create_h__
#define __smw_unix_server_socket_create_h__

#include "smw_unix_server_socket.h"

typedef enum {
  SMWUnixServerSocketCreateErrorNone = 0,
  SMWUnixServerSocketCreateErrorCreatingSocket,
  SMWUnixServerSocketCreateErrorBinding,
  SMWUnixServerSocketCreateErrorAllocatingSocket,
  SMWUnixServerSocketCreateErrorListening
} SMWUnixServerSocketCreateError;

SMWUnixServerSocketCreateError smw_unix_server_socket_create(const char *filePath, SMWUnixServerSocket **s);

#endif