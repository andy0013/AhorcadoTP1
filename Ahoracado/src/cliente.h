/*
 * cliente.h
 *
 *  Created on: 24 sep. 2021
 *      Author: andres
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "protocolo.h"
#include "locutor.h"


#ifndef CLIENTE_H_
#define CLIENTE_H_


#define EXITO 0
#define ERROR 1

typedef struct {
      protocolo_t *protocolo;
} cliente;

/*
 * Ejecuta el flujo de iniciar el cliente.
 * Conectarte con el servidor.
 * Comunicarte.
 * Finalizar la comunicacion.
 * Retorna: 1 en caso de ERROR, 0 en caso de EXITO.
 */
int cliente_ejectuar(int argc, char *argv[]);

/*
 * Inicia el protocolo de nuestro TDA.
 * Retorna: 0 en caso de EXITO, 1 en caso de error.
 */
int cliente_inicio(cliente *servidor_creado, char *host, char *port);

/*
 * Se ocupa de comunicarse con el usuario, en el juego.
 * Inicia el TDA Locutor, que se ocupa del flujo de la partida.
 * Y de solicitar valores al usuario.
 */
void cliente_comunicacion(cliente *servidor_creado, char *argumento_path_archivo);

/*
 * Libera los recursos solicitados en el TDA.
 */
void cliente_fin(cliente *servidor_creado);



#endif /* SRC_CLIENTE_H_ */
