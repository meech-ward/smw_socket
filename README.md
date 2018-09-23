# smw_socket

A C static library that acts as a wrapper around `sys/socket` and exposes a simple api for creating unix domain sockets.

## Usage

run `make` from this directory to compile the library into the `./build` directory.

**Including:**

```c
#include "smw_socket.h"
```

**Compiling:**

```shell
gcc -g path_to_your_app.c ./build/libsmw_socket.a -I./build/ -I./src/ -o your_app_name
```

## Server

1. Create a new server socket.

```c
SMWUnixSocket *socket;
char *filePath = "/tmp/socket_server";
if (smw_unix_server_socket_create(filePath, &socket) != SMWUnixServerSocketConnectErrorNone) {
  fprintf(stderr, "Error creating socket");
}
```

2. Start accepting connections.

```c
void onConnect(SMWUnixSocket *socket) {
  // Accepted a connection
}

void onData(SMWUnixSocket *socket, int dataSize, char *data) {
  // Received data
}

void onClose(SMWUnixSocket *socket) {
  // Connection closed
}

// Start accepting connections
if (smw_unix_server_socket_accept_connections(socket, 100, onConnect, onData, onClose) != SMWUnixServerSocketConnectErrorNone) {
  fprintf(stderr, "Error accepting connections");
}
```

## Client

1. Create a new client socket.

```c
SMWUnixSocket *socket;
char *filePath = "/tmp/socket_server";
if (smw_unix_client_socket_create(filePath, &socket) != SMWUnixClientSocketConnectErrorNone) {
  fprintf(stderr, "Error creating socket\n");
}
```

2. Connect to the server.

```c
void onConnect(SMWUnixSocket *socket) {
  // Connected to server
}

void onData(SMWUnixSocket *socket, int dataSize, char *data) {
  // Received data
}

void onClose(SMWUnixSocket *socket) {
  // Connection closed
}

// Connect to the server
if (smw_unix_client_socket_connect(socket, 100, on_connect, on_data, on_close) != SMWUnixClientSocketConnectErrorNone) {
  fprintf(stderr, "Error creating connection\n");
}
```

## Examples

run `make examples` from this directory to compile the examples into the `./bin` directory.

The examples include a client and server. The server listens for a connection and logs out any data that the client sends.

