#ifndef SHELL_H
#define SHELL_H

#include "stdio.h"
#include "string.h"
#include "unistd.h"


void shell_printf(const char *outPut);
void shell_prompt(void);
void execute_prompt(const char *outPut);
void user_inPut(char *inPut, size_t size);




#endif
