#include "prototypes.h"

int main(int argc, char *argv[]){
	
	
	FILE *ifp;
	FILE *ofp;
	long pos;
	int c, d;
	
	if (argc > 4) {
		fprintf(stderr, "Usage: %s ftest file\n", argv[0]); 
		exit(1);
	}
	
	if(strcmp(argv[1], "-t") == 0){
		textToBinary(argv[2], argv[3]);
	}else if(strcmp(argv[1], "-b") == 0){
		binaryToText(argv[2], argv[3]);
	}else if(strcmp(argv[1], "-s") == 0){
		secondForm(argv[2]);		
	}
	
	return 0;
}