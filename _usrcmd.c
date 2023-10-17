#include "shell.h"
/**
* _usrcmd -  command by users...
* @cmder: command  parsed...
* @sizes: command reading.....
*/
void _usrcmd(char **cmder, size_t *sizes)
{
ssize_t cmdread;

cmdread = _get(cmder, sizes);

if (cmdread == -1)
{
if (*cmder == NULL)
{
perror("getline");
exit(EXIT_FAILURE);
}

if (feof(stdin))
{
_prits("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}

if ((*cmder)[cmdread - 1] == '\n')
{
(*cmder)[cmdread - 1] = '\0';
*sizes = strlen(*cmder);
}
}
