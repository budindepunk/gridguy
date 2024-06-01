#include "gridguy.h"

static void draw_grid(int grid_size, int guy_position[], int *cells)
{
	char *vertical_line = "|";
	char *no_guy = "   "; // three spaces
	char *guy = " o ";
	int x, y;

	y = 0;
	while (y < grid_size)
	{
		x = 0;
		print_horizontal(grid_size);
		while (x < grid_size)
		{
			printf("%s", vertical_line);
			if (guy_position[0] == x && guy_position[1] == y)
			{
				printf(MAGB "%s", guy);
				printf(reset);
			}
			else
			{
				if (cells[y * grid_size + x] == 1)
				{
					printf(CYNB "%s", no_guy);
					printf(reset);
				}
				else
					printf("%s", no_guy);
			}
			x++;
		}
		printf("%s\n", vertical_line);
		y++;
	}
	print_horizontal(grid_size);
}

int check_full(int *cells, int grid_size)
{
	int i = 0;

	while (i < (grid_size * grid_size))
	{
		if (cells[i] == 0)
			return (0);
		i++;
	}
	printf("        " GRNB "yaaaayyy!" reset "\n");
}

static int update_position(char input, int flag, int guy_position[], int grid_size)
{
		if (input == 'a' && !(guy_position[0] - 1 < 0))
		{
			guy_position[0]--;
			flag = 1;
		}
		else if (input == 'd' && !(guy_position[0] + 1 > grid_size - 1))
		{	
			guy_position[0]++;
			flag = 1;
		}
		else if (input == 'w' && !(guy_position[1] - 1 < 0))
		{
			guy_position[1]--;
			flag = 1;
		}
		else if (input == 's' && !(guy_position[1] + 1 > grid_size - 1))
		{
			guy_position[1]++;
			flag = 1;
		}
		else if (input != 'a' && input != 'd' && input != 's' && input != 'w')
			flag = 3;
		return (flag);
}

int main(int argc, char *argv[])
{
	static int guy_position[2] = {0, 0};
	int *cells;
	int grid_size = 5;
	char input;
	int flag; // 1 = all good; 2 = too far; 3 = invalid input
	
	system("clear"); // everything below this
	if (argc > 1 && atoi(argv[1]))
		grid_size = atoi(argv[1]);

	cells = calloc((grid_size * grid_size), sizeof(int));
	cells[guy_position[1] * grid_size + guy_position[0]] = 1;
	draw_grid(grid_size, guy_position, cells);
	while (1)
	{
		input = my_getchar();
		flag = 2;
		
		if (input == '\n')
			continue ;
		else if (input == 'q')
		{
			system("clear");
			break ;
		}
		flag = update_position(input, flag, guy_position, grid_size);
		cells[guy_position[1] * grid_size + guy_position[0]] ^= 1;

		system("clear");
		draw_grid(grid_size, guy_position, cells);
		check_full(cells, grid_size);
		handle_flag(flag);
	}
	free(cells);
	return (0);
}


