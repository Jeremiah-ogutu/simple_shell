#include "shell.h"

void shell_printf(const char *outPut)
{
	write(STDOUT_FILENO, outPut, strlen(outPut));
}
