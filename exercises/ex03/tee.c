#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){

	char *outputFile;
	int aFlag = 0;
	int i;
	for(i = 0; i < argc; i++){
		if(strcmp(argv[i], "-a") == 0){
			aFlag = 1;
		}
		else{
			outputFile = argv[i];
		}
	}
	FILE *file;
	if(aFlag){
		file = fopen(outputFile, "a");
	}
	else{
		file = fopen(outputFile, "w");
	}
	char in[80];
	int loop = 1;
	while(loop){
		printf("Enter input (type quit to quit):\n");
		fgets(in, 80, stdin);
		if(strstr(in, "quit") != NULL){
			fclose(file);
			loop = 0;
		}
		else{
			fprintf(file, "%s", in);
		}
	}
}



/*
3. Originally I had tried to split up this code into multiple functions and found this difficult. However, once I went back into HFC and reread the chapter, I realized that it could all be done within the main function.
*\

/*
4. The professional code has better documentation and the ability to handle more flags. Furthermore, it has implemented warnings with errors and has an array for the buffer. 
*\