#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smw_unix_socket_close.h"

SMWUnixServerSocketCloseError smw_unix_socket_close(SMWUnixSocket *socket) {
  if (close(socket->_fileDescriptor) == -1) {
    return SMWUnixServerSocketCloseErrorClosing;
  }

  return SMWUnixServerSocketCloseErrorNone;
}
