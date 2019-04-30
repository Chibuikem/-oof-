#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secondForm(char *inputFile){
	
	int sID, len; 
	float gpa;
	char firstName[256], lastName[256];
	char fn[256], ln[256];
	
	FILE *finp = fopen(inputFile, "rb");
	
	if(finp != NULL){
		while(!feof(finp)){
			
			strcpy(fn, firstName);
			strcpy(ln, lastName);
			
			unsigned char firstNameLen, lastNameLen;
			fread(&firstNameLen, 1, 1, finp);
			fread(firstName, firstNameLen, 1, finp);
			firstName[firstNameLen] = '\0';
			fread(&lastNameLen, 1, 1, finp);
			fread(lastName, lastNameLen, 1, finp);
			lastName[lastNameLen] = '\0';
			fread(&sID, 4, 1, finp);
			fread(&gpa, 4, 1, finp);
			
			if(strlen(fn) > strlen(firstName)){
				printf("Longest full name is: %s %s\n", fn, ln);
				break;
			}
						
			if(strlen(fn) == strlen(firstName)){
				printf("Theres a tie or only one first name\n");
			}
			
		}
	}
}
