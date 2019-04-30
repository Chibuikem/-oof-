#include "libraries.h"
#include "constants.h"
#include "archiverprototypes.h"
#include "testerprototypes.h"
#include "sizeprototypes.h"


int main(int argc, char *argv[]){
	
	//FILE *stderr;
	//Open stderr on this line
	int i = 3;
	int j;
	int numFiles = argc - i;
	char *filenames[numFiles];
	
	for(j=0; j<numFiles; j++){
		filenames[j] = argv[j+3];
	}
	
	if(strcmp(argv[1], "-a") == 0){
		if(argc > i){
			archive(filenames, numFiles, argv[2]);
		}else{
			printf("Incorrect number of arguments for specified flag.\n");
		}
	}else if(strcmp(argv[1], "-u") == 0){
		if(argc == i){
			unarchive(argv[2]);
		}else{
			printf("Incorrect number of arguments for specified flag.\n");
		}
	}else if(strcmp(argv[1], "-l") == 0){
		if(argc == i){
			archivePrinter(argv[2]);
		}else{
			printf("Incorrect number of arguments for specified flag.\n");
		}
	}else if(strcmp(argv[1], "-v") == 0){
		if(argc > i){
			archiveVerifier(argv[2], filenames);
		}
	}else{
		printf("Incorrect flag.\n");
	}
	
	return 0;
}