#ifndef __smw_unix_server_socket_connect_h__
#define __smw_unix_server_socket_connect_h__

#include "smw_unix_socket.h"

typedef enum {
  SMWUnixServerSocketConnectErrorNone = 0,
  SMWUnixServerSocketConnectErrorBadIncommingSocket,
  SMWUnixServerSocketConnectErrorBadData
} SMWUnixServerSocketConnectError;

/**
 * Start accepting connections for a unix domain socket server.
 *
 * @param socket The socket that will accept connections. See smw_unix_server_socket_create.
 * @param bufferSize The maximum buffer size that the server will accept when onData is called.
 * @param onConnect A pointer to a function that will be called when a client successfully connects to the server.
 * @param onData A pointer to a function that will be called when a client successfully sends data to the server.
 * @param onClose A pointer to a function that will be called when a client disconnects from the server.
 * @return SMWUnixServerSocketConnectError
 */
SMWUnixServerSocketConnectError smw_unix_server_socket_accept_connections(
  SMWUnixSocket *socket, 
  int bufferSize,
  void (*onConnect)(SMWUnixSocket *socket), 
  void (*onData)(SMWUnixSocket *socket, int dataSize, char *data), 
  void (*onClose)(SMWUnixSocket *socket));

typedef enum {
  SMWUnixClientSocketConnectErrorNone = 0,
  SMWUnixClientSocketConnectErrorConnecting,
  SMWUnixClientSocketConnectErrorBadData
} SMWUnixClientSocketConnectError;


/**
 * Connect to a unix domain socket server.
 *
 * @param socket The socket that will accept connections.
 * @param bufferSize The maximum buffer size that the client will accept when onData is called.
 * @param onConnect A pointer to a function that will be called when the server is successfully connected to.
 * @param onData A pointer to a function that will be called when the server successfully sends data to the client.
 * @param onClose A pointer to a function that will be called when the server disconnects from the client.
 * @return SMWUnixClientSocketConnectError
 */
SMWUnixClientSocketConnectError smw_unix_client_socket_connect(
  SMWUnixSocket *socket,
  int bufferSize,
  void (*onConnect)(SMWUnixSocket *socket), 
  void (*onData)(SMWUnixSocket *socket, int dataSize, char *data), 
  void (*onClose)(SMWUnixSocket *socket));

#endif