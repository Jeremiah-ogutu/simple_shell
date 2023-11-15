#include "shell.h"

/**
* executing_text - fuction that execute command
* @command:the command to be executed
* @arguments:the txt in the function
*/

void executing_text(const char *text)
{
pid_t child_pid = fork();

if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
char *text_args[150];
int args_count = 0;

char *token = strtok((char *)text, " ");
while (token != NULL)
{
text_args[args_count++] = token;
token = strtok(NULL, " ");
}
text_args[args_count] = NULL;

execvp(text_args[0], text_args);
perror("execvp");

exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
