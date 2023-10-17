#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
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
    int count = 0;

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
                        _putchar(c);
                        count++;
                        break;
                    }
                case 's':
                    {
                        char *s = va_arg(args, char *);
                        while (*s != '\0')
                        {
                            _putchar(*s);
                            s++;
                            count++;
                        }
                        break;
                    }
                case '%':
                    {
                        _putchar('%');
                        count++;
                        break;
                    }
                default:
                    {
                        _putchar('%');
                        _putchar(*format);
                        count += 2;
                        break;
                    }
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
