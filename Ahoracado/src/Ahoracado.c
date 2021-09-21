/*
 ============================================================================
 Name        : Ahoracado.c
 Author      : Andres
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego_ahorcado.h"



//void elCharLeidoPertenece(char* line,char leido,int *intentos, char *palabraParaInterfaz){
//
//	char ch;
//
//	int userFalloLetra = 1;
//
//	for(int i = 0 ; i < strlen(line) ; i++ ){
//		ch = line[i];
//
//		if(ch == leido){
//			palabraParaInterfaz[i] = leido;
//			userFalloLetra = 0;
//		}
//
//	}
//
//	if(userFalloLetra == 1){
//		*intentos = *intentos - 1 ;
//	}
//
//
//}
//

int main(void) {

	juego juego_ahorcado;

	juego_inicio(&juego_ahorcado);

	juego_levantar_dato(&juego_ahorcado);

	juego_preparar_ahorcado(&juego_ahorcado);

	juego_ejecutar(&juego_ahorcado);

//	FILE* file = fopen("words.txt", "r");
//
//	if( file == NULL) {
//		return 1;
//	}
//
//	char *line = NULL;
//
//	size_t len = 0;
//
//	getline(&line,&len,file);
//
//	puts(line);
//
//	getline(&line,&len,file);
//
//	puts(line);
//
//	getline(&line,&len,file);
//
//	puts(line);
//
//	getline(&line,&len,file);
//
//	puts(line);
//
	//
//	int intentos = 5;
//
//	char palabraParaInterfaz[strlen(line)];
//
//
//	for (int i = 0 ; i < strlen(line) ; i++  ){
//
//		palabraParaInterfaz[i] = '_';
//
//	}
//
//	while(intentos != 0){
//
//		char *input = NULL;
//
//		size_t sizeBytes = 0;
////
//		while((leido != EOF) & (leido != '\n')){
//
//			elCharLeidoPertenece(line,leido,&intentos,palabraParaInterfaz);
//			i++;
//			leido = input[i];
//
//			printf("%s\n",palabraParaInterfaz);
//		}
//
//
//	}
//
//
//

	return 0;
}
