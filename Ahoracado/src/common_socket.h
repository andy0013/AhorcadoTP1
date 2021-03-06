#ifndef SOCKET_H
#define SOCKET_H

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>


#define FLAG_CLIENTE 0
#define FLAG_SERVIDOR AI_PASSIVE

typedef struct {
	int fd;
} socket_t;

void socket_init(socket_t *self);

void socket_uninit(socket_t *self);

int socket_bind_and_listen(socket_t *self, const char *host,
		const char *service);

void socket_accept(socket_t *listener, socket_t *peer);

int socket_connect(socket_t *self, const char *host, const char *service);

ssize_t socket_send(socket_t *self, const char *buffer, size_t length);

ssize_t socket_receive(socket_t *self, char *buffer, size_t length);

#endif
