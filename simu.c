
#include "philo.h"

t_phi	*thread_philo(t_phi *philo, t_arg *param)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		if (philo->n_phi == param->nb_philo)
			flag = 0;
		pthread_mutex_lock(&philo->start);
		if (pthread_create(&philo->thread, NULL, routine, philo) != 0)
			return (NULL);
		philo = philo->next;
	}
	flag = 1;
	while (flag)
	{
		if (philo->n_phi == param->nb_philo)
			flag = 0;
		philo->last_eat = get_time();
		philo->time_start = get_time();
		pthread_mutex_unlock(&philo->start);
		philo = philo->next;
	}
	return (end_simu(philo, param));
}

void	*routine(void *philo)
{
	t_phi	*ph;

	ph = philo;
	pthread_mutex_lock(&ph->start);
	while (1 && ph->nb_philo != 1)
	{
		if (mange(ph) == 1)
			break ;
		if (dors(ph) == 1)
			break ;
		if (pense(ph) == 1)
			break ;
	}
	pthread_mutex_unlock(&ph->start);
	return (NULL);
}
