/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:19:05 by mac               #+#    #+#             */
/*   Updated: 2024/11/07 14:04:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "../include/minishell.h"

static void	suppress_output(void)
{
	struct termios	termios_path;

	if (tcgetattr(0, &termios_path) != 0)
		perror("Minishell: tcgetattr");
	termios_path.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &termios_path) != 0)
		perror("Minishell: tcsetattr");
}

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_eof(int sig)
{
	if (sig == SIGUSR2)
		exit(0);
}

void	handle_sigquit(int sig)
{
	(void)sig;
	rl_redisplay();
}

void	handle_signals(void)
{
	suppress_output();
	signal(SIGUSR2, handle_eof);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
