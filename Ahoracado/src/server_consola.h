/*
 * cliente.h
 *
 *  Created on: 18 sep. 2021
 *      Author: andres
 */

#ifndef COLSOLA_H_
#define COLSOLA_H_

#include <stdio.h>
#include <string.h>
#include "common_protocolo.h"

typedef struct {
	char *input;

	int se_cargo_input;

	int posicion_letra_leida;

	protocolo_t *servidor_a_user;
} consola;

/*
 * Iniciamos los valores de las variables del TDA.
 * Recibimos por parametro una de las variables (protocolo_t)
 */
void consola_inicio(consola *instancia_de_consola
		, protocolo_t *servidor_a_user);

/*
 * Solicitamos al usuario que nos envie la letra para el juego.
 */
void consola_obtener_input_user(consola *instancia_de_consola
		, char *char_user);

/*
 * En caso de que el usuario nos envie mas de una letra.
 * Este metodo maneja la logica (Utilizado
 * para probar en local, el juego a travez de stdin)
 */
void consola_obtener_input_siguiente_user(consola *instancia_de_consola,
		char *char_user);

/*
 * Se encarga de aceptar un nuevo cliente.
 * Continuando con el flujo del juego.
 */
void consola_conectar_usuario_de_ser_necesario(consola *instancia_de_consola);

/*
 * Finaliza la conexion con el socket del cliente conectado actualmente.
 */
void consola_finalizar_partida_cliente_actual(consola *instancia_de_consola);

/*
 * Envia al cliente, la palabra en sus distintos estados. EJ
 * "____" . "c___" . "ca_a" - "casa"
 */
void consola_mensaje_palabra_actual(consola *instancia_de_consola,
		char *palabra_actual, int *intentos, int flag_estado);

/*
 * Libera los recursos del TDA consola.
 */
void consola_fin(consola *instancia_de_consola);

#endif /* CLIENTE_H_ */
