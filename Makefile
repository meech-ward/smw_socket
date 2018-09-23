CC = gcc
CFLAGS= -g -I./build/ -I./src/ -Wall

SOURCES=$(wildcard src/*.c) 
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

# TEST_SRC=$(wildcard tests/*_tests.c)
# TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/libsmw_socket.a

all: $(TARGET) 

$(TARGET): CFLAGS += -fPIC

$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

build:
	@mkdir -p build
	@mkdir -p bin

examples: all
	$(CC) $(CFLAGS) examples/client.c  $(TARGET) -o bin/client_example
	$(CC) $(CFLAGS) examples/server.c  $(TARGET) -o bin/server_example

clean:
	rm -rf build bin $(OBJECTS) $(TESTS)



 