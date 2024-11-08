/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:34:32 by vconesa-          #+#    #+#             */
/*   Updated: 2024/11/07 17:33:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	vash_launch(char **argv)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("type in a valid command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("a forking error occured");
		exit(EXIT_FAILURE);
	}
	return (0);
}

static int	check_built_null_args(char **args)
{
	if (args[0] == NULL)
		return (0);
	return (1);
}

int	handle_builtins(char **args)
{
	check_built_null_args(args);
	if (ft_strncmp(args[0], "exit", 5) == 0)
		exit(0);
	else if (ft_strncmp(args[0], "cd", 3) == 0)
		vash_cd(args);
	else if (ft_strncmp(args[0], "echo", 5) == 0)
		vash_echo(args);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		ft_pwd();
	else if (ft_strncmp(args[0], "env", 4) == 0)
		vash_env();
	else if (ft_strncmp(args[0], "export", 7) == 0
		|| ft_strncmp(args[0], "setenv", 7) == 0)
	{
		if (args[1] == NULL && ft_strncmp(args[0], "setenv", 7) != 0)
			vash_env();
		else
			vash_export(args);
	}
	else if (ft_strncmp(args[0], "unset", 6) == 0
		|| ft_strncmp(args[0], "unsetenv", 9) == 0)
		vash_unset(args);
	else
		return (0);
	return (1);
}

//Previous code of handle_builtins -- delete if everything works

//int handle_builtins(char **args)
// {
// 	if (args[0] == NULL)
// 		return 0;
// 	if (ft_strncmp(args[0], "exit", 5) == 0)
// 		exit(0);
// 	else if (ft_strncmp(args[0], "cd", 3) == 0)
// 		vash_cd(args);
// 	else if (ft_strncmp(args[0], "echo", 5) == 0)
// 		vash_echo(args);
// 	else if (ft_strncmp(args[0], "pwd", 4) == 0)
// 		ft_pwd();
// 	else if (ft_strncmp(args[0], "env", 4) == 0)
// 		vash_env();
// 	else if (ft_strncmp(args[0], "export", 7) == 0
// 		|| ft_strncmp(args[0], "setenv", 7) == 0)
// 	{
// 		if (args[1] == NULL && ft_strncmp(args[0], "setenv", 7) != 0)
// 			vash_env();
// 		else
// 			vash_export(args);
// 	}
// 	else if (ft_strncmp(args[0], "unset", 6) == 0
// 		|| ft_strncmp(args[0], "unsetenv", 9) == 0)
// 		vash_unset(args);
// 	else
// 		return (0);
// 	return (1);
// }
