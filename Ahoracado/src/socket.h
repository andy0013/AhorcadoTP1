#ifndef SOCKET_H
#define SOCKET_H

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>


#define _POSIX_C_SOURCE 200112L
#define FAMILY AF_INET
#define SOCK_TYPE SOCK_STREAM
#define CLIENT_FLAGS 0
#define SERVER_FLAGS AI_PASSIVE



typedef struct {
    int fd;
} socket_t;

void socket_init(socket_t *self);

void socket_uninit(socket_t *self);

int socket_bind_and_listen(socket_t *self,
                            const char *host,
                            const char *service);

void socket_accept(socket_t *listener, socket_t *peer);

int socket_connect(socket_t *self, const char *host, const char *service);

ssize_t socket_send(socket_t *self, const char *buffer, size_t length);

ssize_t socket_receive(socket_t *self, char *buffer, size_t length);

#endif
