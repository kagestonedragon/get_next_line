/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:40:45 by emedea            #+#    #+#             */
/*   Updated: 2019/05/20 14:48:11 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char *duplicate;
	char *dbegin;

	duplicate = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (duplicate == NULL)
		return (NULL);
	dbegin = duplicate;
	while (*s1 != '\0')
	{
		*duplicate = *s1;
		duplicate++;
		s1++;
	}
	*duplicate = '\0';
	return (dbegin);
}
