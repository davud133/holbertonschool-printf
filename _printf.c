#include "main.h"
#include <limits.h>
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
	int num;
	int counter = 0;
	int t;
	char nums[12];
	va_start(arg, format);
	for (i = 0; Str[i] != '\0'; i++)
	{
		if (Str[i] == '%')
		{
			if(Str[i + 1] == '\0')
			{
				return (counter - 1);
			}
			else if (Str[i + 1] == 'c')
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
			else if (Str[i + 1] == 'd' || Str[i + 1] == 'i')
			{
				num = va_arg(arg, int);
				if (num == INT_MIN)
				{
					s = "-2147483648";
					for (k = 0; s[k] != '\0'; k++)
					{
						counter++;
						write(1, &s[k], 1);
					}
				}
				else if (num < 0)
				{
					c = '-';
					write(1, &c, 1);
					counter++;
					num = num * -1;

				}
				else if(num == 0)
				{
					c = '0';
					write(1, &c, 1);
					counter++;
					i++;
				}
				t = 0; 
				while (num > 0)
				{
    					nums[t++] = (num % 10) + '0';
    					num /= 10;
				}
				for (t = t - 1; t >= 0; t--)
				{
    					write(1, &nums[t], 1);
    					counter++;
				}
				i+=1;

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
