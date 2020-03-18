#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
#include <unistd.h>
/**
 * _printf - printff function
 * @format: format string first printf string
 * Prototype: int _printf(const char *format, ...);
 * Return: the number of characters printed
 *(excluding the null byte used to end output to strings)
 * write output to stdout, the standard output stream
 * format is a character string. The format string is
 * composed of zero or more directives.
 * See man 3 printf for more detail. You need to handle
 * the following conversion specifiers:
 * c s %
 **/
int _printf(const char *format, ...)
{
	int i = 0, result;
	int b = 0;
	char *buffer;
	struktur form[] = {
        {"c", save_c},
        {"s", save_s},
        {"d", save_d},
        {NULL, NULL}
        };
	va_list valist;

	if (format == NULL)
		return (-1);
	buffer = malloc(_strlen((char *)format) * sizeof(char) + 1);
	while (format[i])
	{
		buffer[i] = format[i];
		i++;
	}
	va_start(valist, format);
	if (buffer == NULL)
	{
		return (-1);
	}
	if (*buffer == '%' && *(buffer + 1) == 0)
	{
		return (-1);
	}
	for (i = 0; format[i] != '0'; i++)
	{
		if (buffer[i] == '%')
		{
			for (b = 0; b < 4; b++)
			{
				if (buffer[i + 1] == *struktur[b].fo)
				{
					struktur[b].f(buffer, i, '0', valist)
				}
			}
		}
	}
	va_end(valist);
	result = write(1, buffer, _strlen(buffer));
	return (result);
}
