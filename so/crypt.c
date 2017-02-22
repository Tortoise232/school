#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define STATUS_SUCCESS			0
#define STATUS_INVALID_USAGE		-1
#define STATUS_INVALID_PARAMETER	-2
#define STATUS_INVALID_FILE		-3
typedef struct _GLOBAL_DATA
{
    int OperationInProgress;
    char FileName[256];
    char OutFileName[256];
    char Key;
} GLOBAL_DATA, *PGLOBAL_DATA;
GLOBAL_DATA gData = {0};
void PrintUsage(void);
int ReadParams(   PGLOBAL_DATA data   );



int main(int argc, char **argv)

{
    int status = 0;
    FILE* fIn = NULL;
    FILE* fOut = NULL;
    memset(&gData, 0, sizeof(gData));
    status = ReadParams(&gData);
    if (status != STATUS_SUCCESS)
    {
	printf("Error processing parameters!\n");
	return status;
    }
    printf("Start working on file: %s using key: %c\n", gData.FileName, gData.Key);
    gData.OperationInProgress = 1;
    if (fork() == 0)
    {
	printf("Worker process got source file: %s destination file: %s and key %c\n", gData.FileName, gData.OutFileName, gData.Key);
	fIn = fopen(gData.FileName, "r");
        if (fIn != NULL)
	{
	    struct stat st;
	    if (0 == stat(gData.FileName, &st))
	    {
		char* buffer = malloc(st.st_size);
		if (buffer != NULL)
		{
		    size_t i = 0;
		    size_t readBytes = 0;		
		    readBytes = fread(buffer, 1, st.st_size, fIn);
			for (i = 0; i < readBytes; i++)
		    {
			buffer[i] ^= gData.Key;
		    }
		    fOut = fopen(gData.OutFileName, "w");
		    if (fOut != NULL)
		    {
			size_t writtenBytes = 0;		    
			writtenBytes = fwrite(buffer, 1, readBytes, fOut);
			if (writtenBytes == readBytes)
			{
			    printf("Successfully processed %d bytes.\n", (int)writtenBytes);
			}
			else
			{
			    printf("WARNING: Processed %d bytes out of %d bytes!\n", (int)writtenBytes, (int)readBytes);
			}
			fclose(fOut);
		    }				
		    free(buffer);
		}
	    }	    
	    fclose(fIn);
	    fIn = NULL;
	}
    }
    else
    {
	wait(0);
	printf("Child process completed work!\n");
	gData.OperationInProgress = 0;
    }
    return status;
}

void PrintUsage(void)
{
    printf("Usage: crypt <filename> <key>\n\t<filename>	Name of the file to crypt\n\t<key> Crypt key - only one char will be used!\n");
	return;
}

int ReadParams(PGLOBAL_DATA data)
{
    int status = STATUS_SUCCESS;
    if (data == NULL)
    {
	return STATUS_INVALID_PARAMETER;
    }    
    printf("Enter source file name: ");
    scanf("%s", data->FileName);
    if (access(data->FileName, 0) != 0)
    {
	return STATUS_INVALID_FILE;
    }
    printf("Enter destination name: ");
    scanf("%s", data->OutFileName);
    printf("Enter key: ");
    scanf("%s", &data->Key);
    return status;
}