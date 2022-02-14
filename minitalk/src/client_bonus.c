/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 06:53:42 by msimon            #+#    #+#             */
/*   Updated: 2021/06/16 18:43:39 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	g_no_ans_f;

static void	my_hd(int sig)
{
	g_no_ans_f = 0;
	if (sig == SIGUSR2)
		ft_putstr_fd("Server received the message.\n", 1);
}

static void	sent_bit_now(char bit, int pid)
{
	if (pid > 1)
	{
		if (bit)
		{
			if (kill(pid, SIGUSR2))
				pr_error("Bad sent signal.\n");
		}
		else
		{
			if (kill(pid, SIGUSR1))
				pr_error("Bad sent signal.\n");
		}
	}
}

static void	sent_bit(char bit, int pid, int count)
{
	int		w_count;

	g_no_ans_f = 1;
	w_count = 0;
	sent_bit_now(bit, pid);
	while (g_no_ans_f)
	{
		usleep(4);
		w_count++;
		if (w_count == 125)
			break ;
	}
	if (g_no_ans_f && count < 2048)
		sent_bit(bit, pid, count + 1);
}

static void	sent_byte(char ch, int pid)
{
	int		i;
	char	bit;

	i = -1;
	while (++i < 8)
	{
		bit = ch & 1;
		usleep(64);
		sent_bit(bit, pid, 0);
		if (g_no_ans_f)
			pr_error("Server no answer!\n");
		ch = ch >> 1;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	size_t				i;

	if (argc != 3)
		pr_message("Use a client with two parameters: [server-pid] [message]\n");
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, my_hd);
	signal(SIGUSR2, my_hd);
	i = -1;
	while (argv[2][++i])
		sent_byte(argv[2][i], pid);
	sent_byte(argv[2][i], pid);
	return (0);
}
