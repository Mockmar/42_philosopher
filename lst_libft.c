
#include "philo.h"

void	ft_lstadd_back(t_phi **alst, t_phi *new)
{
	t_phi	*tmp;

	tmp = ft_lstlast(*alst);
	if (tmp)
		tmp->next = new;
	else
		*alst = new;
}

void	ft_lstclear(t_phi **lst, int nb_philo)
{
	t_phi	*tmp;
	t_arg	*param;

	param = (*lst)->arg;
	free(param);
	if (!lst || !*lst)
		return ;
	while (lst && *lst && nb_philo)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
		nb_philo--;
	}
}

t_phi	*ft_lstlast(t_phi *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_phi	*ft_lstnew(int num)
{
	t_phi	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->n_phi = num;
	element->next = NULL;
	element->thread = 0;
	element->timer = 0;
	return (element);
}

int	ft_lstsize(t_phi *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
