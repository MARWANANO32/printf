#include "main.h"

<<<<<<< HEAD
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
=======
void print_buffer(char buffer[], int *buff_ind);

/**
 *  * _printf - Printf function
 *   * @format: format.
 *    * Return: Printed chars.
 *     */
int _printf(const char *format, ...)
{
		int i, printed = 0, printed_chars = 0;
			int flags, width, precision, size, buff_ind = 0;
				va_list list;
					char buffer[BUFF_SIZE];

						if (format == NULL)
									return (-1);

							va_start(list, format);

								for (i = 0; format && format[i] != '\0'; i++)
										{
													if (format[i] != '%')
																{
																				buffer[buff_ind++] = format[i];
																							if (buff_ind == BUFF_SIZE)
																												print_buffer(buffer, &buff_ind);
																										/* write(1, &format[i], 1);*/
																										printed_chars++;
																												}
															else
																		{
																						print_buffer(buffer, &buff_ind);
																									flags = get_flags(format, &i);
																												width = get_width(format, &i, list);
																															precision = get_precision(format, &i, list);
																																		size = get_size(format, &i);
																																					++i;
																																								printed = handle_print(format, &i, list, buffer,
																																														flags, width, precision, size);
																																											if (printed == -1)
																																																return (-1);
																																														printed_chars += printed;
																																																}
																}

									print_buffer(buffer, &buff_ind);

										va_end(list);

											return (printed_chars);
}

/**
 *  * print_buffer - Prints the contents of the buffer if it exist
 *   * @buffer: Array of chars
 *    * @buff_ind: Index at which to add next char, represents the length.
 *     */
void print_buffer(char buffer[], int *buff_ind)
{
		if (*buff_ind > 0)
					write(1, &buffer[0], *buff_ind);

			*buff_ind = 0;
}

>>>>>>> 4ba74a0355ee2ca9cab14f00be1cfb661881ad0a
