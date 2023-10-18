#include "shell.h"
/**
* _prits - output char
* @strings: output string
* Return:  integer
*/
int _prits(const char *strings)
{
	return (write(STDOUT_FILENO, strings, strlen(strings)));
}
