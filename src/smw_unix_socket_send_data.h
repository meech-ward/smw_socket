#ifndef __smw_unix_socket_send_data_h__
#define __smw_unix_socket_send_data_h__

#include "smw_unix_socket.h"

typedef enum {
  SMWUnixServerSocketSendDataErrorNone = 0,
  SMWUnixServerSocketSendDataErrorIncomplete
} SMWUnixServerSocketSendDataError;

/**
 * Send data over a unix domain socket.
 *
 * @param socket The socket to send data to.
 * @param dataSize The size of the data to be sent, make sure this includes the terminating character.
 * @param data A char buffer to be sent.
 * @return SMWUnixServerSocketConnectError
 */
SMWUnixServerSocketSendDataError smw_unix_socket_send_data(
  SMWUnixSocket *socket, 
  int dataSize,
  char *data);

#endif