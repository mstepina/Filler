/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:32:46 by mstepina          #+#    #+#             */
/*   Updated: 2019/10/03 17:45:04 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

/*
** Get_Next_Line
*/
# define BUFF_SIZE 10

int				get_next_line(const int fd, char **line);
int				read_func(int fd, char **str, int res);
void			checker(int fd, char **line, char **str);
void			n_check(int fd, char **line, char **str);
void			end_check(int fd, char **line, char **str);

/*
** Get_Next_Line structure
*/

typedef struct	s_array
{
	int				fd_counter;
	char			*left_over_str;
	struct s_array	*next;
}				t_array;

t_array			*list_create(const int fd);
int				ft_read(int fd, char *buff, char **str, char *left_over);
char			*ft_check(char *str, char *left_over, char *buff, int *t);
int				get_line(const int fd, char **line, char *left_over);
int				get_next_line(const int fd, char **line);

/*
** ft_printf
*/
int				ft_printf(char *format, ...);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
char			*ft_strcat(char *dest, char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(char *src);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *dest, char *src, unsigned int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putstr(char const *s);
void			*ft_memset(void *dest, int value, size_t len);
char			*ft_strchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *destination, const void *source, size_t num);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strrchr(const char *s, int c);
void			*ft_memalloc(size_t	size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strtrim(char const *s);
size_t			ft_countwords(char const *str, char c);
char			**ft_strsplit(char const *s, char c);
char			*ft_revstr(char *s);
int				ft_isspace(char c);
size_t			ft_digitcount(long n);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
size_t			ft_wordlen(char const *s, char c);
#endif
