#ifndef STRING_UTILS_H
# define STRING_UTILS_H
int             is_delim(char c);
int             count_words(char *str);
int             ft_strlen(char *str);
int             substr_len(char *start);
void            skip_delims(char **str);
void            ft_strncpy(char *dest, char *src, unsigned int n);
int             ft_strcmp(char *s1, char *s2);
int             index_of(char *str, char c);
char            *ft_substr(char *str, int start, int end);
char            **ft_split(char *str);
int             ft_char_is_digit(char c);
int             ft_substr_is_numeric(char *str, int start, int end);
unsigned int    ft_abs_atoi(char *str);
#endif