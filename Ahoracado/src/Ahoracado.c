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


int main(void) {

	juego juego_ahorcado;

	juego_inicio(&juego_ahorcado);

	juego_levantar_dato(&juego_ahorcado);

	juego_preparar_ahorcado(&juego_ahorcado);

	juego_ejecutar(&juego_ahorcado);


	return 0;
}
