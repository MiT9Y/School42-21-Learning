/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 07:36:55 by msimon            #+#    #+#             */
/*   Updated: 2021/06/16 18:37:40 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list	*g_pid_lst;

static char	*str_add_ch(char *str, char ch)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 2));
	ft_memmove(res, str, len);
	res[len] = ch;
	res[len + 1] = 0;
	if (!res)
		pr_error("Error malloc.\n");
	return (res);
}

static void	add_byte(t_pid_str *el, int pid)
{
	char	*n_str;	

	n_str = str_add_ch(el->str, (char)el->ch);
	free(el->str);
	el->str = n_str;
	if (!el->ch)
	{
		ft_putstr_fd("Procces PID:", 1);
		ft_putnbr_fd(pid, 1);
		ft_putstr_fd(" sent message\n", 1);
		write(1, el->str, ft_strlen(el->str));
		ft_putstr_fd("\n\n", 1);
		del_el(&g_pid_lst, el);
		kill(pid, SIGUSR2);
	}
	else
	{
		el->bit_count = 0;
		el->ch = 0;
		kill(pid, SIGUSR1);
	}
}

static void	my_hd(int sig, siginfo_t *info, void *context)
{
	t_pid_str	*el;

	(void)context;
	if (info->si_pid > 1)
	{
		el = get_el_lst(&g_pid_lst, info->si_pid);
		if (sig == SIGUSR2)
			el->ch += 1 << el->bit_count;
		el->bit_count++;
		if (el->bit_count == 8)
			add_byte(el, info->si_pid);
		else
			kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	act;

	g_pid_lst = 0;
	ft_putstr_fd("This process ID of this program is ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	ft_memset(&act, 0, sizeof(act));
	act.sa_sigaction = my_hd;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);
	sigaddset(&(act.sa_mask), SIGUSR2);
	if (sigaction(SIGUSR1, &act, 0))
		pr_error("signal error\n");
	if (sigaction(SIGUSR2, &act, 0))
		pr_error("signal error\n");
	while (1)
		;
	return (0);
}
