/*
 * cliente.h
 *
 *  Created on: 24 sep. 2021
 *      Author: andres
 */

#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "socket.h"
#include "protocolo.h"

#define EXITO 0
#define ERROR 1

typedef struct {
      protocolo_t *protocolo;
} cliente;

int cliente_execute(int argc, char *argv[]);

int cliente_inicio(cliente *servidor_creado, char *port);

void cliente_comunicacion(cliente *servidor_creado, char *argumento_path_archivo);

void cliente_fin(cliente *servidor_creado);



#endif /* SRC_CLIENTE_H_ */
