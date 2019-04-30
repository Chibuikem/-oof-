#include "libraries.h"
#include "constants.h"

/*This file contains a single function
 *to compute the size of a given archive.
 */

unsigned int archiveSize(char* archiveFile){
	
	//can i put the archive file into a char and use strlen?
	
	FILE *theArchive = fopen(archiveFile, "rb");
	fseek(theArchive, 0, SEEK_END);
	unsigned int archiveSize = ftell(theArchive);
	fseek(theArchive, 0, SEEK_SET);
	fclose(theArchive);
	
	return archiveSize;
}