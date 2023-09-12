#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "helpers.h"

char** parse(char* line, char* sep){
	char** retVal = (char**)malloc(100*8);
	int ctr = 0;
	retVal[ctr] = strsep(&line, sep);
	while(retVal[ctr] != NULL){
		retVal[++ctr] = strsep(&line, sep);
	}
	for(int i = 0; i < ctr; i++)
	{
		retVal[i] = trimArg(retVal[i]);
	}
	return retVal;
}


char* trimArg(char* input)
{
	char* tmp = input;
	int len = strlen(input);
	int counter = 0;
	while(counter < len)
	{   // trim from the left
		if(tmp[counter] != ' ') break;
		//moves the pointer to the first non-space character in the string
		tmp++;
	}

	while(len > 0)
	{   // trim from the right
		if(tmp[len-1] != ' ') break;
		tmp[len-1] = '\0';
		len--;
		// replaces the space with a NULL
		// effectively gets rid of the space
	}

	return tmp;
}
