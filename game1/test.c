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
				printf("��Ӯ��\n");
				break;
			case '*':
				printf("������\n");
				break;
			case 'F':
				printf("ƽ��\n");
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
			printf("��Ӯ��\n");
			break;
		case '*':
			printf("������\n");
			break;
		case 'F':
			printf("ƽ��\n");
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
		printf("��ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0 :
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	}while(input);
	return 0;
}