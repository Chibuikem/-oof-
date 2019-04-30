#include "libraries.h"
#include "constants.h"

/*This file contains two functions that
 *archives a group of given files and
 *also unarchives a given archive.
 */

void archive(char** filenames, int numFiles, char* archiveName){
	
	FILE *archiveFile = fopen(archiveName, "w");
	unsigned int nFiles = numFiles;
	int i = 0;
	fwrite(&nFiles, 4, 1, archiveFile); //Write the number of files being archived
	
	while(i<nFiles){
		
		FILE *theFile = fopen(filenames[i], "r");
		unsigned char fileNameLen = strlen(filenames[i]);
		
		fseek(theFile, 0, SEEK_END);
		unsigned int fileSize = ftell(theFile);
		fseek(theFile, 0, SEEK_SET);
		
		char fileContent[fileSize];
		
		fwrite(&fileNameLen, 1, 1, archiveFile); //Write the length of the filename
		fwrite(filenames[i], fileNameLen+1, 1, archiveFile); //Write the filename
		fwrite(&fileSize, 4, 1, archiveFile); //Write the filesize
		fread(fileContent, fileSize, 1, theFile); //Read the number of filesize bytes into fileContent
		fwrite(fileContent, fileSize, 1, archiveFile); //Write the file contents
		fclose(theFile);
		i++;
	}
	fclose(archiveFile);
}
void unarchive(char* archiveFile){
	
	FILE *theArchive = fopen(archiveFile, "rb");
	unsigned int numFiles = 0;
	unsigned int fileSize = 0;
	fread(&numFiles, 4, 1, theArchive);
	int i = 0;
	
	while(i<numFiles){
	
		unsigned char fileNameLen;
		char fileName[MAX_LEN];
	
		fread(&fileNameLen, 1, 1, theArchive);
		fread(fileName, fileNameLen+1, 1, theArchive);
		fread(&fileSize, 4, 1, theArchive);
		char fileContent[fileSize];
		fread(fileContent, fileSize, 1, theArchive);
	
		FILE *unarchivedFile = fopen(fileName, "w");
	
		fwrite(fileContent, fileSize, 1, unarchivedFile);
		fclose(unarchivedFile);
		i++;
	}
	fclose(theArchive);
}