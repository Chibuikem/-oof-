#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Add sufficient comments to code

void binaryToText(char *inputFile, char *outputFile){
	
	int sID; 
	float gpa;
	char firstName[256], lastName[256];
	
	FILE *finp = fopen(inputFile, "rb");
	FILE *fout = fopen(outputFile, "w");
	
	if((finp != NULL)&&(fout != NULL)){
		
		while(!feof(finp)){
			unsigned char firstNameLen, lastNameLen;
			fread(&firstNameLen, 1, 1, finp);
			fread(firstName, firstNameLen, 1, finp);
			firstName[firstNameLen] = '\0';
			fread(&lastNameLen, 1, 1, finp);
			fread(lastName, lastNameLen, 1, finp);
			lastName[lastNameLen] = '\0';
			fread(&sID, 4, 1, finp);
			fread(&gpa, 4, 1, finp);
			fprintf(fout, "%s %s %d %1.1f\n", firstName, lastName, sID, gpa);
		}
	}

	fclose(finp);
	fclose(fout);
}
