/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:18:56 by vfurmane          #+#    #+#             */
/*   Updated: 2020/12/30 19:01:11 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *dest, int len);
void				*ft_calloc(size_t len, size_t size);
int					ft_isalpha(int chr);
int					ft_isalnum(int chr);
int					ft_isascii(int chr);
int					ft_isdigit(int chr);
int					ft_isprint(int chr);
char				*ft_itoa(int nbr);
void				ft_lstadd_back(t_list **first, t_list *new);
void				ft_lstadd_front(t_list **first, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*ft)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*ft)(void *), \
					void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memccpy(void *dest, const void *src, int end, \
					size_t len);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t len);
void				*ft_memchr(const void *dest, int chr, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *dest, int byte, int len);
void				ft_putchar_fd(char chr, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int nbr, int fd);
void				ft_putstr_fd(char *str, int fd);
char				**ft_split(char const *str, char sep);
char				*ft_strchr(const char *str, int chr);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *str1, char const *str2);
size_t				ft_strlcat(char *dest, const char *src, size_t dest_size);
size_t				ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *str, \
					char (*ft)(unsigned int, char));
int					ft_strncmp(const char *str1, const char *str2, size_t len);
char				*ft_strnstr(const char *str, const char *find, size_t len);
char				*ft_strrchr(const char *str, int chr);
char				*ft_strtrim(char const *str, char const *charset);
char				*ft_substr(char const *str, unsigned int start, size_t len);
int					ft_tolower(int chr);
int					ft_toupper(int chr);

#endif
