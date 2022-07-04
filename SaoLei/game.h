#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY_COUNT 10

void Game();
void menu();                                                                                            //菜单
void saolei();                                                                                          //游戏函数
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);                                   //初始化布置雷的棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);                                            //输出棋盘
void SetMine(char board[ROWS][COLS], int row, int col);                                                 //布置雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);                          //排查雷(扫雷)
int get_mine_count(char mine[ROWS][COLS], int x, int y);                                                //计算x,y坐标周围有几个雷
void Diffuse(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int *win_D); //当扫雷周围没有雷时 向周围扩散 提高游戏可玩性

#endif //__GAME_H__