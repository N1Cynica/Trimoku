#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(char board[ROW][COL], int row, int col);
void display(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void botmove(char board[ROW][COL], int row, int col);
char judge(char board[ROW][COL], int row, int col);
