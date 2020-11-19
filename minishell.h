/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:53:44 by nsimon            #+#    #+#             */
/*   Updated: 2020/11/18 15:38:15 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <errno.h>

typedef struct		s_exec
{
	char			*name;
	char			**args;
	struct s_exec	*next;
}					t_exec;

typedef struct		s_shell
{
	char			**path;
	t_exec			*exec;
}					t_shell;



#endif
