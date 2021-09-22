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
}

void juego_levantar_dato(juego *instancia_de_juego){

	archivo_inicio(&instancia_de_juego->archivo);

}


void juego_preparar_ahorcado(juego *instancia_de_juego){

	leer_linea_archivo(&instancia_de_juego->archivo);

	cliente_inicio(&instancia_de_juego->cliente_user_servidor);

	int longitudDePalabraPorAdivinarEnEsteIntento  = (strlen(instancia_de_juego->archivo.line)-1);

	palabra_inicio(&instancia_de_juego->palabra_leida, 0 , longitudDePalabraPorAdivinarEnEsteIntento, instancia_de_juego->archivo.line);

}

void juego_ejecutar(juego *instancia_de_juego){

	char input_user;

	cliente_obtener_input_user(&instancia_de_juego->cliente_user_servidor, &input_user);

	while(instancia_de_juego->intentosDisponibles != 0){

		elCharLeidoPertenece(instancia_de_juego->archivo.line,input_user,&instancia_de_juego->intentosDisponibles,instancia_de_juego->palabra_leida.palabra_en_juego,&instancia_de_juego->palabra_leida.cantidad_de_letras);

		printf("%s\n", instancia_de_juego->palabra_leida.palabra_en_juego);

		if(instancia_de_juego->palabra_leida.longitud == instancia_de_juego->palabra_leida.cantidad_de_letras) {

			cliente_user_adivino_la_palabra();

			juego_preparar_ahorcado(&(*instancia_de_juego));

			cliente_obtener_input_user(&instancia_de_juego->cliente_user_servidor, &input_user);

		}

		cliente_obtener_input_siguiente_user(&instancia_de_juego->cliente_user_servidor, &input_user);
	}


}

void elCharLeidoPertenece(char* line,char leido,int *intentos, char *palabraParaInterfaz,int *letras_adivinadas){

	char ch;

	int userFalloLetra = 1;

	for(int i = 0 ; i < (strlen(line)-1) ; i++ ){
		ch = line[i];

		if(ch == leido){
			palabraParaInterfaz[i] = leido;
			userFalloLetra = 0;
			*letras_adivinadas = *letras_adivinadas + 1;
		}
	}

	if(userFalloLetra == 1){
		*intentos = *intentos - 1;
	}


}




void juego_fin(){


}



