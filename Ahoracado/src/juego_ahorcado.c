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

}

void juego_preparar_ahorcado(juego *instancia_de_juego){

	archivo_inicio(&instancia_de_juego->archivo);

	leer_linea_archivo(&instancia_de_juego->archivo);

	cliente_inicio(&instancia_de_juego->cliente_user_servidor);


}

void juego_ejecutar(juego *instancia_de_juego){

	int longitudDePalabraPorAdivinarEnEsteIntento  = strlen(instancia_de_juego->archivo.line);

	char palabraParaInterfaz[longitudDePalabraPorAdivinarEnEsteIntento];

	char input_user;

	juego_inicializar_palabra_actual_para_usuario(palabraParaInterfaz,longitudDePalabraPorAdivinarEnEsteIntento);

	cliente_obtener_input_user(&instancia_de_juego->cliente_user_servidor, &input_user);

	while(instancia_de_juego->intentosDisponibles != 0){

		elCharLeidoPertenece(instancia_de_juego->archivo.line,input_user,&instancia_de_juego->intentosDisponibles,palabraParaInterfaz);

		printf("%s\n",palabraParaInterfaz);

		cliente_obtener_input_siguiente_user(&instancia_de_juego->cliente_user_servidor, &input_user);
	}


}

void elCharLeidoPertenece(char* line,char leido,int *intentos, char *palabraParaInterfaz){

	char ch;

	int userFalloLetra = 1;

	for(int i = 0 ; i < strlen(line) ; i++ ){
		ch = line[i];

		if(ch == leido){
			palabraParaInterfaz[i] = leido;
			userFalloLetra = 0;
		}

	}

	if(userFalloLetra == 1){
		*intentos = *intentos - 1 ;
	}


}

void juego_fin(){


}


void juego_inicializar_palabra_actual_para_usuario(char *palabraParaInterfaz, int longitudDePalabraPorAdivinarEnEsteIntento){

	for (int i = 0 ; i < longitudDePalabraPorAdivinarEnEsteIntento ; i++){

		palabraParaInterfaz[i] = '_';
	}

}


