#include <stdarg.h> // For va_lis, va_start, va_arg, va_copy, va_end
#include <unistd.h> // For malloc, free, write
#include <stdio.h>

/* my printf passed grademe */
int	ft_putchar_printf(char a)
{
	return (write(1, &a, 1));
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_type_d(int a)
{
	int	len;

	len = 0;
	if (a == 0)
		return (write(1, "0", 1));
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		len += write(1, "-", 1);
		a *= -1;
	}
	if (a >= 10)
		len += ft_type_d(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (len + 1);
}

int	ft_type_x(unsigned int a, char c)
{
	int	len;

	len = 0;
	if (a >= 16)
		len += ft_type_x(a / 16, c);
	if (c == 'x')
		write(1, &"0123456789abcdef"[a % 16], 1);
	return (len + 1);
}

int	ft_work_types(va_list *args, char c)
{
	if (c == 's')
		return (ft_string(va_arg((*args), char *)));
	else if (c == 'd')
		return (ft_type_d(va_arg((*args), int)));
	else if (c == 'x')
		return (ft_type_x(va_arg((*args), unsigned int), c));
	else if (c == '%')
		return (ft_string("%"));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_work_types(&args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar_printf(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}


#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	size;

	size = 0;

	size = ft_printf("%s\n", "toto");
	printf("%d\n", size);
	size = printf("%s\n", "toto");
	printf("%d\n", size);
	size = ft_printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	printf("%d\n", size);
	ft_printf("Hello world %\n");
	return (0);
}
