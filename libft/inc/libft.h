/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:32:41 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/19 22:34:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <float.h>

// BUF_SIZE (USED IN GNL AND MINITALK)
# define BUF_SIZE 1024

// FD_SIZE (MAX NUMBER OF SIMULTANEOUS FILES TO BE READ IN GNL)
# define FD_SIZE 42

// FD_MAX (USED IN MINITALK)
# define FD_MAX 1024

// ARENA_BUF (DEFAULT INITIAL SIZE OF AN ARENA WHEN CREATED)
# define ARENA_BUF 1024

// CODES FOR ERROR TRACKING
// SUCCESSFUL EXECUTION
# define SUCCESS 0
// UNSUCCEFUL EXECUTION
# define FAIL 1
// SUCCESSFUL EXECUTION
# define OK 1
// UNSUCCEFUL EXECUTION
# define KO 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_float
{
	float	whole;
	float	dec;
}	t_float;

typedef struct s_arena
{
	size_t			capacity;
	size_t			size;
	uint8_t			*data;
	struct s_arena	*next;
}	t_arena;

typedef struct s_vec
{
	uint8_t	*data;
	size_t	elem_size;
	size_t	capacity;
	size_t	len;
	t_arena	*arena;
}	t_vec;

// ASCII
// Checks if input int 'c' is alphabetic character in ascii
int		ft_isalpha(int c);
// Checks if input int 'c' is numeric character in ascii
int		ft_isdigit(int c);
// Checks if input int 'c' is numeric character or sign in ascii
int		ft_isnum(int c);
// Checks if input int 'c' is numeric character, period or sign in ascii
int		ft_isfloat(int c);
// Checks if input int 'c' is alphanumeric character in ascii
int		ft_isalnum(int c);
// Checks if input int 'c' is valid character in ascii
int		ft_isascii(int c);
// Checks if input int 'c' is printable character in ascii
int		ft_isprint(int c);
// Checks if input int 'c' is whitespace character in ascii
int		ft_isspace(int c);
// Checks if input int 'c' is '+' or '-'
int		ft_issign(int c);
// Checks if input char '*nptr' is a number with leading zeros
int		ft_isleadingzero(const char *nptr);
// Checks if input char '*nptr' is a valid float
int		ft_strisfloat(const char *nptr);
// Checks if input char '*nptr' is a valid integer
int		ft_strisnum(const char *nptr);
// If input int 'c' is lowercase ascii then it converts to uppercase
int		ft_toupper(int c);
// If input int 'c' is uppercase ascii then it converts to lowercase
int		ft_tolower(int c);
// Utility for applying ASCII checks to strings
int		ft_isstr(char *str, int (f)(int));
// Utility for applying ASCII checks to arrays of strings
int		ft_isarr(char **arr, int (f)(int));

// GNL
// Reads a file pointed to by int 'fd' and returns the first line or EOF as a
// string
char	*gnl(int fd);
char	*supergnl(int fd);

// LISTS
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *add);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *add);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// MEMORY
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

// NUMBERS
bool	ft_atoi(const char *nptr, int *nbr);
bool	ft_atof(const char *nptr, float	*nbr);
char	*ft_itoa(int n);
int		ft_power(int base, int exponent);
int		ft_digitcount(unsigned int n, unsigned int base);
double	ft_sin(double x);
double	ft_cos(double x);
double	ft_sqrt(double nbr);
bool	ft_naf(const char *nptr);
bool	ft_nan(const char *nptr);

// PRINTING
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putnbr(int n);
int		ft_putuint(unsigned int n);
int		ft_puthex(unsigned long nbr, const char *hex);
int		ft_putptr(va_list args);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *format, ...);

// STRINGS
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strnchr(const char *s, int c, int len);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// VECTORS
int		vec_alloc(t_vec **dst, t_arena *arena);
int		vec_new(t_vec *dst, size_t init_len, size_t elem_size);
void	vec_free(t_vec **src);
void	vec_data_free(t_vec *src);
int		vec_reset(t_vec *src);
int		vec_from(t_vec *dst, void *src, size_t len, size_t elem_size);
int		vec_copy(t_vec *dst, t_vec *src);
void	vec_printf(const t_vec *src, char printf_flag);
void	vec_putvars(const t_vec *src);
int		vec_resize(t_vec *src, size_t target_len);
int		vec_push(t_vec *dst, const void *src);
int		vec_pop(void *dst, t_vec *src);
void	*vec_get(t_vec *src, size_t index);
int		vec_check_and_grow(t_vec *dst, size_t extra);
int		vec_insert(t_vec *dst, void *src, size_t index);
int		vec_remove(t_vec *src, size_t index);
int		vec_append(t_vec *dst, t_vec *src);
int		vec_prepend(t_vec *dst, t_vec *src);
int		vec_inpend(t_vec *dst, t_vec *src, size_t after);
int		vec_iter(t_vec *src, void (*f)(void *));
int		vec_map(t_vec *dst, t_vec *src, void (*f)(void *));
int		vec_filter(t_vec *dst, t_vec *src, bool (*f)(void *));
int		vec_reduce(void *acc, t_vec *src, void (*f)(void *, void *));
int		vec_sort(t_vec *src, int (*f)(void *, void *));
void	vec_init(t_vec *dst, size_t init_len, size_t elem_size, t_arena *arena);
void	vec_set(t_vec *dst, uint8_t *data, size_t len, size_t capacity);
int		vec_safe_size(size_t a, size_t b, size_t *dst);
int		vec_exit(t_vec *dst);

// ARENA FUNCTIONS
int		ft_arena_init(t_arena **arena, size_t capacity);
int		ft_arena_alloc(t_arena *arena, void **ptr, size_t size);
int		ft_arena_reset(t_arena *arena);
int		ft_arena_free(t_arena **arena);
int		ft_arena_list_free(t_arena **arena);
void	ft_print_arena(const t_arena *arena);
void	ft_print_arena_list(const t_arena *arena);

#endif
