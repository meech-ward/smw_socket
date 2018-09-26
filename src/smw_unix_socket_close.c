#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smw_unix_socket_close.h"

SMWUnixServerSocketCloseError smw_unix_socket_close(SMWUnixSocket *socket) {
  int closeResult = close(socket->_fileDescriptor);

  smw_unix_socket_free(socket);

  if (closeResult == -1) {
    return SMWUnixServerSocketCloseErrorClosing;
  }

  return SMWUnixServerSocketCloseErrorNone;
}

