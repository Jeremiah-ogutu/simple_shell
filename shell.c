#include "shell.h"
/**
 * main-the starting point
 *
 * Return:void
 */

int main(void)
{
	char text[124];

	while (1)
	{
		unveil_prompt();
		executing_text(text, NULL);
		 input_text(text, sizeof(text));
	}
}
