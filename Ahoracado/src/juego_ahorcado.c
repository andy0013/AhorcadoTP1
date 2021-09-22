/*
 * juego_ahorcado.c
 *
 *  Created on: 17 sep. 2021
 *      Author: andres
 */

#include "juego_ahorcado.h"
#include <string.h>


void juego_inicio(juego *instancia_de_juego){
	instancia_de_juego->intentosDisponibles = 5;
	lector_de_archivo palabras_por_descubrir;
	instancia_de_juego->archivo = palabras_por_descubrir;
	cliente user_servidor;
	instancia_de_juego->cliente_user_servidor = user_servidor;
	palabra palabra_leida;
	instancia_de_juego->palabra_leida = palabra_leida;
	instancia_de_juego->veces_que_gano = 0;
	instancia_de_juego->veces_que_perdio = 0;
}

void juego_levantar_dato(juego *instancia_de_juego){

	archivo_inicio(&instancia_de_juego->archivo);

}


void juego_preparar_ahorcado(juego *instancia_de_juego){

	leer_linea_archivo(&instancia_de_juego->archivo);

	cliente_inicio(&instancia_de_juego->cliente_user_servidor);

	int longitudDePalabraPorAdivinarEnEsteIntento  = (strlen(instancia_de_juego->archivo.line)-1);

	palabra_inicio(&instancia_de_juego->palabra_leida, longitudDePalabraPorAdivinarEnEsteIntento, instancia_de_juego->archivo.line);

}



void juego_ejecutar(juego *instancia_de_juego){

	char input_user;

	while((instancia_de_juego->intentosDisponibles != 0) & (!linea_llego_al_final(&instancia_de_juego->archivo.file))){

		cliente_obtener_input_user(&instancia_de_juego->cliente_user_servidor, &input_user);

		palabra_detectar_char_y_modificar_datos(&instancia_de_juego->palabra_leida,input_user,&instancia_de_juego->intentosDisponibles);

		cliente_mensaje_palabra_actual(instancia_de_juego->palabra_leida.palabra_en_juego);

		if(palabras_leidas_e_construidas_son_iguales(&instancia_de_juego->palabra_leida)) {

			cliente_user_adivino_la_palabra();

			juego_preparar_ahorcado(&(*instancia_de_juego));

			instancia_de_juego->veces_que_gano = instancia_de_juego->veces_que_gano + 1;
		}

	}

	cliente_mensaje_final_del_juego( instancia_de_juego->veces_que_gano , instancia_de_juego->veces_que_perdio);


}


void juego_fin(){


}



