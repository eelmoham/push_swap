/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:01:48 by eelmoham          #+#    #+#             */
/*   Updated: 2021/11/30 18:21:20 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	sjoin_len;
	size_t	index;

	sjoin_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *) malloc(sjoin_len);
	if (!strjoin)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
		strjoin[index++] = *s1++;
	while (*s2 != '\0')
		strjoin[index++] = *s2++;
	strjoin[index] = '\0';
	return (strjoin);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		count;
	int		i;

	i = 0;
	count = ft_strlen(src);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	ln;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	ln = ft_strlen(s);
	if (start >= ln)
		return (ft_strdup(""));
	if (len >= ln - start)
		ptr = (char *)malloc(ln - start + 1);
	else
		ptr = (char *)malloc(len + 1);
	if (ptr == 0)
		return (0);
	while (s[start] != 0 && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
