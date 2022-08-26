/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:01:07 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/26 23:01:22 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

// remember to free the pointer
/*int main(int ac, char **av)
{
	char	**splitted_clues;
	int		*int_clues;
	int		**board;

	//remember to free
	splitted_clues = ft_split(av[1], ' ');
	//remember to free
	int_clues = atoi_clues(splitted_clues);
	init_board(&board);
	init_value(&board, 1);
	util_print_board(&board);
	return (0);
}*/

int	main(void)
{
	t_cell	**board;

	init_board(&board);
	init_values(&board);
	util_print_board(&board);
	return (0);
}