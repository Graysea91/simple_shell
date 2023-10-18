#include "shell.h"
/**
* main -   program
* @argc: passed to the sytem
* @argv: argvs argument
* @env: envs variables
* Return: returns  an integer
*/
int main(int argc, char *argv[], char **env)
{
int exitno;
size_t nline;
size_t sizes;
char *cmder;
(void)argc;
(void)argv;

cmder = NULL;
exitno = 0;

while (1)
{
if (isatty(0) == 1)
_prop();

_usrcmd(&cmder, &sizes);

if (strcmp(cmder, "exit") == 0)
{
break;
}
else if (strncmp(cmder, "exit ", 5) == 0)
{
exitno = atoi(cmder + 5);
break;
}
else if (strcmp(cmder, "env") == 0 || strcmp(cmder, "printenv") == 0)
_env_print(env);
_exect(cmder);

nline = strcspn(cmder, "\n");
if (nline < sizes)
cmder[nline] = '\0';

if (cmder != NULL)
cmder = NULL;
}

return (exitno);
}
