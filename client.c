#include "minitalk.h"

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

static void	char_to_bin(int c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (1 & (c >> i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	char	*error;
	char	*s;
	int		pid;

	if (ac == 3)
	{
		check_pid(av[1]);
		pid = ft_atoi(av[1]);
		s = av[2];
		while (*s)
		{
			char_to_bin(*s, pid);
			s++;
		}
		char_to_bin('\n', pid);
	}
	else
	{
		if (ac > 3)
			error = "ERROR: many arguments!\n";
		else
			error = "ERROR: few arguments!\n";
		ft_putstr_fd(error, 1);
	}
	return (0);
}
