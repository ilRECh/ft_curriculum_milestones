#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

enum
{
	TRUE = 1,
	MAX_RANK = 1000000000,
};

typedef struct s_list
{
	unsigned long	value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isspace(int c);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t dst_size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dst_size);
char			*ft_strndup(const char *s, size_t len);
unsigned int	ft_abs(int n);
void			ft_putchar_fd(char c, int fd);
t_list			*ft_lstnew(uint64_t value);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstclear(t_list **lst);
void			ft_lstnormalizer(t_list *lst);
void			fill_with(char c, unsigned int amount);
void			ft_putnbr_base(uint64_t nbr, uint8_t base, char *symbs);
size_t			count_symbs(uint64_t nbr, uint8_t base);
int32_t			ft_power(int32_t nbr, int32_t power);
void			ft_bignummultiply(t_list **lst, uint64_t value, int16_t power);
void			ft_bignumaddition(t_list *lst, t_list **extra);

#endif
