#include "../minitalk.h"
#include <stdio.h>

static int	get_char(char *s)
{
	int	symbol;
	int	i;
	int	base;

	i = 7;
	symbol = 0;
	base = 1;
	while (i >= 0)
	{
		if (s[i] == '1')
			symbol += base;
		base *= 2;
		i--;
	}
	return (symbol);
}

static void	signal_handle(int sig)
{
	static char	*s;
	int			i;

	i = 0;
	if (s == NULL)
		s = ft_strdup("");
	if (sig == SIGUSR1)
		s = ft_strjoin(s, "1");
	if (sig == SIGUSR2)
		s = ft_strjoin(s, "0");
	if (ft_strlen(s) == 8)
	{
		ft_putchar_fd(get_char(s), 1);
		free (s);
		s = NULL;
	}
}

int	main(void)
{
	pid_t	pid;
	char	*id;

	signal(SIGUSR1, signal_handle);
	signal(SIGUSR2, signal_handle);
	pid = getpid();
	id = ft_itoa(pid);
	ft_putstr_fd("pid = ", 1);
	ft_putstr_fd(id, 1);
	ft_putstr_fd("\n", 1);
	free (id);
	while (1)
		pause();
	return (0);
}
