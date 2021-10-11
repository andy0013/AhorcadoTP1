/*
 * common_sock.c
 *
 *  Created on: 11 oct. 2021
 *      Author: andres
 */

#include "common_socket.h"

void socket_init(socket_t *self) {
	self->fd = -2;
}

void socket_uninit(socket_t *self) {
	shutdown(self->fd, SHUT_RDWR);
	close(self->fd);
}

static struct addrinfo* addrinfo_server_o_cliente(const char *host,
		const char *port, int hints_flags) {
	struct addrinfo *addr_obtenido;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = hints_flags;
	if ((getaddrinfo(host, port, &hints, &addr_obtenido)) != 0) {
		return NULL;
	}
	return addr_obtenido;
}

int socket_bind_and_listen(socket_t *self, const char *host,
		const char *service) {
	int conectado = 0;
	int conexion_exitosa = -1;
	struct addrinfo *addr_result, *i;
	addr_result = addrinfo_server_o_cliente(NULL, service, FLAG_SERVIDOR);
	int fd = -1;
	for (i = addr_result; i != NULL && conectado == 0; i = i->ai_next) {
		fd = socket(i->ai_family, i->ai_socktype, i->ai_protocol);
		conexion_exitosa = bind(fd, i->ai_addr, i->ai_addrlen);
		if (conexion_exitosa == 0) {
			conectado = 1;
		}
	}
	self->fd = fd;
	if (!conectado) {
		socket_uninit(self);
	}
	freeaddrinfo(addr_result);
	if (conectado) {
		int listening = 0;
		listening = listen(self->fd, 10);
		if (listening == -1) {
			return 1;
		}
	}

	return conexion_exitosa;
}

void socket_accept(socket_t *listener, socket_t *peer) {
	int fd = accept(listener->fd, NULL, NULL);
	peer->fd = fd;
}

int socket_connect(socket_t *self, const char *host, const char *service) {
	int conectado = 0;
	int conexion_exitosa = -1;
	struct addrinfo *addr_obtenido, *i;
	addr_obtenido = addrinfo_server_o_cliente(host, service,
			FLAG_CLIENTE);
	int fd = -1;
	for (i = addr_obtenido; i != NULL && conectado == 0; i = i->ai_next) {
		fd = socket(i->ai_family, i->ai_socktype, i->ai_protocol);
		conexion_exitosa = connect(fd, i->ai_addr, i->ai_addrlen);
		if (conexion_exitosa == 0) {
			conectado = 1;
		}
	}
	self->fd = fd;
	freeaddrinfo(addr_obtenido);
	if (!conectado) {
		socket_uninit(self);
	}
	return conexion_exitosa;
}

ssize_t socket_send(socket_t *self, const char *buffer, size_t bytes_a_enviar) {
	int bytes_enviados = 0;
	int socket_conectado = 1;
	while ((bytes_enviados < bytes_a_enviar) && (socket_conectado) ) {
		ssize_t bytes = 0;
		bytes = send(self->fd, &buffer[bytes_enviados],
				bytes_a_enviar - bytes_enviados,MSG_NOSIGNAL);
		if ((bytes == -1) || (bytes == 0)) {
			socket_conectado = 0;
		}
		bytes_enviados += bytes;
	}
	if(!socket_conectado){
		socket_uninit(self);
	}
	return bytes_enviados;
}

ssize_t socket_receive(socket_t *self, char *buffer, size_t length) {
	int bytes_recibidos = 0;
	int socket_conectado = 1;
	while ((bytes_recibidos < length) && (socket_conectado)) {
		ssize_t bytes = 0;
		bytes = recv(self->fd, &buffer[bytes_recibidos],
				length - bytes_recibidos, 0);
		if ((bytes == -1) || (bytes == 0)) {
			socket_conectado = 0;
			break;
		}
		bytes_recibidos += bytes;
	}
	if(!socket_conectado){
		socket_uninit(self);
	}
	return bytes_recibidos;
}

