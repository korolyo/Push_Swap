/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:02:51 by acollin           #+#    #+#             */
/*   Updated: 2021/08/04 22:03:41 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static char	**free_array(char **res)
//{
//	int	i;
//
//	i = 0;
//	while (res[i] != NULL)
//	{
//		free(res[i]);
//		i++;
//	}
//	free(res);
//	return (NULL);
//}
//
static int	count_words(char const *s, char c)
{
	int     count;
	size_t	flag;
	size_t	i;

	count = 0;
	flag = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		else if (flag)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

//static char	*result(size_t j, size_t reslen, char **res, char *str)
//{
//	size_t	i;
//
//	res[j] = (char *)ft_calloc(sizeof(char), (reslen + 1));
//	if (res[j] == NULL)
//	{
//		free_array(res);
//		return (NULL);
//	}
//	i = 0;
//	while (reslen > 0)
//	{
//		res[j][i] = *(str - reslen);
//		i++;
//		reslen--;
//	}
//	return (res[j]);
//}
//
//static void	*printres(char *str, char c, char **res, int count)
//{
//	size_t	j;
//	size_t	reslen;
//
//	j = 0;
//	reslen = 0;
//	while (count > 0)
//	{
//		while (*str == c)
//			str++;
//		if (*str != c)
//		{
//			while (*str != c && *str)
//			{
//				reslen++;
//				str++;
//			}
//			result(j, reslen, res, str);
//			reslen = 0;
//			j++;
//		}
//		count--;
//	}
//	res[j] = NULL;
//	return ((char **)res);
//}

void    *ft_free_all_split_alloc(char **split, size_t elts)
{
    size_t	i;

    i = 0;
    while (i < elts)
    {
        free(split[i]);
        i++;
    }
    free(split);
    return (NULL);
}

static void *ft_split_range(char **split, char const *s, t_split_next *st, t_split_next *lt)
{
    split[lt->length] = ft_substr(s, st->start, st->length);
    if (!split[lt->length])
        return (ft_free_all_split_alloc(split, lt->length));
    lt->length++;
    return (split);
}

static void *ft_split_by_char(char **split, char const *s, char c)
{
    size_t			i;
    t_split_next	st;
    t_split_next	lt;

    i = 0;
    lt.length = 0;
    lt.start = 0;
    while (s[i])
    {
        if (s[i] == c)
        {
            st.start = lt.start;
            st.length = (i - lt.start);
            if (i > lt.start && !ft_split_range(split, s, &st, &lt))
                return (NULL);
            lt.start = i + 1;
        }
        i++;
    }
    st.start = lt.start;
    st.length = (i - lt.start);
    if (i > lt.start && i > 0 && !ft_split_range(split, s, &st, &lt))
        return (NULL);
    split[lt.length] = 0;
    return (split);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**res;
	int     count;

	count = count_words(s, c);
	str = (char *)s;
	while (*str == c)
		str++;
	res = (char **) ft_calloc(sizeof(s), (count + 1));
	if (res == NULL)
		return (NULL);
    if (!ft_split_by_char(res, s, c))
        return (NULL);
	return ((char **)res);
}
