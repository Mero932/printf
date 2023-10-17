#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
* _putchar - This function prints a character using the putchar function.
*
* @c : character parameter
* Return: 1 (success) -1 (failure)
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
