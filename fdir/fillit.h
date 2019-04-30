/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:33:09 by mwunsch           #+#    #+#             */
/*   Updated: 2019/01/11 18:56:14 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include "../libft/libft.h"

void			ft_exit(int n);
void			ft_matrix_creation(int size);
void			fillit_check(char *tetrimino, size_t length);
int				fillit_recursion(int size);
void			ft_print_matrix();
void			size_tetrimino_check(char *tetrimino);
void			ft_matrix_del(char **matrix, int size);

extern int		g_t_num;
extern int		**g_tetrimino;
extern char		**g_matrix;
extern int		g_m_size;

#endif
