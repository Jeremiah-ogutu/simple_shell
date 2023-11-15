#include "shell.h"

/**
* executing_text - fuction that execute command
* @command:the command to be executed
* @arguments:the txt in the function
*/

void executing_text(const char *command, char *const arguments[])
{
pid_t child_pid = fork();

if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
execve(command, arguments, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}

}
