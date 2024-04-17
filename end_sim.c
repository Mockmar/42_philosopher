
#include "philo.h"

t_phi	*end_simu(t_phi *philo, t_arg *param)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		pthread_mutex_lock(&philo->timer_eat);
		if (get_time() - philo->last_eat > (long long)philo->time2die)
		{
			print_shell(philo, 4);
			flag = 0;
		}
		pthread_mutex_unlock(&philo->timer_eat);
		philo = philo->next;
	}
	flag = param->nb_philo;
	while (flag)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		flag--;
	}
	return (philo);
}

int	quit_clean(t_phi *ph)
{
	int	nb_philo;
	int	i;

	i = ph->arg->nb_philo;
	pthread_mutex_destroy(&ph->arg->print);
	while (i)
	{
		pthread_mutex_destroy(&ph->mutex);
		pthread_mutex_destroy(&ph->timer_eat);
		ph = ph->next;
		i--;
	}
	nb_philo = ph->arg->nb_philo;
	ft_lstclear(&ph, nb_philo);
	return (0);
}
