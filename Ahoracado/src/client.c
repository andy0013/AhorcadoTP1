/*
 * main.c
 *
 *  Created on: 23 sep. 2021
 *      Author: andres
 */

#include <stdio.h>
#include <string.h>
#include "client_cliente.h"

#define SERVIDOR "server"
#define CLIENTE "client"

int main(int argc, char *argv[]) {
	int r = 0;
	if ((argc == 3) && (strstr(CLIENTE, CLIENTE) != NULL)) {
		r = cliente_ejectuar(argc, argv);
	}
	return r;
}

