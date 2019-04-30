/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:58:21 by mwunsch           #+#    #+#             */
/*   Updated: 2019/01/11 19:06:50 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		g_t_num;
int		**g_tetrimino;
char	**g_matrix;
int		g_m_size;

static void		ft_get_input(char *name, char **input)
{
	int			fd;
	char		*line;
	char		*tmp;
	int			i;
	int			sum_of_lines;

	((*input = ft_strnew(1)) == NULL) ? ft_exit(-1) : (1);
	((fd = open(name, O_RDONLY)) < 0) ? ft_exit(-1) : (1);
	sum_of_lines = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == '\0')
		{
			if ((tmp = ft_strjoin(*input, "\n")) == NULL)
				ft_exit(-1);
		}
		else
			((tmp = ft_strjoin(*input, line)) == NULL) ? ft_exit(-1) : (1);
		ft_memdel((void **)input);
		ft_memdel((void **)&line);
		*input = tmp;
		sum_of_lines++;
	}
	(close(fd) < 0 || i < 0 || sum_of_lines < 4) ? ft_exit(-1) : (1);
}

static void		ft_tetrimino(char *input, int i, int a, int x)
{
	if (!(g_tetrimino = (int **)malloc(sizeof(int *) * g_t_num)))
		ft_exit(-1);
	while (i < g_t_num)
	{
		a = 0;
		x = 0;
		if ((g_tetrimino[i] = (int *)malloc(sizeof(int) * 8)) == NULL)
			ft_exit(-1);
		while (input[a] && input[a] != '\n')
		{
			while (input[a] == '.')
				a++;
			if (input[a] == '#')
			{
				g_tetrimino[i][x + 0] = a / 4;
				g_tetrimino[i][x + 1] = a % 4;
				a++;
				x += 2;
			}
		}
		if (input[a])
			input = input + (a + 1);
		i++;
	}
}

static void		ft_tetrim_coordinates(void)
{
	int			i;
	int			x;

	i = 0;
	while (i < g_t_num)
	{
		x = 2;
		while (x < 7)
		{
			g_tetrimino[i][x + 0] = g_tetrimino[i][x + 0] - g_tetrimino[i][0];
			g_tetrimino[i][x + 1] = g_tetrimino[i][x + 1] - g_tetrimino[i][1];
			x += 2;
		}
		g_tetrimino[i][0] = 0;
		g_tetrimino[i][1] = 0;
		i++;
	}
}

static int		ft_matrix_size_count(void)
{
	int			n;

	n = 2;
	while (n * n < g_t_num * 4)
		n++;
	return (n);
}

int				main(int argc, char **argv)
{
	char		*input;

	if (argc != 2)
		ft_exit(-1);
	ft_get_input(argv[1], &input);
	fillit_check(input, ft_strlen(input));
	g_t_num = (ft_strlen(input) + 1) / 17;
	ft_tetrimino(input, 0, 0, 0);
	ft_tetrim_coordinates();
	g_m_size = ft_matrix_size_count();
	fillit_recursion(g_m_size);
	ft_print_matrix();
	free(input);
	ft_matrix_del(g_matrix, g_m_size);
	while (g_t_num - 1 > 0)
	{
		free(g_tetrimino[g_t_num - 1]);
		g_t_num--;
	}
	free(g_tetrimino);
	return (0);
}
