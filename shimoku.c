#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void	displayMatrix(int	matrix[7][6])
{
	int	row;
	int	column;

	column = 5;
	while (column >= 0)
	{
		row = 0;
		while (row < 7)
		{
			printf("%5i", matrix[row][column]);
			++row;
		}
		printf("\n");
		--column;
	}
}

int	vertical(int	com, int	player, int	amount, int	table[7][6])
{
	int	i;
	int	h;

	i = 0;
	while (i < 7)
	{
		com = 0;
		player = 0;
		h = 0;
		while (h < 6)
		{
			if (com == amount)
			{
				return (1);
			}
			else if (player == amount)
			{
				return (2);
			}
			if (table[i][h] == 1)
			{
				com = com + 1;
				player = 0;
			}
			else if (table[i][h] == 2)
			{
				player = player + 1;
				com = 0;
			}
			else
			{
				com = 0;
				player = 0;
			}
			++h;
		}
		++i;
	}
	return (0);
}

int	horizontal(int	com, int	player, int	amount, int table[7][6])
{
	int	h;
	int	i;

	h = 0;
	while (h < 6)
	{
		com = 0;
		player = 0;
		i = 0;
		while (i < 7)
		{
			if (com == amount)
			{
				return (1);
			}
			else if (player == amount)
			{
				return (2);
			}
			if (table[i][h] == 1)
			{
				com = com + 1;
				player = 0;
			}
			else if (table[i][h] == 2)
			{
				player = player + 1;
				com = 0;
			}
			else
			{
				com = 0;
				player = 0;
			}
			++i;
		}
		++h;
	}
	return (0);
}

int	diagonal(int	com, int	player, int	amount, int	table[7][6])
{
	int	i;
	int	h;
	int	k;
	int	point;

	i = 0;
	while (i < 7)
	{
		com = 0;
		player = 0;
		h = 0;
		k = 0;
		while (h < 7 && k < 6)
		{
			point = table[i + h][k];
			if (com == amount)
			{
				return (1);
			}
			else if (player == amount)
			{
				return (2);
			}
			if (point == 1)
			{
				++com;
				player = 0;
			}
			else if (point == 2)
			{
				++player;
				com = 0;
			}
			else
			{
				com = 0;
				player = 0;
			}
			++h;
			++k;
		}
		++i;
	}
	com = 0;
	player = 0;
	i = 6;
	while (i >= 0)
	{
		com = 0;
		player = 0;
		h = 0;
		k = 0;
		while (h < 7 && k < 6)
		{
			point = table[h][i + k];
			if (com == amount)
			{
				return (1);
			}
			else if (player == amount)
			{
				return (2);
			}
			if (point == 1)
			{
				++com;
				player = 0;
			}
			else if (point == 2)
			{
				++player;
				com = 0;
			}
			else
			{
				com = 0;
				player = 0;
			}
			++h;
			++k;
		}
		--i;
	}
	i = 1;
	while (i < 3)
	{
		com = 0;
		player = 0;
		h = 0;
		k = 0;
		while (h < 5 && k < 6)
		{
			point = table[h][i + k];
			if (com == amount)
			{
				return (1);
			}
			else if (player == amount)
			{
				return (2);
			}
			if (point == 1)
			{
				++com;
				player = 0;
			}
			else if (point == 2)
			{
				++player;
				com = 0;
			}
			else
			{
				com = 0;
				player = 0;
			}
			++h;
			++k;
		}
		++i;
	}
	i = 6;
	while (i >= 0)
	{
		h = 0;
		k = 1;
		com = 0;
		player = 0;
		h = 0;
		k = 1;
		while (h < 7 && k < 6)
		{
			point = table[i - h][k];
			if (com == amount)
			{
				return (1);
			}
			else if (player == amount)
			{
				return (2);
			}
			if (point == 1)
			{
				++com;
				player = 0;
			}
			else if (point == 2)
			{
				++player;
				com = 0;
			}
			else
			{
				com = 0;
				player = 0;
			}
			++h;
			++k;
		}
		--i;
	}
	return (0);
}

int	random_number(int	min, int	max)
{
	return (min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX)));
}

int	check_mate(int	number, int	column_number, int	table[7][6], int	side)
{
	int	i;

	number = 0;
	while (number < 7)
	{
		column_number = 7;
		i = 0;
		while (i < 6)
		{
			if (table[number][i] == 0)
			{
				table[number][i] = side;
				column_number = i;
				break ;
			}
			++i;
		}
		++number;
		if (column_number != 7)
		{
			if (vertical(0, 0, 4, table)
				== side || horizontal(0, 0, 4, table) == side
				|| diagonal(0, 0, 4, table) == side)
			{
				if (side == 3)
				{
					table[number][column_number] = 1;
				}
				return (1);
			}
			else
			{
				table[number][column_number] = 0;
			}
		}
		++number;
	}
	return (0);
}

int	main(int	argc, char const	*argv[])
{
	void	displayMatrix(int	matrix[7][6]);
	int		vertical(int		com, int		player, int			amount, int			table[7][6]);
	int		horizontal(int		com, int		player, int			amount, int			table[7][6]);
	int		diagonal(int		com, int		player, int			amount, int			table[7][6]);
	int		check_mate(int		com_number, int	column_number, int	table[7][6], int	side);
	int		connect[7][6] =
	{
		{
			0, 0, 0, 0, 0, 0
		},
		{
			0, 0, 0, 0, 0, 0
		},
		{
			0, 0, 0, 0, 0, 0
		},
		{
			1, 0, 0, 0, 0, 0 
		},
		{ 
			0, 0, 0, 0, 0, 0 
		},
		{
			0, 0, 0, 0, 0, 0
		},
		{ 
			0, 0, 0, 0, 0, 0
		},
	};
	int	count;
	int	player_number;
	int	com_number;
	int	column_number;
	int	com;
	int	player;

	count = 0;
	player_number = 0;
	com_number = 0;
	column_number = 0;
	printf("OK!");
	while (true)
	{
		printf("count: %i\n", count);
		printf("-------------------------------------\n");
		printf("    1    2    3    4    5    6    7\n");
		printf("-------------------------------------\n");
		displayMatrix(connect);
		com = 0;
		player = 0;
		if (vertical(com, player, 4, connect) == 1 || horizontal(com, player, 4, connect) == 1 || diagonal(com, player, 4, connect) == 1)
		{
			printf("Boo!");
			return (0);
		}
		if (count % 2 == 1)
		{
		com = 0;
		player = 0;
			if (check_mate(0, 0, connect, 1))
			{
				printf("are you serious?\n");
			}
			else if (check_mate(0, 0, connect, 2))
			{
				printf("close!\n");
			}
			else
			{
				com_number = random_number(0, 6);
				int	i;
				i = 0;
				while (i < 6)
				{
					if (connect[com_number][i] == 0)
					{
						connect[com_number][i] = 1;
						break;
					}
					++i;
				}
			}
		}
		else
		{
			printf("Your Turn\n");
			printf("put in your peg\n");
			printf("Press (only) 1 ~ 7\n");
			scanf("%i", &player_number);
			int	i;
			i = 0;
			while (i < 6)
			{
				if (connect[player_number][i] == 0)
				{
					connect[player_number][i] = 2;
					break;
				}
				++i;
			}
		}
		count = count + 1;
	}
	return (0);
}
