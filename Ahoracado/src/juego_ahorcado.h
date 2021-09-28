/*
 * game_ahorcado.h
 *
 *  Created on: 17 sep. 2021
 *      Author: andres
 */

#include "lector_de_archivo.h"
#include "palabra.h"
#include <string.h>
#include "consola.h"

#ifndef JUEGO_AHORCADO_H_
#define JUEGO_AHORCADO_H_

typedef struct {
	int intentos_juego;
	int intentos_disponibles;
	lector_de_archivo archivo;
	consola *consola_user_servidor;
	palabra palabra_leida;
	int veces_que_gano;
	int veces_que_perdio;
} juego;

/*
 *  Inicia las variables del TDA juego.
 *  Recibe la consola para conectarse con el cliente.
 *  Y recibe los intentos cargados por argumento.
 */
void juego_inicio(juego *instancia_de_juego, consola *cliente_user_servidor,
		int intentos_juego);

/*
 * Hace inicio del archivo.
 */
void juego_levantar_dato(juego *instancia_de_juego,
		char *argumento_path_archivo);

/*
 * Prepara las variables del TDA.
 * Para una ejecucion del juego.
 * (Lee el archivo, carga la palabra.)
 */
void juego_preparar_ahorcado(juego *instancia_de_juego);

/*
 * Haciendo uso de las variables del TDA.
 * Maneja la logica del juego. Conectar User - Perdir palabra - Moficar valores..
 */
void juego_ejecutar(juego *instancia_de_juego);

/*
 * Libera los recursos solicitados en el TDA juego.
 */
void juego_fin(juego *instancia_de_juego);

#endif /* JUEGO_AHORCADO_H_ */
