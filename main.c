/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:01:07 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/26 17:01:14 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"



int main(int ac, char **av)
{
	int		i;
	char	**splitted_clues;
	int		*int_clues;

	splitted_clues = ft_split(av[1], ' ');
	int_clues = char_to_int_clues(splitted_clues);
	init_board();
	// remember to free the pointer
	//util_print_arr(int_clues);
	return (0);
}