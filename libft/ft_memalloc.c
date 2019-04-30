/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:08:26 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/26 16:11:31 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;

	if (!size)
		return (NULL);
	p = (char *)malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);
	ft_bzero((void *)p, size);
	return (p);
}
