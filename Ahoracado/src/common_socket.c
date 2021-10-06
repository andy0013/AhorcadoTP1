/*

 * socket.c
 *
 *  Created on: 18 sep. 2021
 *      Author: andres
 */

#include "common_socket.h"

void socket_init(socket_t *self) {
	self->fd = 0;
}

void socket_uninit(socket_t *self) {
	close(self->fd);
}

/*
 * Funcion que organiza el getaddrinfo.
 * En esa funcion debemos setear los datos del hints, socktype, flags.
 * Esta infiormacion fue proporcionada en las diapositivas de socket.
 */
static struct addrinfo* _prepare_getaddrinfo(socket_t *self, const char *host,
		const char *service, int flags) {
	struct addrinfo *addr_result;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_TYPE;
	hints.ai_flags = flags;
	if ((getaddrinfo(host, service, &hints, &addr_result)) != 0) {
		return NULL;
	}
	return addr_result;
}

int socket_bind_and_listen(socket_t *self, const char *host,
		const char *service) {
	int binded = 0;
	int connection = -1;
	struct addrinfo *addr_result, *ptr;
	//Si enviamos el host con NULL es localhost
	addr_result = _prepare_getaddrinfo(self, NULL, service, SERVER_FLAGS);
	int fd = -1;
	for (ptr = addr_result; ptr != NULL && binded == 0; ptr = ptr->ai_next) {
		/* Creamos el socket definiendo la familia (deberia ser AF_INET IPv4),
		 el tipo de socket (deberia ser SOCK_STREAM TCP) y el protocolo (0) */
		fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		connection = bind(fd, ptr->ai_addr, ptr->ai_addrlen);
		if (connection == 0) {
			binded = 1;
		}
	}
	self->fd = fd;
	/* Finalmente, la **lista** de direcciones debe ser liberada */
	freeaddrinfo(addr_result);
	if (binded) {
		int listening = 0;
		listening = listen(self->fd, 10);
		if (listening == -1) {
			return 1;
		}
	}

	return connection;
}

void socket_accept(socket_t *listener, socket_t *peer) {
	int fd = accept(listener->fd, NULL, NULL);
	peer->fd = fd;
}

int socket_connect(socket_t *self, const char *host, const char *service) {
	int connection = 0;
	int connection_err = 0;
	struct addrinfo *addr_result, *ptr;
	addr_result = _prepare_getaddrinfo(self, host, service, CLIENT_FLAGS);

	int fd = -1;
	for (ptr = addr_result; ptr != NULL && connection_err == 0;
			ptr = ptr->ai_next) {
		/* Creamos el socket definiendo la familia (deberia ser AF_INET IPv4),
		 el tipo de socket (deberia ser SOCK_STREAM TCP) y el protocolo (0) */
		fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		connection = connect(fd, ptr->ai_addr, ptr->ai_addrlen);
		if (connection == -1) {
			connection_err = 1;
		}
	}
	self->fd = fd;
	/* Finalmente, la **lista** de direcciones debe ser liberada */
	freeaddrinfo(addr_result);
	return connection;
}

ssize_t socket_send(socket_t *self, const char *buffer, size_t length) {
	if (length == 0)
		return 0;
	int all_bytes_sent = 0;
	while (all_bytes_sent < length) {
		ssize_t bytes = 0;
		bytes = send(self->fd, &buffer[all_bytes_sent], length - all_bytes_sent,
				MSG_NOSIGNAL);
		if (bytes == -1) {
			all_bytes_sent = -1;
			break;
		}
		if (bytes == 0)
			break;
		all_bytes_sent += bytes;
	}
	return all_bytes_sent;
}

ssize_t socket_receive(socket_t *self, char *buffer, size_t length) {
	if (length == 0)
		return 0;
	int all_bytes_received = 0;
	while (all_bytes_received < length) {
		ssize_t bytes = 0;
		bytes = recv(self->fd, &buffer[all_bytes_received], length - all_bytes_received, 0);
		if (bytes == -1) {
			all_bytes_received = -1;
			break;
		}
		if (bytes == 0)
			break;
		all_bytes_received += bytes;
	}
	return all_bytes_received;
}

