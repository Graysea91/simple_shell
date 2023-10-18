#include "shell.h"
/**
* _prop - commandline prompt
*
*/
void _prop(void)
{
char dir[1024];

if (getcwd(dir, sizeof(dir)) == NULL)
{
perror("getcwd");
exit(EXIT_FAILURE);
}
_prits(dir);
_prits("$ ");
}
