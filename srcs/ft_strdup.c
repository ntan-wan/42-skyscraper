/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:15:30 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/28 21:47:59 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	size_t	i;
	char	*ptr;

	i = 0;
	str_len = utils_strlen(str);
	ptr = (char *)malloc((str_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
