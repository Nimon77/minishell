/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rqouchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:25:36 by rqouchic          #+#    #+#             */
/*   Updated: 2020/06/01 19:59:01 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef	struct		s_struct
{
	char			flag;
	int				width;
	int				precision;
	char			type;
	int				bool;
	int				prec_s;
	int				x;
}					t_struct;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strdup(const char *s);
void				*ft_calloc(size_t nombre, size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd, int i);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_lstiter(t_list *lst, void (*f)(void *));
char				*ft_itoa_base(unsigned int n, char *base);
int					ft_putnbr_unsigned(unsigned int n);
char				*ft_itoa_base_add(unsigned long long int n, char *base);
int					ft_putchar_fd_return(char c, int fd);
char				*ft_strjoin_f12(char const *s1, char const *s2);
int					get_next_line(int fd, char **line);
char				*ft_strjoin_s1(char const *s1, char const *s2);
char				*ft_strjoin_s2(char const *s1, char const *s2);

int					ft_print_x(long long int nb, t_struct *data);
int					ft_printf(const char *str, ...);
int					ft_print_u(unsigned int nb, t_struct *data);
int					ft_print_string(char *str, t_struct *data);
int					ft_print_nb(int nb, t_struct *data);
int					ft_print_char(char a, t_struct *data);
int					ft_print_add(long long int nb, t_struct *data);
void				ft_verif_type(const char *str, t_struct *data, int **i);
void				ft_verif_precision(const char *str, t_struct *data, int **i,
va_list arg);
void				ft_verif_width(const char *str, t_struct *data,
int **i, va_list arg);
void				ft_verif_flags(const char *str, t_struct *data, int **i);
void				ft_initial_data(t_struct *data);
void				ft_printbis_x(t_struct *data, unsigned long long int *nb,
int *p, int *a);
#endif
