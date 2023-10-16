#inlcude "main.h"

/**
 *  _printf - produces output according to a format.
 *  
 *  @format: charcter string
 *
 *  Return: the num of charcters printed
*/

int _printf(const char *format, ...)
{
	int i = 0;
	va_list ptr0;
	int x;
	
	va_start(ptr0, format);

	x = va_arg(ptr0, char)

	for (i = 0; i < format; i++)
	{
		if (x == 'c')
		{
			printf("%c\n", x);
			return (strlen(x));
		}
		else if (x == 's')
		{
			printf("%s\n", x);
			return (strlen(x));
		}
		else if (x == '%')
		{
			printf("%%\n", x);
			return (strlen(x));
		}
	}
}
