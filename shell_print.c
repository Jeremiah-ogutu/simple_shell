#include "shell.h"
/**
 * jerlis_print-the fuction to print
 * @special_printf:this a function performing the printf
 */

void jerlis_print(const char *special_printf)
{
	write(STDOUT_FILENO, special_printf, strlen(special_printf));
}
