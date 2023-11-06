#include "shell.h"

int main(void)
{
<<<<<<< HEAD
	char text[150];

	while (true)
	{
		shell_prompt();
		user_inPut(text, sizeof(text));
		execute_prompt(text);


	}
	return (0);
=======
	char command[124];

	while(1)
	{
		unveil_prompt();
	}
>>>>>>> refs/remotes/origin/main
}
