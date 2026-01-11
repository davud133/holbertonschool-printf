#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - my own printf
 * @format: string
 * @...: arguments
 *
 * Return: nothing
 */
int _printf(const char *format, ...)
{
	va_list arg;
	const char *Str = format;
	int i;
	char c;
	char *s;
	int k;
	int counter = 0;
	va_start(arg, format);
	for (i = 0; Str[i] != '\0'; i++)
	{
		if (Str[i] == '%')
		{
			if (Str[i + 1] == 'c')
			{
				c = va_arg(arg, int);
				write(1, &c, 1);
				i += 1;
				counter++;
			}
			else if (Str[i + 1] == 's')

			{
				s = va_arg(arg, char *);
				if (s == NULL)
					s = "(null)";
				for (k = 0; s[k] != '\0'; k++)
				{
					write(1, &s[k], 1);
					counter++;
				}
				i += 1;
			}
			else if (Str[i + 1] == '%')
			{
				write(1, &Str[i], 1);
				i += 1;
				counter++;
			}
			else
			{
				write(1, &Str[i], 1);
				counter++;
			}
		}
		else
		{
			write(1, &Str[i], 1);
			counter++;
		}
	}
	va_end(arg);
	return (counter);
}
