#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void shell_printf(const char *text);
void shell_prompt(void);
void execute_prompt(const char *text);
void user_inPut(char *text, size_t size);




#endif
