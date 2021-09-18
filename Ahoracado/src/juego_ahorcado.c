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

}

void juego_preparar_archivo(juego *instancia_de_juego){

	archivo_inicio(&instancia_de_juego->archivo);

	leer_linea_archivo(&instancia_de_juego->archivo);


}

void juego_ejecutar(juego *instancia_de_juego){

	//ACA DEBERIA USAR CONEXION DE UNA PERSONA!

	int longitudDePalabraPorAdivinarEnEsteIntento  = strlen(instancia_de_juego->archivo.line);

	char palabraParaInterfaz[longitudDePalabraPorAdivinarEnEsteIntento];

	juego_inicializar_palabra_actual_para_usuario(palabraParaInterfaz,longitudDePalabraPorAdivinarEnEsteIntento);

	while(instancia_de_juego->intentosDisponibles != 0){

//		int i=0;
//
//		char leido = input[i];
//
//		while((leido != EOF) & (leido != '\n')){
//
//			elCharLeidoPertenece(instancia_de_juego->archivo.line,leido,&instancia_de_juego->intentosDisponibles,palabraParaInterfaz);
//			i++;
//			leido = input[i];
//
//			printf("%s\n",palabraParaInterfaz);
//		}
//
//
//	}


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


