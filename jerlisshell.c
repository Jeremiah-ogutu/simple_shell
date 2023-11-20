Simple Shell interprets commands from std input and forks the program to a child process through use of 'execve. 
Child process executes the command and returns parent process 

invocation
shell operates in  interactive interactive mode, executed via './hsh', prompting the user with '$' to input and execute commands and  non-interactive mode, use 'echo'

builtins
It includes builtins like those of real shell:
'exit [status]' - exits the program.
'env' - prints the environment variables 
'setenv [name] [value]' - manages environment variable
'unsetenv [name]' - deletes a specified environment variable.
'cd [directory]' - changes the working directory

Authors
Jeremiah and Lisette from cohort 19
