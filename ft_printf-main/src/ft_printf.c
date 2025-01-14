/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:02:30 by mgayout           #+#    #+#             */
/*   Updated: 2023/12/01 11:02:30 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft-main/include/libft.h"
#include <stdarg.h>

int	ft_printf2(char *format, va_list args);

int	ft_format(char format, va_list args);

int	ft_hexa(const int fd, const char *base, unsigned long n, int i);

int	ft_putnbr_unsigned(unsigned int n, const int fd);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	char	*ptr;

	ptr = (char *)format;
	va_start (args, format);
	size = ft_printf2(ptr, args);
	va_end(args);
	return (size);
}

int	ft_printf2(char *format, va_list args)
{
	int	size;
	int	j;
	int	i;

	size = 0;
	j = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j = ft_format(format[i], args);
			if (j == -1)
				return (-1);
			size += j;
		}
		else if (ft_putchar_fd(format[i], 1) == -1)
			return (-1);
		else
			size++;
		if (format[i])
			i++;
	}
	return (size);
}

int	ft_format(char format, va_list args)
{
	const char	base1[] = "0123456789abcdef";
	const char	base2[] = "0123456789ABCDEF";
	const int	fd = 1;

	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int), fd));
	if (format == 'x')
		return (ft_hexa(fd, base1, va_arg(args, unsigned int), 0));
	if (format == 'X')
		return (ft_hexa(fd, base2, va_arg(args, unsigned int), 0));
	if (format == 'p')
		return (ft_hexa(fd, base1, va_arg(args, unsigned long), 1));
	if (format == '%')
		return (ft_putchar_fd('%', fd));
	return (-1);
}

int	ft_hexa(const int fd, const char *base, unsigned long n, int i)
{
	int	size;

	size = 0;
	if (i == 1)
	{
		if (n == 0)
			return (ft_putstr_fd("(nil)", fd));
		ft_putstr_fd("0x", fd);
		size += 2;
	}
	if (n >= 16)
		size += ft_hexa(fd, base, n / 16, 0);
	ft_putchar_fd(base[n % 16], fd);
	size++;
	return (size);
}

int	ft_putnbr_unsigned(unsigned int n, const int fd)
{
	int	size;

	size = 0;
	if (n >= 10)
		size += ft_putnbr_unsigned(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
	size++;
	return (size);
}

/*int main (void)
{
	ft_printf(" %p \n", 0);
	printf(" %p \n", (void *)0);
	return (0);
}

int main (void)
{
	const char format[]=" %c / %s / %d %d / %i %i /
	 %u %u / %x %x / %X %X / %p %p / %% \n";
	int		c = '4';
	char	s[]="Bonjour !";
	int		p = INT_MIN;
	int 	q = INT_MAX;
	void	*ptr;
	void	*ptr2;

	ptr = &p;
	ptr2 = &q;
	printf("size = %d\n", ft_printf(format, c, s, 
	(int)INT_MIN, INT_MAX, (int)INT_MIN, INT_MAX, 
	(int)INT_MIN, INT_MAX, (int)INT_MIN, INT_MAX, 
	(int)INT_MIN, INT_MAX, ptr, ptr2));
	printf("size = %d\n", printf(format, c, s, 
	(int)INT_MIN, INT_MAX, (int)INT_MIN, INT_MAX, 
	(int)INT_MIN, INT_MAX, (int)INT_MIN, INT_MAX, 
	(int)INT_MIN, INT_MAX, ptr, ptr2));
	return (0);
}*/