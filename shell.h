#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


void jerlis_print(const char *special_printf);
void unveil_prompt(void);
int executing_text(char (*text)[124]);
void input_text(char *text, size_t size);

#endif
