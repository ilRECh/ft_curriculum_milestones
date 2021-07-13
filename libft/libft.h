#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include "ft_printf.h"

# define TRUE 1
# define FALSE 0

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define BLACK_BOLD "\033[0;30;1m"
# define RED_BOLD "\033[0;31;1m"
# define GREEN_BOLD "\033[0;32;1m"
# define YELLOW_BOLD "\033[0;33;1m"
# define BLUE_BOLD "\033[0;34;1m"
# define MAGENTA_BOLD "\033[0;35;1m"
# define CYAN_BOLD "\033[0;36;1m"

///
///	SORTs
///	CONFIGURE sort_config.h FIRST!
///
typedef struct s_index
{
	size_t	First;
	size_t	Middle;
	size_t	Last;
}	t_index;

typedef struct s_function
{
	int	(*compare)(void *, void *, size_t, size_t);
	int	(*assign)(void *, void *, size_t, size_t);
}	t_function;

typedef enum e_DATA_TYPE
{
	CHAR = 1,
	UCHAR = 11,
	INT = 14,
	UINT = 24,
	LONG = 28,
	ULONG = 38,
	FLOAT = 34,
	DOUBLE = 18
}	t_DATA_TYPE;

void			ft_mergesort(void *to_sort, size_t len, t_DATA_TYPE type);

///
///	SEARCHes
///
size_t			ft_bin_search(int *arr, size_t left, size_t right, int to_find);

///
/// MEMs
///
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);

///
///	IS
///
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

///
///	TO
///
int				ft_tolower(int c);
int				ft_toupper(int c);

///
/// CONVERTIONs
///
int				ft_atoi(const char *nptr);
int				ft_atoi_base(const char *nptr, uint8_t base);
char			*ft_itoa(int n);

///
///	MEMORY ALLOCs
///
void			*ft_calloc(size_t nmemb, size_t size);

///
///	STRINGs
///
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dst_size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dst_size);
char			*ft_strndup(const char *s, size_t len);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

///
///	PUTs
///
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

///
///	MATHs
///
unsigned int	ft_abs(int n);
unsigned long	ft_pow(int n, uint8_t pow);

///
///	Single-linked list element
///
typedef struct s_slist
{
	void			*content;
	struct s_slist	*next;
}	t_slist;

///
///	Double-linked list element
///
typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

///
///	Linked list
///
typedef struct s_list
{
	t_dlist	*head;
	t_dlist	*cur;
	t_dlist	*end;
}	t_list;

void			ft_lst_init(int args, ...);
t_dlist			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list *lst, void *content);
int				ft_lstsize(t_list lst);
// t_dlist			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list *lst, void *content);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list lst, void (*f)(t_list));
int				ft_lstindex(t_list lst);
t_list			ft_lstmap(t_list lst, void *(*f)(void *),
					void (*del)(void *));
// t_dlist			*ft_lstfirst(t_list *lst);

///
///	GNL
///

int				get_next_line(int fd, char **line);

#endif
