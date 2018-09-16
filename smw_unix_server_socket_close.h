#ifndef __smw_unix_server_socket_close_h__
#define __smw_unix_server_socket_close_h__

#include "smw_unix_socket.h"

typedef enum {
  SMWUnixServerSocketCloseErrorNone = 0,
  SMWUnixServerSocketCloseErrorClosing
} SMWUnixServerSocketCloseError;

SMWUnixServerSocketCloseError smw_unix_server_socket_close(SMWUnixSocket *socket);

#endif