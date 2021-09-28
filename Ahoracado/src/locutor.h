/*
 * locutor.h
 *
 *  Created on: 27 sep. 2021
 *      Author: andres
 */

#ifndef LOCUTOR_H_
#define LOCUTOR_H_

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "protocolo.h"


typedef struct {
      char *palabra;
      char *input_user;
      int intentos_usuario;
      int longitud_palabra;
      int termino_la_partida;
      int posicion_de_letra_enviada;
} locutor;


void locutor_inicio(locutor *locutor);

void locutor_preparar_atributos_de_partida(locutor *locutor);

void locutor_recibir_y_actualizar(locutor *locutor, protocolo_t *protocolo);

void locutor_imprimir_informacon_recibida(locutor *locutor);

void locutor_solicitar_y_enviar_letra_del_input_user(locutor *locutor, protocolo_t *protocolo);

int locutor_termino_el_juego_ganamos(locutor *locutor);

int locutor_termino_el_juego_perdimos(locutor *locutor);

#endif /* LOCUTOR_H_ */
