#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void init(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row; i++)
	{
		for (j = 0;j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void display(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
				printf("|");
			else
				printf("\n");
		}
		if (i < row - 1)
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
				else
					printf("\n");
			}
	}
}

void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋：\n");
	while (1)
	{
		printf("请输入坐标（格式：行空格列）：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("棋格被占用!\n");
			}
		}
		else
		{
			printf("坐标非法!\n");
		}
	}
}

//void botmove(char board[ROW][COL], int row, int col)
//{
//	printf("电脑下棋：\n");
//	int x = 0;
//	int y = 0;
//	while(board[x][y] != ' ')
//	{
//		x = rand() % row;
//		y = rand() % col;
//	}
//	board[x][y] = '*';
//}

char judge(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][0];
	}
	for (j = 0;j < col;j++)
	{
		if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
			return board[1][j];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
				return 'K';
			if (i == row - 1 && j == col - 1 && board[i][j] != ' ')
				return 'F';
		}
	}
}

void botmove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋：\n");
	int i = 0;
	int j = 0;
	int k = 0;
	int x = 0;
	int y = 0;
	int arrx = 0;
	int arry = 0;
	int warrx = 0;
	int warry = 0;
	int sarrx = 0;
	int sarry = 0;
	int countP = 0;
	int countB = 0;
	int countS = 0;
	for (x = 0;x < row;x++)
	{
		countP = 0;
		countB = 0;
		countS = 0;
		for (y = 0;y < row;y++)
		{
			if (board[x][y] == '#')
				countP = countP + 1;
			if (board[x][y] == '*')
				countB = countB + 1;
			if (board[x][y] == ' ')
				countS = countS + 1;
		}
		if (countP == 2)
		{
			for (y = 0;y < row;y++)
			{
				if (board[x][y] == ' ')
				{
					arrx = x;
					arry = y;
					i = 1;
				}
			}
		}
		if (countB == 2)
		{
			for (y = 0;y < row;y++)
			{
				if (board[x][y] == ' ')
				{
					warrx = x;
					warry = y;
					j = 1;
				}
			}
		}
		if (countS == 2)
		{
			for (y = 0;y < row;y++)
			{
				if (board[x][y] == '*')
				{
					for (y = 0;y < row;y++)
					{
						if (board[x][y] == ' ')
						{
							sarrx = x;
							sarry = y;
							k = 1;
						}
					}
				}
			}
		}
	}
	for (y = 0;y < row;y++)
	{
		countP = 0;
		countB = 0;
		countS = 0;
		for (x = 0;x < row;x++)
		{
			if (board[x][y] == '#')
				countP = countP + 1;
			if (board[x][y] == '*')
				countB = countB + 1;
			if (board[x][y] == ' ')
				countS = countS + 1;
		}
		if (countP == 2)
		{
			for (x = 0;x < row;x++)
			{
				if (board[x][y] == ' ')
				{
					arrx = x;
					arry = y;
					i = 1;
				}
			}
		}
		if (countB == 2)
		{
			for (x = 0;x < row;x++)
			{
				if (board[x][y] == ' ')
				{
					warrx = x;
					warry = y;
					j = 1;
				}
			}
		}
		if (countS == 2)
		{
			for (x = 0;x < row;x++)
			{
				if (board[x][y] == '*')
				{
					for (x = 0;x < row;x++)
					{
						if (board[x][y] == ' ')
						{
							sarrx = x;
							sarry = y;
							k = 1;
						}
					}
				}
			}
		}
	}
	countP = 0;
	countB = 0;
	countS = 0;
	for (x = 0;x < row;x++)
	{
		if (board[x][x] == '#')
			countP = countP + 1;
		if (board[x][x] == '*')
			countB = countB + 1;
		if (board[x][x] == '*')
			countS = countS + 1;
	}
	if (countP == 2)
	{
		for (x = 0;x < row;x++)
		{
			if (board[x][x] == ' ')
			{
				arrx = x;
				arry = x;
				i = 1;
			}
		}
	}
	if (countB == 2)
	{
		for (x = 0;x < row;x++)
		{
			if (board[x][x] == ' ')
			{
				warrx = x;
				warry = x;
				j = 1;
			}
		}
	}
	if (countS == 2)
	{
		for (x = 0;x < row;x++)
		{
			if (board[x][x] == ' ')
			{
				sarrx = x;
				sarry = x;
				k = 1;
			}
		}
	}
	countP = 0;
	countB = 0;
	countS = 0;
	for (x = 0;x < row;x++)
	{
		if (board[x][2 - x] == '#')
			countP = countP + 1;
		if (board[x][2 - x] == '*')
			countB = countB + 1;
		if (board[x][2 - x] == '*')
			countS = countS + 1;
	}
	if (countP == 2)
	{
		for (x = 0;x < row;x++)
		{
			if (board[x][2 - x] == ' ')
			{
				arrx = x;
				arry = 2 - x;
				i = 1;
			}
		}
	}
	if (countB == 2)
	{
		for (x = 0;x < row;x++)
		{
			if (board[x][2 - x] == ' ')
			{
				warrx = x;
				warry = 2 - x;
				j = 1;
			}
		}
	}
	if (countS == 2)
	{
		for (x = 0;x < row;x++)
		{
			if (board[x][2 - x] == '*')
			{
				for (x = 0;x < row;x++)
				{
					if (board[x][2 - x] == ' ')
					{
						sarrx = x;
						sarry = 2 - x;
						k = 1;
					}
				}
			}
		}
	}
	if (board[1][1] == ' ')
	{
		board[1][1] = '*';
	}
	else
	{
		if (j == 1)
		{
			board[warrx][warry] = '*';
		}
		else
		{
			if (i == 1)
			{
				board[arrx][arry] = '*';
			}
			else
			{
				if (k == 1)
				{
					board[sarrx][sarry] = '*';
				}
				else
				{
					while(board[x][y] != ' ')
					{
					x = rand() % row;
					y = rand() % col;
					}
					board[x][y] = '*';
				}
			}
		}
	}
}


