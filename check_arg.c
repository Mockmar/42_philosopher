
#include "philo.h"

int	check_arg(int ac, char **av)
{
	int	tmp;

	tmp = ac;
	if (ac != 5 && ac != 6)
		return (1);
	while (ac > 1)
	{
		if (str_is_not_nbr(av[ac - 1]))
			return (1);
		if (hors_int(av[ac - 1]))
			return (1);
		if (av[ac - 1][0] == '-')
			return (1);
		ac--;
	}
	if (ft_atoi(av[1]) == 0)
		return (1);
	if (tmp == 6 && ft_atoi(av[tmp - 1]) == 0)
		return (1);
	return (0);
}

int	str_is_not_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	hors_int(char *str)
{
	int	nb;
	int	i;

	nb = ft_atoi(str);
	if (!ft_strcmp("-2147483648", str))
		return (0);
	i = ft_strlen(str) - 1;
	if ((nb < 0 && str[0] != '-' ) || (nb >= 0 && str[0] == '-'))
		return (1);
	if (nb == 0 && str[0] == '0')
		return (0);
	else if (nb == 0 && str[0] != '0')
		return (1);
	if (nb < 0)
		nb = -nb;
	while (i >= 0)
	{
		if (i == 0 && str[i] == '-')
			return (0);
		if (str[i] - 48 != nb % 10)
			return (1);
		nb = nb / 10;
		i--;
	}
	return (0);
}
