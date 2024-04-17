
#include "philo.h"

int	mange(t_phi *ph)
{
	if (take_fork(ph) == 1)
		return (1);
	pthread_mutex_lock(&ph->timer_eat);
	ph->last_eat = get_time();
	pthread_mutex_unlock(&ph->timer_eat);
	if (print_shell(ph, 0))
		return (1);
	attend(ph->time2eat);
	if (pthread_mutex_unlock(&ph->mutex) != 0)
		return (1);
	if (pthread_mutex_unlock(&ph->next->mutex) != 0)
		return (1);
	return (0);
}

int	take_fork(t_phi *ph)
{
	if ((ph->n_phi % 2 == 0))
		return (take_fork_paire(ph));
	else
		return (take_fork_impaire(ph));
}

int	take_fork_paire(t_phi *ph)
{
	pthread_mutex_lock(&ph->mutex);
	if (print_shell(ph, 3) == 1)
	{
		pthread_mutex_unlock(&ph->mutex);
		return (1);
	}
	pthread_mutex_lock(&ph->next->mutex);
	if (print_shell(ph, 3) == 1)
	{
		pthread_mutex_unlock(&ph->mutex);
		pthread_mutex_unlock(&ph->next->mutex);
		return (1);
	}
	return (0);
}

int	take_fork_impaire(t_phi *ph)
{
	pthread_mutex_lock(&ph->next->mutex);
	if (print_shell(ph, 3) == 1)
	{
		pthread_mutex_unlock(&ph->next->mutex);
		return (1);
	}
	pthread_mutex_lock(&ph->mutex);
	if (print_shell(ph, 3) == 1)
	{
		pthread_mutex_unlock(&ph->next->mutex);
		pthread_mutex_unlock(&ph->mutex);
		return (1);
	}
	return (0);
}
