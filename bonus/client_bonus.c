#include "../minitalk.h"

static void	ac_error(int ac)
{
	if (ac > 3)
		ft_putstr_fd("ERROR: many arguments!\n", 1);
	else
		ft_putstr_fd("ERROR: few arguments!\n", 1);
}

static void	check_pid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] > 47 && s[i] < 58))
		{
			ft_putstr_fd("ERROR: wrong PID!\n", 1);
			exit(1);
		}
		i++;
	}
}

static int	char_to_bin(int c, int pid)
{
	int	i;
	int	check;

	i = 7;
	while (i >= 0)
	{
		if (1 & (c >> i))
			check = kill(pid, SIGUSR1);
		else
			check = kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
	return (check);
}

int	main(int ac, char **av)
{
	char	*s;
	int		pid;
	int		check;

	if (ac == 3)
	{
		check_pid(av[1]);
		pid = ft_atoi(av[1]);
		s = av[2];
		while (*s)
		{
			check = char_to_bin(*s, pid);
			if (check != 0)
			{
				ft_putstr_fd("ERROR: Can't send a message!\n", 1);
				exit(1);
			}
			s++;
		}
		char_to_bin('\n', pid);
		ft_putstr_fd("SUCCESS: Message sent!\n", 1);
	}
	else
		ac_error(ac);
	return (0);
}
