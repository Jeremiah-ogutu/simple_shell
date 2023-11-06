#include "shell.h"

void jerlis_print(const char *special_printf)
{
	write(STDOUT_FILENO, special_printf, strlen(special_printf));
}
