/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:38:54 by malavent          #+#    #+#             */
/*   Updated: 2019/05/11 12:21:17 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strcpy(char *dest, char const *src);
char				*ft_strncpy(char *dest, char const *src, size_t n);
char				*ft_strcat(char *dest, char const *src);
char				*ft_strncat(char *dest, char const *src, size_t n);
size_t				ft_strlcat(char *dest, char const *src, size_t size);
void				*ft_memset(void	*s, int c, size_t n);
size_t				ft_strlen(char const *s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
char				*ft_strdup(char const *s);
char				*ft_strrchr(char const *s, int c);
char				*ft_strchr(char const *s, int c);
void				*ft_memmove(void *dest, void const *src, size_t len);
char				**ft_strsplit(char const *s, char c);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_itoa(uintmax_t n);
char				*ft_strjoin(char const *s1, char const *s2);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
uintmax_t			ft_power(int n, int power);
void				ft_lstswap_content(t_list *lst_a, t_list *lst_b);
t_list				*ft_lstat(t_list *lst, int at);
t_list				*ft_lstsort(t_list *lst, int (*cmp)(int, int));
size_t				ft_lstsize(t_list *lst);
int					ft_convert_dec(char c, int base);
int					ft_atoi_base(const char *str, int base);
size_t				ft_numlen(uintmax_t nb);
char				ft_convert_itoc(uintmax_t value);
size_t				ft_numlen_base(uintmax_t value, uintmax_t base);
char				*ft_itoabase(uintmax_t value, int base);
int					ft_intsize(int n);
char				*ft_strrev(char *str);
void				ft_swap(char *a, char *b);
/*
**				Added functions for ft_printf
*/
void				ft_putnstr(char *str, int size);
char				*ft_strupper(char *str);
void				print_nchar(int size, char c);
char				*ft_dftoa(double x);
#endif
