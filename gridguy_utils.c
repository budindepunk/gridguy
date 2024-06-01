#include "gridguy.h"
#include <stdio.h>
#include <termios.h>

void print_horizontal(int grid_size)
{
	int i = 0;
	char *block = "---+";

	printf("+");
	while (i < grid_size)
	{
		printf("%s", block);
		i++;
	}
	printf("\n");
	return ;
}

void handle_flag(int flag)
{
	switch (flag)
		{
			case 1:
				printf("\n");
				break;
			case 2:
				printf("        " REDB "too far!" reset "\n");
				break ;
			case 3:
				printf("        " YELB "what?" reset "\n");
				break ;
		}
}
int my_getchar(void)
{
	// this implementation of getchar i got from here:
	// https://gist.github.com/physacco/5aed1c3a31ce7932c1b9461e979203de
	// this one lets me receive the key input without needing to press enter
	
	int c;
	struct termios oldt;
	struct termios newt;

	tcgetattr(0, &oldt); // store settings. 0 is stdin
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO); // change in settings

	tcsetattr(0, TCSANOW, &newt); // apply
	c = getchar();
	tcsetattr(0, TCSANOW, &oldt); // restore

	return (c);
}