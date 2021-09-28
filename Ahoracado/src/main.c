/*
 * main.c
 *
 *  Created on: 23 sep. 2021
 *      Author: andres
 */

#include <stdio.h>
#include <string.h>
#include "servidor.h"
#include "cliente.h"

#define SERVIDOR "server"
#define CLIENTE "client"

int main(int argc, char *argv[]) {
	int r = 0;
	if ((argc == 4) && (strstr(argv[0], SERVIDOR) != NULL)) {
		r = servidor_ejecutar(argc, argv);
	} else if ((argc == 3) && (strstr(argv[0], CLIENTE) != NULL)) {
		r = cliente_ejectuar(argc, argv);
	} else {
		return r;
	}
}
