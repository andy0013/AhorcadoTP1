/*

 * socket.c
 *
 *  Created on: 18 sep. 2021
 *      Author: andres
 */

#include "socket.h"

void socket_init(socket_t *self){

}


void socket_uninit(socket_t *self){

}


/*
 * Funcion que organiza el getaddrinfo.
 * En esa funcion debemos setear los datos del hints, socktype, flags.
 * Se llevo a una funcion para no reescribir codigo
 * Esta infiormacion fue proporcionada en las diapositivas de socket.
 */
static struct addrinfo *prepare_getaddrinfo(socket_t *self, const char *host, const char *service, int flags) {
    struct addrinfo *addr_result;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_TYPE;
    hints.ai_flags = flags;
    int r = 0;
    if ((r = getaddrinfo(host, service, &hints, &addr_result)) != 0) {
    	//printf("error %s:",gai_sterror(r))
        return NULL;
    }
    return addr_result;
}





int socket_bind_and_listen(socket_t *self,
                            const char *host,
                            const char *service){
	int binded = 0;
	int connection = -1;
	int listening = 0;
	struct addrinfo *addr_result,*ptr;

	//Si enviamos el host con NULL es localhost
	addr_result = prepare_getaddrinfo(self, NULL, service, SERVER_FLAGS);
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
	if(binded){
		listening = listen(self->fd,10);
		if(listening == -1){
			return 1;
		}
	}
	return 0;
}


void socket_accept(socket_t *listener, socket_t *peer){
	 int fd = accept(listener->fd, NULL, NULL);
	 peer->fd=fd;
}

int socket_connect(socket_t *self, const char *host, const char *service){
	int connection = 0;
	int connected = 0;
    struct addrinfo *addr_result,*ptr;
    addr_result = prepare_getaddrinfo(self, host, service, CLIENT_FLAGS);

	int fd = -1;
	for (ptr = addr_result; ptr != NULL && connected == 0; ptr = ptr->ai_next) {
		/* Creamos el socket definiendo la familia (deberia ser AF_INET IPv4),
		 el tipo de socket (deberia ser SOCK_STREAM TCP) y el protocolo (0) */
		fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		connection = connect(fd, ptr->ai_addr, ptr->ai_addrlen);
		if (connection == -1) {
			connected = 1;
		}
	}
	self->fd = fd;
	/* Finalmente, la **lista** de direcciones debe ser liberada */
	freeaddrinfo(addr_result);

	return connection;

}



ssize_t socket_send(socket_t *self, const char *buffer, size_t length){
    if (length == 0) return 0;
    int send_bytes = length;
    int all_bytes_sended = 0;
    ssize_t bytes = 0;
    //falta preparar para binario, y con protocolo.
     // guardo bytes
    while (all_bytes_sended < length) {
        bytes = send(self->fd, &buffer[all_bytes_sended],
                     send_bytes, MSG_NOSIGNAL);
        if (bytes == -1) {
            all_bytes_sended = -1;
            break;
        }else if (bytes == 0){
            break;
        }
        all_bytes_sended += bytes;
        send_bytes -= bytes;
    }
    return all_bytes_sended;
}


ssize_t socket_receive(socket_t *self, char *buffer, size_t length){
    if (length == 0) return 0;
    int recv_bytes = length;
    int all_bytes_received = 0;
    ssize_t bytes = 0;
    //falta preparar para binario, y con protocolo.
    // guardo bytes
    while (all_bytes_received < length) {
        bytes = recv(self->fd, &buffer[all_bytes_received],
                     recv_bytes, 0);
        if (bytes == -1) {
            all_bytes_received = -1;
            break;
        }
        if (bytes == 0)
            break;
        all_bytes_received += bytes;
        recv_bytes -= bytes;
    }
    return all_bytes_received;
}



