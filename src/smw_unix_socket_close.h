#ifndef __smw_unix_server_socket_close_h__
#define __smw_unix_server_socket_close_h__

#include "smw_unix_socket.h"

typedef enum {
  SMWUnixServerSocketCloseErrorNone = 0,
  SMWUnixServerSocketCloseErrorClosing
} SMWUnixServerSocketCloseError;

/**
 * Close and free a SMWUnixServerSocket.
 * Always use this method to close the socket when you're done using it.
 *
 * @param socket A socket pointer that will be freed.
 * @return SMWUnixServerSocketCloseError
 */
SMWUnixServerSocketCloseError smw_unix_socket_close(SMWUnixSocket *socket);

#endif