
#include "philo.h"

long long	get_time(void)
{
	struct timeval	temps;

	gettimeofday(&temps, NULL);
	return (temps.tv_sec * 1000 + temps.tv_usec / 1000);
}

int	print_shell(t_phi *ph, int mode)
{
	char	*msg[5];

	msg[0] = "is eating";
	msg[1] = "is sleeping";
	msg[2] = "is thinking";
	msg[3] = "has taken a fork";
	msg[4] = "died";
	pthread_mutex_lock(&ph->arg->print);
	if (mode == 0 && ph->nb_must_eat != -1 && nb_meal(ph))
		ph->arg->is_dead = 1;
	else if (ph->arg->is_dead == 1)
		return (print_shell_bis(ph, mode));
	printf("%lld %d %s\n", get_time() - ph->time_start, \
	ph->n_phi, msg[mode]);
	if (mode != 4)
		pthread_mutex_unlock(&ph->arg->print);
	else
	{
		ph->arg->is_dead = 1;
		pthread_mutex_unlock(&ph->arg->print);
	}
	return (0);
}

int	print_shell_bis(t_phi *ph, int mode)
{
	if (mode == 0)
	{
		pthread_mutex_unlock(&ph->next->mutex);
		pthread_mutex_unlock(&ph->mutex);
	}
	pthread_mutex_unlock(&ph->arg->print);
	return (1);
}

void	attend(int tmp_ms)
{
	tmp_ms = tmp_ms * 1000;
	while (tmp_ms > 1000000)
	{
		usleep(1000000);
		tmp_ms -= 1000000;
	}
	usleep(tmp_ms);
}

int	nb_meal(t_phi *ph)
{
	int	i;
	int	cpt;

	i = ph->nb_philo;
	cpt = 0;
	ph->nb_eat += 1;
	while (i)
	{
		if (ph->nb_eat >= ph->nb_must_eat)
			cpt++;
		ph = ph->next;
		i--;
	}
	return (cpt == ph->nb_philo);
}
