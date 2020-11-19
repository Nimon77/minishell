/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:59:40 by nsimon            #+#    #+#             */
/*   Updated: 2020/11/19 17:09:51 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigintHandler(int sig_num)
{
	write(1, "\n❯ ", 5);
}

void	free_matrice(char **tab)
{
	int	i;
	
	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			tab[i++] = NULL;
		}
		free(tab);
		tab = NULL;
	}
}

void 	free_exec(t_shell *data)
{
	t_exec *current;
	t_exec *next;
	
	current = data->exec;
	while (current)
	{
		free(current->name);
		free_matrice(current->args);
		next = current->next;
		free(current);
		current = next;
	}
	data->exec = NULL;
}

void	free_data(t_shell *data)
{
	free_matrice(data->path);
	free_exec(data);
}

void	get_env(t_shell *data, char **env)
{
	int	i;
	char *str;
	
	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	str = ft_strdup(&env[i][5]);
	data->path = ft_split(str, ':');
	free(str);
}

int		count_args(char *line)
{
	int	i;
	int	ret;
	
	i = 0;
	if (!line[i])
		return 0;
	ret = 1;
	while (line[i] != ';' && line[i])
	{
		if ((line[i] == ' ' && line[i+1] != ' '))
			ret++;
		i++;
	}
	return ret;
}

int		get_args(t_exec *new, char *line)
{
	int	i;
	int	j;
	int	nb_args;
	int	count;
	
	i = 0;
	count = 1;
	nb_args = count_args(line) + 1;
	new->args = malloc(sizeof(char *) * nb_args + 1);
	new->args[nb_args] = NULL;
	new->args[0] = ft_strdup(new->name);
	while (line[i] != ';' && line[i])
	{
		j = 0;
		while (line[i] == ' ' && line[i])
			i++;
		while (line[i + j] != ' ' && line[i + j] != ';' && line[i + j])
			j++;
		new->args[count++] = ft_substr(line, i, j);
		i += j;
	}
	return i;
}

void	find_exec(t_exec *exec, char **path)
{
	int	i;
	int fd;
	char *str;
	char *tmp;
	
	i = 0;
	if (!ft_strncmp(exec->name, "/", 1) || !ft_strncmp(exec->name, "./", 2))
		return;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		str = ft_strjoin(tmp, exec->name);
		free(tmp);
		fd = open(str, O_RDONLY);
		close(fd);
		if (fd != -1)
		{
			free(exec->name);
			exec->name = str;
			break;
		}
		free(str);
		i++;
	}
	if (exec->next != NULL)
		find_exec(exec->next, path);
}

void	ft_lst_shell_add_back(t_exec **alst, t_exec *new)
{
	t_exec *tmp;
	
	if (!new)
		return ;
	if (!*alst)
	{
		(*alst) = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	parse(t_shell *data, char *line)
{
	int	i;
	int	j;
	t_exec *new;
	
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		new = malloc(sizeof(t_exec));
		new->next = NULL;
		while (line[i] != ' ' && line[i] != ';' && line[i])
			i++;
		new->name = ft_substr(line, j, i - j);
		i++;
		i += get_args(new, &line[i]);
		line[i] == ';' ? i++ : 0;
		while (line[i] == ' ')
			i++;
		j = i;
		ft_lst_shell_add_back(&data->exec, new);
	}
	find_exec(data->exec, data->path);
}

void	ft_exec(t_shell *data, char **env)
{
	pid_t pid;
	int status;
	t_exec *current;
	
	current = data->exec;
	while (current)
	{
		if ((pid = fork()) == -1)
			perror("fork error");
		else if (pid == 0)
		{
			if ((execve(current->name, current->args, env)) == -1)
			{
				ft_printf("No such file or directory\n");
				exit(EXIT_FAILURE);
			}
		}
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			ft_printf("Exit status: %d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			ft_printf("Erreur: %s\n", strerror(11));
		current = current->next;
	}
}

int		main(int argc, char **argv, char **env)
{
	char *line;
	t_shell	data;
	
	//signal(SIGINT, sigintHandler);
	write(1, "❯ ", 4);
	while (get_next_line(0, &line))
	{
		if (line[0] == '\0' || (line[0] == ';') || (line[0] == '|') ||
			(line[0] == ' ' && !line[1]))
		{
			write(1, "❯ ", 4);
			continue ;
		}
		if (!ft_strncmp(line, "exit", 5))
			exit(EXIT_SUCCESS);
		
		get_env(&data, env);
		parse(&data, line);
		ft_exec(&data, env);
		
		free(line);
		free_data(&data);
		write(1, "❯ ", 4);
	}
	return 1;
}
