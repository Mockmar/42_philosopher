
#include "philo.h"

int	pense(t_phi *ph)
{
	if (print_shell(ph, 2))
		return (1);
	if (ph->nb_philo % 2 == 1)
		attend(ph->time2eat - 10);
	return (0);
}

int	dors(t_phi *ph)
{
	if (print_shell(ph, 1))
		return (1);
	attend(ph->time2sleep);
	return (0);
}
