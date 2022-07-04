#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void Game( );
void menu( );  //菜单
void sanziqi( );  //游戏函数
void InitBoard( char board[ROW][COL] , int row , int col );  //初始化棋盘
void DisplayBoard(char board[ROW][COL] , int row , int col );  //输出棋盘
void PlayerMove(char board[ROW][COL] , int row , int col);  //玩家下棋
void ComputerMove(char board[ROW][COL] , int row , int col);  //电脑下棋
char IsWin(char board[ROW][COL] , int row , int col);  //告诉我们四种游戏状态  //玩家赢'*'  电脑赢'#'  平局'Q'  继续'C'
int IsFull(char board[ROW][COL] , int row , int col);  //数组满了:1 数组没有满:0

#endif  //__GAME_H__