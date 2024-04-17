
#include "philo.h"

int	ft_atoi(const char *nptr)
{
	long long int	num;
	int				i;
	int				signe;

	num = 0;
	i = 0;
	signe = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - 48;
		i++;
	}
	return (num * signe);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*s1_b;
	unsigned char	*s2_b;

	s1_b = (unsigned char *)s1;
	s2_b = (unsigned char *)s2;
	i = 0;
	while (s1_b[i] == s2_b[i] && s1_b[i] != 0 && s2_b[i] != 0)
		i++;
	return (s1_b[i] - s2_b[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
