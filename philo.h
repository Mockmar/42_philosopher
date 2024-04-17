#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_arg
{
	int				nb_philo;
	int				is_dead;
	pthread_mutex_t	print;
}	t_arg;

typedef struct s_phi
{
	struct s_arg		*arg;
	int					nb_philo;
	int					time2die;
	int					time2eat;
	int					time2sleep;
	int					nb_must_eat;
	int					is_dead;
	int					n_phi;
	pthread_t			thread;
	pthread_t			timer;
	pthread_mutex_t		timer_eat;
	pthread_mutex_t		mutex;
	long long			last_eat;
	int					nb_eat;
	long long			time_start;
	int					nb_think;
	pthread_mutex_t		start;
	struct s_phi		*next;
}	t_phi;

/*check_arg*/
int			check_arg(int ac, char **av);
int			str_is_not_nbr(char *str);
int			hors_int(char *str);
/*ft_libft*/
int			ft_atoi(const char *nptr);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
/*init*/
int			init_sim(int ac, char **av);
t_arg		*init_arg(char **av);
t_phi		*init_philo(t_phi *philo, t_arg *param, char **av, int ac);
t_phi		*lst_philo(t_arg *param);
t_phi		*init_philo_bis(t_phi *philo, t_arg *param, char **av);
/*lst_libft*/
int			ft_lstsize(t_phi *lst);
t_phi		*ft_lstnew(int num);
t_phi		*ft_lstlast(t_phi *lst);
void		ft_lstclear(t_phi **ph, int nb_philo);
void		ft_lstadd_back(t_phi **alst, t_phi *new);
/*simu*/
t_phi		*thread_philo(t_phi *philo, t_arg *param);
void		*routine(void *philo);
/*eat_fork*/
int			take_fork(t_phi *ph);
int			take_fork_impaire(t_phi *ph);
int			take_fork_paire(t_phi *ph);
int			mange(t_phi *ph);
/*sleep_think*/
int			pense(t_phi *ph);
int			dors(t_phi *ph);
/*utils*/
int			print_shell(t_phi *ph, int mode);
int			print_shell_bis(t_phi *ph, int mode);
long long	get_time(void);
void		attend(int tmp_ms);
int			nb_meal(t_phi *ph);
/*end_sim*/
int			quit_clean(t_phi *ph);
t_phi		*end_simu(t_phi *philo, t_arg *param);

#endif
