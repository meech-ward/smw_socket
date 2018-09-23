#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smw_unix_socket_send_data.h"

SMWUnixServerSocketSendDataError smw_unix_socket_send_data(
  SMWUnixSocket *socket, 
  int dataSize,
  char *data) {

    if (write(socket->_fileDescriptor, data, dataSize) != dataSize) {
      return SMWUnixServerSocketSendDataErrorIncomplete;
    }

    return SMWUnixServerSocketSendDataErrorNone;
  }

