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


#define BUFFER_SIZE 2
#define INPUT_USER 10


typedef struct {
	FILE *file;
	size_t lenFile;
} file_reader_t;



void elCharLeidoPertenece(char* line,char leido){

	char ch;

	char palabraParaInterfaz[(strlen(line)-1)];

	int i = 0;

	ch = line[i];

	while((ch != '\n') & (ch != EOF)){

		ch = line[i];

		if(ch != leido){
			palabraParaInterfaz[i] = '_';
		} else {
			palabraParaInterfaz[i] = leido;
		}

		i++;
	}

	printf("%s",palabraParaInterfaz);

}


int main(void) {


	FILE* file = fopen("words.txt", "r");

	if( file == NULL) {
		return 1;
	}

	char *line = NULL;

	size_t len = 0;

	getline(&line,&len,file);

	printf("%s",line);

	printf("%s","ingrese una letra:");

	char *input = NULL;

	size_t sizeBytes = 0;

	getline(&input,&sizeBytes,stdin);

	int i=0;

	char leido = input[i];

	//STRLEN?
	while((leido != EOF) & (leido != '\n')){

		printf("%c",leido);
		elCharLeidoPertenece(line,leido);

		i++;
		leido = input[i];


	}





	return 0;
}
