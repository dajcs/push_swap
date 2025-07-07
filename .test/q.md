Can you help me writing a C program called `push_swap`?
- the program calculates and displays the shortest sequence of `push_swap` instructions needed to sort the given integers.

## The rules

- there are 2 [stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) named `a` and `b`
- at the beginning:
  - the stack `a` contains a random number of unique negative and/or positive integers
  - the stack `b` is empty
- the goal is to sort the numbers in stack `a` in ascending order. To achieve this, we can use the following operations:
  - `sa` (swap a): Swap the first 2 elements at the top  of stack `a`. Do nothing if there is only one element or none.
  - `sb` (swap b): Swap the first 2 elements at the top  of stack `b`. Do nothing if there is only one element or none.
  - `ss` do `sa` and `sb` at the same time.
  - `pa` (push a): Take the first element at the top of `b` and put it on top of `a`. Do nothing if `b` is empty.
  - `pb` (push b): Take the first element at the top of `a` and put it on top of `b`. Do nothing if `a` is empty.
  - `ra` (rotate a): Shift up all elements of stack `a` by 1. The first element becomes the last one.
  - `rb` (rotate b): Shift up all elements of stack `b` by 1. The first element becomes the last one.
  - `rr` do `ra` and `rb` at the same time.
  - `rra` (reverse rotate a): Shift down all elements of stack `a` by 1. The last element becomes the first one.
  - `rrb` (reverse rotate b): Shift down all elements of stack `b` by 1. The last element becomes the first one.
  - `rrr` do `rra` and `rrb` at the same time.

## Example

```bash
Init a and b:
2
1
3
6
5
8
_ _
a b
```

```bash
Exec sa:
1
2
3
6
5
8
_ _
a b
```

```bash
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
```

```bash
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
```

```bash
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
```

```bash
Exec sa:
5 3
6 2
8 1
_ _
a b
```

```bash
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
```

The integers got sorted in 12 instructions. Could be done better?

## the `push_swap` program details

- name: `push_swap`
- files: Makefile, *.h, *.c
- Makefile: NAME, all, clean, fclean, re
- Arguments: stack a: A list of integers
- Libft authorized, see `libft.h` at the end
- Allowed external functions: `read`, `write`, `malloc`, `free`, `exit` and any function from `libft`

- global variables are forbidden
- arguments: takes as an argument the stack - a formatted list of integers. The first argument should be at the top of the stack
- the program must display the shortest sequence of instructions needed to sort stack `a` with the smallest number at the top
- the instructions must be separated by `\n`
- the goal is to sort the stack with the lowest possible number of operations.
- if no arguments, just return the prompt.
- if error, display "Error\n" on the standard error. Example of errors: some arguments not integers, some arguments exceeding the integer limits, and/or the presence of ducplicate numbers.

```bash
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```

A binary will be provided to evaluate the program. It will work as follows:

```bash
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
```

If the `checker_OS` displays `KO` this means that the `push_swap` program instructions are not sorting the numbers.

### Project validation:
- sort 100 random numbers in less than 700 operations
- sort 500 random numbers in less than 5500 operations

### The Norminette rules should be adhered:
- only while loops are allowed
- ternary operators are not allowed
- variable definition and variable assignment in separate rows
- one empty line after variable definitions, no other empty lines
- only one variable definition/assignment on a line
- only one instruction on a single line
- comments inside the function not allowed, the comments should be placed above the function prototype
- max 80 characters / line
- max 4 parameters / function
- max 5 variables / function
- max 25 lines / function
- max 5 functions / .c file

### libft.h

```c

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// from ft_printf.h
# include <stdarg.h>
# include <stdint.h>

// from get_next_line
# include <limits.h>
# define BUFFER_SIZE 2048
# define OPEN_MAX 1024

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ******************* Added from ft_printf.h ****************************** */

typedef struct s_flags
{
	int				minus;
	int				zero;
	int				width;
	int				dot;
	int				precision;
	int				hash;
	int				space;
	int				plus;
}					t_flags;

int					ft_printf(const char *format, ...);

// parsing and dispatching
int					ft_eval_format(va_list args, const char *format, int *i);
t_flags				ft_init_flags(void);
void				ft_parse_flags_width_prec(t_flags *flags,
						const char *format, int *i);
int					ft_dispatch(char type, t_flags flags, va_list args);

// print functions for each conversion specifier
int					ft_print_char(char c, t_flags flags);
int					ft_print_str(char *str, t_flags flags);
int					ft_print_ptr(uintptr_t ptr, t_flags flags);
int					ft_print_nbr(int n, t_flags flags);
int					ft_print_unsigned(unsigned int n, t_flags flags);
int					ft_print_hex(unsigned int n, t_flags flags, char format);

// utility functions
int					ft_print_padding(char c, int len);
char				*ft_utoa(unsigned int n);
void				ft_strrev(char *s, int len);
int					ft_ptr_len(uintptr_t num);
void				ft_put_ptr(uintptr_t num);

/* ******************* Added from get_next_line ************************* */

char				*get_next_line(int fd);
size_t				gnl_strlen(char *s);
char				*gnl_strchr(char *s, int c);
char				*gnl_strjoin(char *s1, char *s2);
char				*gnl_substr(char *s, unsigned int start, size_t len);

#endif
```
