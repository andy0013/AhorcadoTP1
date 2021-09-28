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
    int argc2 = 3;
    char *argv2[] = {"./cliente","0.0.0.0","7777"};
    int r = 0;
    if((argc2 == 4) & (strstr(argv2[0],SERVIDOR) != NULL)){
    	servidor_execute(argc, argv);
    }else if((argc2 == 3) & (strstr(argv2[0],CLIENTE) != NULL)){
     	cliente_execute(argc, argv);
    }else{
    	return r;
    }
}
