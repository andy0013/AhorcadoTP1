/*
 * locutor.h
 *
 *  Created on: 27 sep. 2021
 *      Author: andres
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "common_protocolo.h"

#ifndef LOCUTOR_H_
#define LOCUTOR_H_

typedef struct {
	char *palabra;
	char *input_user;
	int intentos_usuario;
	int longitud_palabra;
	int termino_la_partida;
	int posicion_de_letra_enviada;
} locutor;

/*
 * Incializa las variables que queremos guardar valores, para imprimir luego
 * en el TDA.
 */
void locutor_inicio(locutor *locutor);

/*
 *  Inicializa las variables en valores 0 - NULL.
 *  De las variables que se van a ir modificando dependiendo de lo
 *  que retorne el SERVIDOR.
 */
void locutor_preparar_atributos_de_partida(locutor *locutor);

/*
 * Utiliza el protocolo para recibir variables del SERVIDOR.
 * Guarda esos valores en las variables que inicializamos
 * en "void locutor_preparar_atributos_de_partida(locutor *locutor);"
 */
void locutor_recibir_y_actualizar(locutor *locutor, protocolo_t *protocolo);

/*
 * Imprime la informacion del TDA locutor.
 * Informacion que fue previamente setteada.
 */
void locutor_imprimir_informacon_recibida(locutor *locutor);

/*
 * Se ocupa de modificar las variables que obtuvimos al hacer "locutor_inicio"
 * Es el input del usuario.
 * Junto con funciones no accesibles desde afuera del TDA, se ocupa de la logica para cuando el usuario
 * ingresa mas de una letra, y las envia correctamente, de a 1.
 */
void locutor_solicitar_y_enviar_letra_del_input_user(locutor *locutor,
		protocolo_t *protocolo);

/*
 * Retorna 1 si termino el juego, por GANAR.
 * Si perdimos, aunque haya terminado la partida, este metodo retorna 0.
 */
int locutor_termino_el_juego_ganamos(locutor *locutor);

/*
 *Retorna 1 si termina el juego, por PERDER.
 *Si ganamos, aunque haya terminado la partida, este metodo retorna 0;
 */
int locutor_termino_el_juego_perdimos(locutor *locutor);

void locutor_obtener_letra_del_input_user(locutor *locutor, char *letra);

/*
 *  Libera recursos pedidos en el TDA locutor.
 */
void locutor_fin(locutor *locutor);

#endif /* LOCUTOR_H_ */
