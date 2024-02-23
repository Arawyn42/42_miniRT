# <div align="center">⚙️ libft (a [42](https://42perpignan.fr/) project) ⚙️</div>
## 📑 Introduction
The `libft` ('lib' stands for *library* and 'ft' for *forty-two*) is the very first project in the 42 cursus. The goal of this project is to recreate some of the standard GNU Libc functions, plus a few other miscellaneous ones for a grand total of 46 functions, each in their respective dot c file. This will enable us to reuse these functions afterwards on our other 42 projects, since standard C library such as `string.h` are not allowed.\
This project is crucial in the learning process of the C language, as many of the functions are easy and perfect for beginners.\
The goal of this project is not to reinvent the wheel, but to gain a better understanding of how all the basic functions works, how many computing power they use and memory space they require.

Subject : <a href=asset/en.subject.pdf>en.libft_subject.pdf<a/>
### My grade
[![nsalles's 42 Libft Score](https://badge42.coday.fr/api/v2/clshyl91d071301p436jjiyqr/project/3344498)](https://github.com/Coday-meric/badge42)

## Usage
Download `libft` and enter the repo :
```sh
git clone https://github.com/Floperatok/42-libft && cd 42-libft
```
Compile the project :
```sh
make && make clean
```
You can now use my `libft` on all your projects using the `libft.a` file :
```sh
gcc libft.a your_project.c
```

## 📚 Functions list
| Libc functions  | Prototype                                                                                              |
|----------------|---------------------|
| [ft_atoi](src/ft_atoi.c) | `int ft_atoi(const char *nptr)` |
| [ft_bzero](src/ft_bzero.c) | `void ft_bzero(void *s, size_t n)` |
| [ft_calloc](src/ft_calloc.c) | `void *ft_calloc(size_t nmemb, size_t size)` |
| [ft_isalnum](src/ft_isalnum.c) | `int ft_isalnum(int c)` |
| [ft_isalpha](src/ft_isalpha.c) | `int ft_isalpha(int c)` |
| [ft_isascii](src/ft_isascii.c) | `int ft_isascii(int c)` |
| [ft_isdigit](src/ft_isdigit.c) | `int ft_isdigit(int c)` |
| [ft_isprint](src/ft_isprint.c) | `int ft_isprint(int c)` |
| [ft_memchr](src/ft_memchr.c) | `void *ft_memchr(const void *s, int c, size_t n)` |
| [ft_memcmp](src/ft_memcmp.c) | `int ft_memcmp(const void *s1, const void *s2, size_t n)` |
| [ft_memcpy](src/ft_memcpy.c) | `void *ft_memcpy(void *dest, const void *src, size_t n)` |
| [ft_memmove](src/ft_memmove.c) | `void *ft_memmove(void *dst, const void *src, size_t len)` |
| [ft_memset](src/ft_memset.c) | `void *ft_memset(void *s, int c, size_t len)` |
| [ft_strchr](src/ft_strchr.c) | `char *ft_strchr(const char *s, int c)` |
| [ft_strdup](src/ft_strdup.c) | `char *ft_strdup(const char *s)` |
| [ft_strlcat](src/ft_strlcat.c) | `size_t ft_strlcat(char *dst, const char *src, size_t size)` |
| [ft_strlcpy](src/ft_strlcpy.c) | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` |
| [ft_strlen](src/ft_strlen.c) | `size_t ft_strlen(const char *s)` |
| [ft_strncmp](src/ft_strncmp.c) | `int ft_strncmp(const char *s1, const char *s2, size_t n)` |
| [ft_strnstr](src/ft_strnstr.c) | `char *ft_strnstr(const char *big, const char *little, size_t len)` |
| [ft_strrchr](src/ft_strrchr.c) | `char *ft_strrchr(const char *s, int c)` |
| [ft_tolower](src/ft_tolower.c) | `int ft_tolower(int c)` |
| [ft_toupper](src/ft_toupper.c) | `int ft_toupper(int c)` |


| Additional functions    | Prototype        | 
|------------------|---------------------|
| [ft_itoa](src/ft_itoa.c) | `char *ft_itoa(int n)` |
| [ft_putchar_fd](src/ft_putchar_fd.c) | `void ft_putchar_fd(char c, int fd)` |
| [ft_putendl_fd](src/ft_putendl_fd.c) | `void ft_putendl_fd(char *s, int fd)` |
| [ft_putnbr_fd](src/ft_putnbr_fd.c) | `void ft_putnbr_fd(int n, int fd)` |
| [ft_putstr_fd](src/ft_putstr_fd.c) | `void ft_putstr_fd(char *s, int fd)` |
| [ft_split](src/ft_split.c) | `char **ft_split(char const *s, char c)` |
| [ft_strjoin](src/ft_strjoin.c) | `char *ft_strjoin(char const *s1, char const *s2)` |
| [ft_striteri](src/ft_striteri.c) | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` |
| [ft_strmapi](src/ft_strmapi.c) | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` |
| [ft_strtrim](src/ft_strtrim.c) | `char *ft_strtrim(char const *s1, char const *set)` |
| [ft_substr](src/ft_substr.c) | `char *ft_substr(char const *s, unsigned int start, size_t len)` |


| Linked list - Bonus functions    | Prototype      |
|------------------|---------------------|
| [ft_lstadd_back](src/ft_lstadd_back.c) | `void ft_lstadd_back(t_list **lst, t_list *new)` |
| [ft_lstadd_front](src/ft_lstadd_front.c) | `void ft_lstadd_front(t_list **lst, t_list *new)` |
| [ft_lstclear](src/ft_lstclear.c) | `void ft_lstclear(t_list **lst, void (*del)(void *))` |
| [ft_lstdelone](src/ft_lstdelone.c) | `void ft_lstdelone(t_list *lst, void (*del)(void *))` |
| [ft_lstiter](src/ft_lstiter.c) | `void ft_lstiter(t_list *lst, void (*f)(void *))`|
| [ft_lstlast](src/ft_lstlast.c) | `t_list	*ft_lstlast(t_list *lst)` |
| [ft_lstmap](src/ft_lstmap.c) | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` |
| [ft_lstnew](src/ft_lstnew.c) | `t_list *ft_lstnew(void *content)` | 
| [ft_lstsize](src/ft_lstsize.c) | `int	ft_lstsize(t_list *lst)` |

| Personal functions | Prototype        |
|-|-|
| [get_next_line](https://github.com/Floperatok/42-get_next_line) | `char *get_next_line(int fd)` |
| [ft_printf](https://github.com/Floperatok/42-ft_printf) | `int ft_printf(const char *str, ...)` |

