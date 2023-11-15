#include "shell.h"
/**
 * main-the starting point
 *
 * Return:0 success
 */

int main(void)
{

	char text[124];

	while (1)
	{
		unveil_prompt();
		executing_text(&text);
		 input_text(text, sizeof(text));
	}
}
