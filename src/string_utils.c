#include <stdlib.h>
#include "../include/string_utils.h"

int is_delim(char c) {
    return (c == ' ' || (c >= 9 && c <= 13));
}

int count_words(char *str) {
    int words;

    if (str == NULL)
        return (0);
    words = 0;
    while (*str) {
        if (!is_delim(*str)) {
           words++;
           while (*str && !is_delim(*str)) {
              ++str;
           }
        }
        else {
            ++str;
        }
    }
    return (words);
}

int substr_len(char *start) {
    int length;

    length = 0;
    while (*start && !is_delim(*start)) {
        ++start;
        ++length;
    }
    return (length);
}

int ft_strlen(char *str) {
    int length;

    length = 0;
    while (*str) {
        length++;
        str++;
    }
    return (length);
}

void skip_delims(char **str) {
    while (**str && is_delim(**str))
        (*str)++;
}

void ft_strncpy(char *dest, char *src, unsigned int n) {
    while (*src && n--) {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';
}

int ft_strcmp(char *s1, char *s2) {
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int index_of(char *str, char c) {
    int i;

    i = 0;
    while (str[i] && str[i] != c) {
        ++i;
    }
    if (!str[i]) {
        return (-1);
    }
    else {
        return (i);
    }
}

char *ft_substr(char *str, int start, int end) {
    int len;
    char *sub;

    if (!str || start < 0 || end < 0 || start >= end) {
        return (NULL);
    }
    len = end - start;
    sub = (char *) malloc((len + 1) * sizeof(char));
    if (!sub)
        return (NULL);
    ft_strncpy(sub, str + start, len);
    return (sub);
}

char **ft_split(char *str) {
    int words;
    char **splitted;
    int i;
    int len;

    words = count_words(str);
    splitted = (char **) malloc(sizeof(char *) * (words + 1));
    if (!splitted)
        return (NULL);
    i = 0;
    while (i < words) {
        skip_delims(&str);
        len = substr_len(str);
        splitted[i] = (char *) malloc((len + 1) * sizeof(char));
        if (!splitted[i]) {
            while (--i >= 0)
                free(splitted[i]);
            free(splitted);
            return (NULL);
        }
        ft_strncpy(splitted[i], str, len);
        str += len;
        ++i;
    }
    splitted[i] = NULL;
    return (splitted);
}

int ft_char_is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int ft_substr_is_numeric(char *str, int start, int end) {
    if (!str || start < 0 || end < 0 || start >= end || end > ft_strlen(str)) {
        return (0);
    }
    while (start < end && str[start] && ft_char_is_digit(str[start]))
        ++start;
    return (start == end);
}

unsigned int ft_abs_atoi(char *str) {
    unsigned int value;

    value = 0;
    while (*str && ft_char_is_digit(*str)) {
        value = (value * 10) + (*str - '0');
        ++str;
    }
    return (value);
}