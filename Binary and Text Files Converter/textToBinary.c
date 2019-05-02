#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void textToBinary(char *inputFile, char *outputFile){
	
	FILE *ifp, *ofp;

	char firstName[256], lastName[256];
	int sID; 
	float gpa;
	
	if(((ifp = fopen(inputFile, "r")) != NULL)&&((ofp = fopen(outputFile, "w")) != NULL)){
		while((fscanf(ifp, "%s %s %d %f\n", firstName, lastName, &sID, &gpa)) != EOF){
			unsigned char firstNameLen = strlen(firstName);
			unsigned char lastNameLen = strlen(lastName);
			fwrite(&firstNameLen, sizeof(firstNameLen), 1, ofp);
			fwrite(firstName, sizeof(char), firstNameLen, ofp);
			fwrite(&lastNameLen, sizeof(lastNameLen), 1, ofp);
			fwrite(lastName, sizeof(char), lastNameLen, ofp);
			fwrite(&sID, sizeof(int), 1, ofp);
			fwrite(&gpa, sizeof(float), 1, ofp);
		}
		fclose(ifp);
		fclose(ofp);
	}else{
		fprintf(stderr, "Couldn't open: %s\n", "input file");
	}	
}
