/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:29:12 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/10 18:11:23 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

long	ft_atoi(const char	*string)
{
	int			i;
	int			ichara;
	long		result;

	i = 0;
	ichara = 1;
	result = 0;
	while (string[i] == 32 || (string[i] >= 9 && string[i] <= 13))
		i++;
	if (string[i] == '-')
	{
		ichara = -1;
		i++;
	}
	else if (string[i] == '+')
		i++;
	while (ft_isdigit(string[i]) && string[i] != '\0')
	{
		result = result * 10 + (string[i] - '0');
		i++;
	}
	return (result * ichara);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c < 58)
		return (1);
	return (0);
}

double	ft_atod(const char *string)
{
	double	number;
	int		i;
	double	decimal_part;
	double	integer_part;

	integer_part = 10.0;
	i = 0;
	number = 0.0;
	decimal_part = (double)ft_atoi(string);
	while(string[i] != '.' && string[i] != '\0')
		i++;
	if (string[i] == '.')
	{
		i++;
		while (ft_isdigit(string[i]) && string[i]!= '\0')
		{
			number += (double)(string[i] - 48) / integer_part;
			i++;
			integer_part *= 10;
		}
	}
	if (string[0] == '-')
		number *= -1;
	return (decimal_part + number);
}
