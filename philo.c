
#include "philo.h"

int	main(int ac, char **av)
{
	if (check_arg(ac, av))
	{
		printf("Erreur d'argument\n");
		return (0);
	}
	init_sim(ac, av);
}
