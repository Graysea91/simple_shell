#include "shell.h"
/**
* _exect - child process
* @comdline: executed
*/
void _exect(const char *comdline);
void _exect(const char *comdline)
{
char *argssn[128];
int argscounts = 0;
char *delimiters = " \n\t";
char *_my_env[] = {NULL};

pid_t pross_id = fork();

if (pross_id == -1)
{
perror("fork Error");
exit(EXIT_FAILURE);
}
else if (pross_id == 0)
{
char *token_s = strtok((char *)comdline, delimiters);

while (token_s != NULL)
{
argssn[argscounts++] = token_s;
token_s = strtok(NULL, delimiters);
}
argssn[argscounts] = NULL;

if (strcmp(argssn[0], "clear") == 0)
{
if (system("clear") == -1)
{
perror("clear");
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}

if (strchr(argssn[0], '/') != NULL)
{
if (execve(argssn[0], argssn, _my_env) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
char *_ph_envs = getenv("PATH");
char *_ph_copy = strdup(_ph_envs);
char *_phs = strtok(_ph_copy, ":");

free(_ph_copy);
while (_phs != NULL)
{
char fullths[256];

snprintf(fullths, sizeof(fullths), "%s/%s", _phs, argssn[0]);
if (execve(fullths, argssn, _my_env) != -1)
{
exit(EXIT_SUCCESS);
}
_phs = strtok(NULL, ":\t\n");
}

perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}
