#include "main.h"

/**
 * _printf - print anything
 * @format: the format string
 *
 * return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int mul = 0;
	va_list ar;
	char *p, *start;

	params_m params = PARAMS_INIT;

	va_start(ar, format);

	if (!format || (format[0] == '%' && format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return(-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ar);
		if (*p != '%')
		{
			mul += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, ar);
		p = get_precision(p, &params, ar);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			mul += print_from_to(strat, p
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			mul += get_print_func(p, ar, &params);

	}
	_putchar(BUF_FLUSH);
	va_end(ar);
	return (mul);
}
