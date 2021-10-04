/*
 * main.c
 *
 *  Created on: 23 sep. 2021
 *      Author: andres
 */

#include <stdio.h>
#include <string.h>
#include "server_servidor.h"

#define SERVIDOR "server"
#define CLIENTE "client"

int main(int argc, char *argv[]) {
	int r = 0;
	if ((argc == 4) && (strstr(SERVIDOR, SERVIDOR) != NULL)) {
		r = servidor_ejecutar(argc, argv);
	}
	return r;
}

