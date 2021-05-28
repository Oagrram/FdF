/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:02:08 by oagrram           #+#    #+#             */
/*   Updated: 2020/02/29 12:02:32 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hex_dec(char *hex_val)
{
	int len;
	int base;
	int dec_val;
	int	i;

	len = ft_strlen(hex_val);
	base = 1;
	dec_val = 0;
	i = len - 1;
	while (i >= 0)
	{
		hex_val[i] = ft_toupper(hex_val[i]);
		if (hex_val[i] >= '0' && hex_val[i] <= '9')
		{
			dec_val += (hex_val[i] - 48) * base;
			base = base * 16;
		}
		else if (hex_val[i] >= 'A' && hex_val[i] <= 'F')
		{
			dec_val += (hex_val[i] - 55) * base;
			base = base * 16;
		}
		i--;
	}
	return (dec_val);
}
