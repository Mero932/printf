#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 *
 * @format: character string.
 *
 * Return: count (character of strings)
 */

int _printf(const char *format, ...)
{
va_list args;
int count 
count = 0;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
int c = va_arg(args, int);
write(1, &c, 1);
count++;
break;
}
case 's':
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
                            write(1, &*s, 1);

                            s++;
                            count++;
                        }
                        break;
                    }
                case '%':
                    {
                        putchar('%');
                        count++;
                        break;
                    }
                default:
                    {
                        putchar('%');
                        putchar(*format);
                        count += 2;
                        break;
                    }
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
