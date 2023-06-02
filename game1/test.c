#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
menu()
{
	printf("***************************\n");
	printf("***********1.play**********\n");
	printf("***********0.exit**********\n");
	printf("***************************\n");
}
void game()
{
	char board[ROW][COL] = { " " };
	char ret = 0;
	init(board, ROW, COL);
	display(board, ROW, COL);
	while (1)
	{
		playermove(board, ROW, COL);
		display(board, ROW, COL);
		ret = judge(board, ROW, COL);
		switch (ret)
		{
			case '#':
				printf("你赢了\n");
				break;
			case '*':
				printf("你输了\n");
				break;
			case 'F':
				printf("平局\n");
				break;
			case 'K':
				break;
		}
		if (ret != 'K')
			break;
		botmove(board, ROW, COL);
		display(board, ROW, COL);
		ret = judge(board, ROW, COL);
		switch (ret)
		{
		case '#':
			printf("你赢了\n");
			break;
		case '*':
			printf("你输了\n");
			break;
		case 'F':
			printf("平局\n");
			break;
		case 'K':
			break;
		}
		if (ret != 'K')
			break;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0 :
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}while(input);
	return 0;
}