#include<stdio.h>

#include<windows.h>

#define FrameX 4	//x coordinate of game's window
#define FrameY 4	//y coordinate of game's window
#define Frame_height 20	//height of game's window
#define Frame_width 20	//width of game's window

int i;
int a[2];	//used for mark snake's tail's coordiantes

//declaration of snake's struture

struct Snake
{
	int x[99];	//snake's horizontal coordiante
	int y[99];	//snake's vertical coordinate
	int length;	//snake's length
	int speed;	//snake's speed
};

// mouse's position

void GamePosition(HANDLE g_hout, int x, int y)
{
	COORD pos;	//the position of a char on screen
	pos.X = x;	//horizontal coordinate
	pos.Y = y;	//vertical coordinate
	SetConsoleCursorPosition(g_hout, pos);	//set the mouse on screen
}

//initialize the snake

void init_snake(struct Snake* snake)
{
	snake->x[0] = FrameX + 2;	//initialize the snake's horizontal coordinate
	snake->y[0] = FrameY + Frame_height/2;	//initialize the snake's horizontal coordinate
	snake->length=3;	//initialize the snake's length
	snake->speed=300;	//initialize the snake's speed

	for (i=1; i < snake->length; i++)
	{
		snake->x[i] = snake-> x[i-1] + 2;
		snake->y[i] = snake-> y[i-1];
	}
}

//to move the snake

void move_snake(HANDLE hout, struct Snake* snake)
{
	GamePosition(hout, snake->x[0], snake->y[0]);
	printf(" ");	//clear the tail
	for (i=1; i < snake->length; i++)
	{
		snake->x[i-1] = snake->x[i];
		snake->y[i-1] = snake->y[i];
	}
}

//to print the snake

void show_snake(HANDLE hout, struct Snake* snake)
{
	for(i=0; i< snake->length; i++)
	{
		GamePosition(hout, snake->x[i], snake->y[i]);
		if (i == 0)
			printf("◇");
		else if (i == snake->length-1)
			printf("◎");
		else
			printf("■");
	}
}

// start game

void start_game()
{
	unsigned char ch = 77;
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	struct Snake s, *snake = &s;
	init_snake(snake);
	while(1)
	{
		a[0] = snake->x[0];
		a[0] = snake->y[0];
		ch = getch();
			switch(ch)
			{
				case 72:
				move_snake(hout, snake);
				snake->y[snake->length-1] -= 1;
				break;

				case 80:
				move_snake(hout, snake);
				snake->y[snake->length-1] += 1;
				break;

				case 75:
				move_snake(hout, snake);
				snake->x[snake->length-1] -= 2;
				break;

				case 77:
				move_snake(hout, snake);
				snake->x[snake->length-1] += 2;
				break;
			}
		show_snake(hout, snake);
	}
}

int main(void)
{
	start_game();
	return 0;
}

