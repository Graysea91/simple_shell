#include "shell.h"
/**
* _get - read input
* @buffer: use in storing read input
* @size_s: buffer size
* Return: integer
*/
ssize_t _get(char **buffer, size_t *size_s)
{
static char buffer_s[1024];

ssize_t numread;

*buffer = NULL;

if (*buffer == NULL)
{
*buffer = buffer_s;
}
*size_s = sizeof(buffer_s);

numread = read(0, *buffer, *size_s);

if (numread == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
else if (numread == 0)
{
if (isatty(0))
_prits("\n");
exit(EXIT_SUCCESS);
}

return (numread);
}
