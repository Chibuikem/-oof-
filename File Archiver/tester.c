#include "libraries.h"
#include "constants.h"
#include "sizeprototypes.h"

/*This file contains two functions that
 *prints out the archive and verifies whether
 *an archive contains the files it is supposed to.
 */

void archivePrinter(char *archiveFile){
	
	unsigned int numFiles = 0;
	unsigned int fileSize = 0;
	int i = 0;
	char fileName[MAX_LEN];
	unsigned char fileNameLen;
	unsigned int aSize = archiveSize(archiveFile);
	
	FILE *theArchive = fopen(archiveFile, "rb");
	fread(&numFiles, 4, 1, theArchive);
	
	printf("The archive size is %d bytes.\nThere are %d file(s) in the archive.\n", aSize, numFiles);
	
	while(i<numFiles){
		
		fread(&fileNameLen, 1, 1, theArchive);
		fread(fileName, fileNameLen+1, 1, theArchive);
		fread(&fileSize, 4, 1, theArchive);
		char fileContent[fileSize];
		fread(fileContent, fileSize, 1, theArchive);
	
		printf("%s = %d bytes\n", fileName, fileSize);
		i++;
	}
}
	
void archiveVerifier(char *archiveFile, char** filenames){
	
	unsigned int numFiles = 0;
	unsigned int temp = 4;
	unsigned int fileSize = 0;
	unsigned int i = 0;
	
	FILE *theArchive = fopen(archiveFile, "rb");
	fread(&numFiles, 4, 1, theArchive);
	
	unsigned int aSize = archiveSize(archiveFile);
	//printf("archive: %d\n", aSize);
	
	printf("Buffered.\nNow flushing\n");
	fflush(stdout);
	
	while(i<numFiles){
	
		unsigned char fileNameLen;
		char fileName[MAX_LEN];
	
		fread(&fileNameLen, 1, 1, theArchive);
		int fileNameReal = fileNameLen+1;
		fread(fileName, fileNameReal, 1, theArchive);
	
		fread(&fileSize, 4, 1, theArchive);
		temp = 1+fileNameReal+4+fileSize+temp;
		printf("%d\n", temp);
		char fileContent[fileSize];
		fread(fileContent, fileSize, 1, theArchive);
		
		FILE *unarchivedFile = fopen(fileName, "r");
		
		fseek(unarchivedFile, 0, SEEK_END);
		unsigned int fileSize1 = ftell(unarchivedFile);
		fseek(unarchivedFile, 0, SEEK_SET);
		
		fclose(unarchivedFile);
		
		if((strcmp(fileName, filenames[i]) != 0)||(strlen(fileName) != strlen(filenames[i]))||(fileSize != fileSize1)){
			printf("Archive is corrupted\n");
			exit(1);
		}
		
		i++;
		
		if(aSize != temp){
			unsigned int missingBytes = aSize - temp;
			printf("Archive is missing %d bytes\n", missingBytes);
		}else{
			printf("Archive is missing 0 bytes\nArchive Verified\n");
		}
		
	}
	
}