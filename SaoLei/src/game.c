
#include "game.h"

void Game()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择>:");
        scanf("%d", &input);
        switch (input)
        {
        case 0:
        {
            printf("退出游戏\n");
            break;
        }
        case 1:
        {
            saolei();
            break;
        }
        default:
        {
            printf("输入错误\n");
            break;
        }
        }
    } while (input);
    return;
}

void menu() //菜单
{
    printf("******************************************\n");
    printf("******    0.exit         1.play     ******\n");
    printf("******************************************\n");
    return;
}

// 1.布置雷
// 2.排查雷(扫雷)
// 两个数组一个放雷的信息 一个放排查雷的信息
void saolei() //游戏函数
{
    char mine[ROWS][COLS] = {0};      // ROWS*COLS  布置雷的棋盘  '0'表示没有雷 '1'表示有雷
    char show[ROWS][COLS] = {0};      // ROWS*COLS  排查雷的棋盘  '0'~'8' 表示周围有几个雷 初始化用'*'
    InitBoard(mine, ROWS, COLS, '0'); //初始化布置雷的棋盘
    InitBoard(show, ROWS, COLS, '*'); //初始化排查雷的棋盘
    // DisplayBoard(mine , ROW , COL);  //输出布置雷的棋盘
    printf("本次游戏有%d颗雷.\n" , EASY_COUNT);
    DisplayBoard(show, ROW, COL);   //输出排查雷的棋盘
    SetMine(mine, ROW, COL);        //布置雷
    DisplayBoard(mine, ROW, COL);   //输出布置雷的棋盘
    FindMine(mine, show, ROW, COL); //排查雷(扫雷)
    return;
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) //初始化棋盘
{
    int i = 0;
    for (i = 0; i < rows; i++)
    {
        int j = 0;
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
    return;
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) //输出棋盘  ROW*COL
{
    int i = 0;
    int j = 0;
    //打印列号
    for (i = 0; i <= row; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        //打印行号
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return;
}

void SetMine(char board[ROWS][COLS], int row, int col) //布置雷
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = (rand() % row) + 1;
        int y = (rand() % col) + 1;
        if (board[x][y] == '0') //判断是否有雷
        {
            board[x][y] = '1';
            count--;
        }
    }
    return;
}

// void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) //排查雷(扫雷)
// {
//     int x = 0;
//     int y = 0;
//     int win = 0;
//     // 9*9-10=71
//     while (win < row * col - EASY_COUNT)
//     {
//         printf("请输入排查雷的坐标:>");
//         scanf("%d%d", &x, &y);
//         if (x >= 1 && x <= row && y >= 1 && x <= col) //坐标合法
//         {
//             if (mine[x][y] == '1') // 1.踩雷
//             {
//                 printf("很遗憾,你被炸死了.\n");
//                 DisplayBoard(mine, row, col); //输出布置雷的棋盘
//                 break;
//             }
//             else if (mine[x][y] == '0' && show[x][y] != '*')
//             {
//                 printf("这个位置已经排查过了,请重新输入\n");
//             }
//             else //不是雷 并且没有排查过
//             {
//                 int count = get_mine_count(mine, x, y); //计算x,y坐标周围有几个雷
//                 show[x][y] = count + '0';
//                 DisplayBoard(show, ROW, COL); //输出排查雷的棋盘
//                 win++;
//             }
//         }
//         else
//         {
//             printf("输入坐标非法,请重新输入!\n");
//         }
//     }
//     if (win == row * col - EASY_COUNT)
//     {
//         printf("恭喜你,排雷成功.\n");
//         DisplayBoard(mine, ROW, COL); //输出布置雷的棋盘
//     }
//     return;
// }

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) //排查雷(扫雷)
{
    int x = 0;
    int y = 0;
    int win = 0;
    // 9*9-10=71
    while (win < row * col - EASY_COUNT)
    {
        printf("请输入排查雷的坐标(行 列):>");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && x <= col) //坐标合法
        {
            if (mine[x][y] == '1') // 1.踩雷
            {
                printf("很遗憾,你被炸死了.\n");
                DisplayBoard(mine, row, col); //输出布置雷的棋盘
                break;
            }
            else if (mine[x][y] == '0' && show[x][y] != '*')
            {
                printf("这个位置已经排查过了,请重新输入\n");
            }
            else //不是雷 并且没有排查过
            {
                int count = get_mine_count(mine, x, y); //计算x,y坐标周围有几个雷
                if (count == 0)                         //扫雷周围没有雷
                {
                    // show[x][y] = ' ';
                    Diffuse(mine, show, ROW, COL, x, y, &win);
                }
                else //扫雷周围有雷
                {
                    show[x][y] = count + '0';
                    win++;
                }
                DisplayBoard(show, ROW, COL); //输出排查雷的棋盘
            }
        }
        else
        {
            printf("输入坐标非法,请重新输入!\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        printf("恭喜你,排雷成功.\n");
        DisplayBoard(mine, ROW, COL); //输出布置雷的棋盘
    }
    return;
}

int get_mine_count(char mine[ROWS][COLS], int x, int y) //计算x,y坐标周围有几个雷
{
    return mine[x - 1][y] +
           mine[x - 1][y + 1] +
           mine[x][y + 1] +
           mine[x + 1][y + 1] +
           mine[x + 1][y] +
           mine[x + 1][y - 1] +
           mine[x][y - 1] +
           mine[x - 1][y - 1] - 8 * '0';
}

void Diffuse(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int *win_D) //当扫雷周围没有雷时 向周围扩散 提高游戏可玩性
{
    int count = 0;
    count = get_mine_count(mine, x, y);
    if (mine[x][y] == '1') //递归函数出口 当这个坐标是地雷
    {
        return;
    }
    else if (mine[x][y] == '0' && count != 0) //递归函数出口 当这个坐标围有地雷
    {
        show[x][y] = count + '0';
        (*win_D)++;
        return;
    }
    else if (mine[x][y] == '0' && count == 0) //当这个坐标不是地雷并且这个坐标周围没有地雷  对周围8个坐标进行递归
    {
        show[x][y] = ' '; //空格
        (*win_D)++;
        if (x >= 1 && x <= row && y >= 1 && y <= col) //在外面的一圈不进行递归
        {
            if (show[x - 1][y] == '*' && x - 1 >= 1) //对已经递归的不进行递归
            {
                Diffuse(mine, show, ROW, COL, x - 1, y, win_D);
            }
            if (show[x - 1][y + 1] == '*' && x - 1 >= 1 && y + 1 <= col)
            {
                Diffuse(mine, show, ROW, COL, x - 1, y + 1, win_D);
            }
            if (show[x][y + 1] == '*' && y + 1 <= col)
            {
                Diffuse(mine, show, ROW, COL, x, y + 1, win_D);
            }
            if (show[x + 1][y + 1] == '*' && x + 1 <= row && y + 1 <= col)
            {
                Diffuse(mine, show, ROW, COL, x + 1, y + 1, win_D);
            }

            if (show[x + 1][y] == '*' && x + 1 <= row)
            {
                Diffuse(mine, show, ROW, COL, x + 1, y, win_D);
            }

            if (show[x + 1][y - 1] == '*' && x + 1 <= row && y - 1 >= 1)
            {
                Diffuse(mine, show, ROW, COL, x + 1, y - 1, win_D);
            }

            if (show[x][y - 1] == '*' && y - 1 >= 1)
            {
                Diffuse(mine, show, ROW, COL, x, y - 1, win_D);
            }

            if (show[x - 1][y - 1] == '*' && x - 1 >= 1 && y - 1 >= 1)
            {
                Diffuse(mine, show, ROW, COL, x - 1, y - 1, win_D);
            }
        }
    }
}