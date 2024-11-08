/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:16:09 by mac               #+#    #+#             */
/*   Updated: 2024/11/07 17:35:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	vash_cd(char **args)
{
	char	*path;
	char	cwd[1024];

	if (args[1] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			perror("error: cd");
			return (-1);
		}
	}
	else
		path = args[1];
	if (chdir(path) != 0)
	{
		perror("error: cd");
		return (-1);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		;
	else
		perror("Minishell: cd: no such file or directory");
	return (0);
}

int	ft_pwd(void)
{
	char	cwd[4096];

	if (getcwd(cwd, 4096))
	{
		printf("%s\n", cwd);
		return (1);
	}
	else
		return (0);
}
