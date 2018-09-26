#ifndef __smw_unix_server_socket_create_h__
#define __smw_unix_server_socket_create_h__

#include "smw_unix_socket.h"

/**
 * Any errors that might occur when calling smw_unix_server_socket_create.
 */
typedef enum {
  SMWUnixServerSocketCreateErrorNone = 0, ///< No error occurred. 
  SMWUnixServerSocketCreateErrorCreatingSocket, ///< Could not create the socket file descriptor.
  SMWUnixServerSocketCreateErrorBinding, 
  SMWUnixServerSocketCreateErrorAllocatingSocket,
  SMWUnixServerSocketCreateErrorListening,
  SMWUnixServerSocketCreateErrorRemoving
} SMWUnixServerSocketCreateError;

/**
 * Create a new SMWUnixServerSocket for a server.
 * Always use this method to create a new SMWUnixServerSocket for a server.
 * Make sure you close the socket with smw_unix_socket_close when you're done.
 *
 * @param filePath The path to the unix domain socket.
 * @param s A pointer to a socket pointer that will be initialized and populated.
 * @return SMWUnixServerSocketCreateError
 */
SMWUnixServerSocketCreateError smw_unix_server_socket_create(const char *filePath, SMWUnixSocket **s);

typedef enum {
  SMWUnixClientSocketCreateErrorNone = 0,
  SMWUnixClientSocketCreateErrorCreatingSocket,
  SMWUnixClientSocketCreateErrorBinding,
  SMWUnixClientSocketCreateErrorAllocatingSocket,
  SMWUnixClientSocketCreateErrorListening
} SMWUnixClientSocketCreateError;

/**
 * Create a new SMWUnixServerSocket for a client.
 * Always use this method to create a new SMWUnixServerSocket for a client.
 * Make sure you close the socket with smw_unix_socket_close when you're done.
 *
 * @param filePath The path to the unix domain socket.
 * @param s A pointer to a socket pointer that will be initialized and populated.
 * @return SMWUnixServerSocketCreateError
 */
SMWUnixClientSocketCreateError smw_unix_client_socket_create(const char *filePath, SMWUnixSocket **s);

#endif