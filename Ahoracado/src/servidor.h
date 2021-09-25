/*
 * servidor.h
 *
 *  Created on: 22 sep. 2021
 *      Author: andres
 */

#ifndef SERVIDOR_H_
#define SERVIDOR_H_
#include "consola.h"
#include "juego_ahorcado.h"
#include "socket.h"

#define EXITO 0
#define ERROR 1


typedef struct {
      socket_t skt;
} servidor;

int servidor_ejecutar(int argc, char *argv[]);

int servidor_inicio(servidor *servidor_creado, char *port);

void servidor_comunicacion(servidor *servidor_creado,char *argumento_path_archivo);

void servidor_fin(servidor *servidor_creado);

#endif /* SRC_SERVIDOR_H_ */
