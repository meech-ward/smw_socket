#ifndef __smw_unix_socket_send_data_h__
#define __smw_unix_socket_send_data_h__

#include "smw_unix_socket.h"

typedef enum {
  SMWUnixServerSocketSendDataErrorNone = 0,
  SMWUnixServerSocketSendDataErrorIncomplete
} SMWUnixServerSocketSendDataError;

SMWUnixServerSocketSendDataError smw_unix_socket_send_data(
  SMWUnixSocket *socket, 
  int dataSsize,
  char *data);

#endif