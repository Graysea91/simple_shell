#include "shell.h"
/**
* _env_print - stdout envs
* @env: variables from enviroment
*/
void _env_print(char **env)
{
int a;
char b = '\n';

for (a = 0; env[a] != NULL; a++)
{
_prits(env[a]);
_put(b);
}
}
