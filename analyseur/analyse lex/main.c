#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*
* @param argv[] is a vecteur of string that we will pass the path of the file to analyse
* brief  the main funct will open the file (.snk file)
*
*/

int main(int argc, char *argv[]) {
	int i;char c;
	FILE *file;
	
	
	file = fopen(argv[1],"r");
	if(file == NULL)
	{
		printf("ERROR D'OVERTURE DU FICHIER ");
		exit(0);
	}
	
	//juste un test pour ouvrire le fichier 
	while((c = fgetc(file) ) != EOF)
	{
		printf("%c",c);
	}
	fclose(file);
	return 0;
}
