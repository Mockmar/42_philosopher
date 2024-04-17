
#include "philo.h"

int	init_sim(int ac, char **av)
{
	t_arg	*param;
	t_phi	*philo;

	param = init_arg(av);
	if (!param)
		return (1);
	philo = lst_philo(param);
	if (!philo)
		return (1);
	philo = init_philo(philo, param, av, ac);
	if (!philo)
		return (1);
	philo = thread_philo(philo, param);
	if (!philo)
		return (1);
	quit_clean(philo);
	return (0);
}

t_arg	*init_arg(char **av)
{
	t_arg	*param;

	param = malloc(sizeof(*param));
	if (!param)
		return (NULL);
	param->nb_philo = ft_atoi(av[1]);
	param->is_dead = 0;
	if (pthread_mutex_init(&param->print, NULL) != 0)
		return (NULL);
	return (param);
}

t_phi	*init_philo(t_phi	*philo, t_arg *param, char **av, int ac)
{
	int	i;

	i = param->nb_philo;
	while (i)
	{
		if (pthread_mutex_init(&(philo->mutex), NULL) != 0)
			return (NULL);
		if (pthread_mutex_init(&(philo->start), NULL) != 0)
			return (NULL);
		if (pthread_mutex_init(&(philo->timer_eat), NULL) != 0)
			return (NULL);
		philo = init_philo_bis(philo, param, av);
		if (ac == 6)
			philo->nb_must_eat = ft_atoi(av[5]);
		else
			philo->nb_must_eat = -1;
		philo = philo->next;
		i--;
	}
	return (philo);
}

t_phi	*init_philo_bis(t_phi *philo, t_arg *param, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time2die = ft_atoi(av[2]);
	philo->time2eat = ft_atoi(av[3]);
	philo->time2sleep = ft_atoi(av[4]);
	philo->nb_eat = 0;
	philo->nb_think = 0;
	philo->arg = param;
	return (philo);
}

t_phi	*lst_philo(t_arg *param)
{
	t_phi	*philo;
	t_phi	*tmp;
	t_phi	*new;
	int		i;

	i = 1;
	philo = NULL;
	tmp = NULL;
	while (i <= param->nb_philo)
	{
		new = ft_lstnew(i);
		if (!new)
			return (NULL);
		ft_lstadd_back(&philo, new);
		philo->arg = param;
		i++;
	}
	tmp = ft_lstlast(philo);
	tmp->next = philo;
	return (philo);
}
