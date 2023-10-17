#include "shell.h"
#include <unistd.h>
/**
* _put - output to stdout
* @characts: output characters
* Return: int
*/
int _put(char characts)
{
        return (write(STDOUT_FILENO, &characts, 1));
}
