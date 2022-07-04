#include "game.h"

void Game( )
{
    int input = 0;
    srand ( (unsigned int) time(NULL) );
    do
    {
        menu( );
        printf ("请选择>:");
        scanf ("%d" , &input);
        switch (input)
        {
            case 0 : {printf("退出游戏\n"); break;}
            case 1 : {sanziqi( ); break;}
            default : {printf("输入错误\n"); break;}
        }
    }while(input);
    return;
}

void menu( )  //菜单
{
    printf ("******************************************\n");
    printf ("******    0.exit         1.play     ******\n");
    printf ("******************************************\n");
    return;
}

void sanziqi( )  //游戏函数 三子棋
{
    //数组-存放玩家和电脑走的棋盘信息
    char board[ROW][COL] = {0};  //全部空格
    char ret = 0;  // 
    InitBoard(board , ROW , COL );  //初始化棋盘
    DisplayBoard(board , ROW , COL );  //输出棋盘
    while (1)
    {
        PlayerMove(board , ROW , COL);  //玩家下棋
        DisplayBoard(board , ROW , COL);  //输出棋盘
        ret = IsWin(board , ROW , COL);  //判断玩家是否赢
        if (ret != 'C')
        {
            break;
        }
        ComputerMove(board , ROW , COL);  //电脑下棋
        DisplayBoard(board , ROW , COL);  //输出棋盘
        ret = IsWin(board , ROW , COL);  //判断电脑是否赢
        if (ret != 'C')
        {
            break;
        }
    }
    if (ret == '*')
    {
        printf ("你赢了\n");
    }
    else if (ret == '#')
    {
        printf ("惜败\n");
    }
    else if (ret == 'Q')
    {
        printf ("平局了\n");
    }
    return;
}

void InitBoard( char board[ROW][COL] , int row , int col )  //初始化棋盘
{
    int i = 0;
    for (i = 0 ; i < row ; i++)
    {
        int j = 0;
        for (j = 0 ; j < col ; j++)
        {
            board[i][j] = ' ';  //空格
        }
    }
    return;
}

//    |   |   
// ---|---|---
//    |   |   
// ---|---|---
//    |   |   
void DisplayBoard(char board[ROW][COL] , int row , int col )  //输出棋盘
{
    int i = 0;
    for (i = 0 ; i < ROW ; i++)
    {
        int j = 0;
        for (j = 0 ; j < col ; j++)  //输出一行数据
        {
            printf (" %c " , board[i][j]);
            if (j < col - 1)  //最后一个不输出'|'
            {
                printf ("|");
            }
        }
        printf ("\n");
        if (i < row - 1)  //输出分割行  最后一行不输出
        {
            for (j = 0 ; j < col ; j++)
            {
                printf ("---");
                if (j < col - 1)  //最后一个不输出'|'
                {
                    printf ("|");
                }
            }
        }
        printf ("\n");
    }
    return;
}

void PlayerMove(char board[ROW][COL] , int row , int col)  //玩家下棋
{
    int x = 0;
    int y = 0;
    printf ("玩家走\n");
    while(1)
    {
        printf ("请输入坐标:>");
        scanf ("%d%d" , &x , &y);
        //判断x,y的合法性
        if ( (x >= 1) && (x <= row) && (y >= 1) && (y <= col) )
        {
            if (board[x - 1][y - 1] == ' ')  //位置没有被下
            {
                board[x -1][y -1] = '*';  //玩家下棋标志
                break;
            }
            else 
            {
                printf ("坐标已经下过棋了,请重新输入!\n");
            }
        }
        else 
        {
            printf ("坐标非法,请重新输入!\n");
        }
    }
    return;
}

void ComputerMove(char board[ROW][COL] , int row , int col)  //电脑下棋
{
    int x = 0;
    int y = 0;
    printf ("电脑走:>\n");
    while(1)
    {
        x = rand( ) % row;
        y = rand( ) % col;
        //判断x,y的合法性
        if (board[x][y] == ' ')  //位置没有被下
        {
            board[x][y] = '#';  //电脑下棋标志
            break;
        }
    }
    return;
}

//告诉我们四种游戏状态
//玩家赢'*'  电脑赢'#'  平局'Q'  继续'C'
char IsWin(char board[ROW][COL] , int row , int col)
{
    int i = 0;
    for (i = 0 ; i < row ; i++)  //横三行
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }
    for (i = 0 ; i < col ; i++)  //竖三列
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
    }
    //两个对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    //判断是否平局
    if (1 == IsFull(board , ROW , COL))
    {
        return 'Q';
    }
    return 'C';
}

int IsFull(char board[ROW][COL] , int row , int col)  //数组满了:1 数组没有满:0
{
    int i = 0;
    int flag = 1;  //假设数组满了
    for (i = 0 ; i < row ; i++)
    {
        int j = 0;
        for (j = 0 ; j < col ; j++)
        {
            if (board[i][j] == ' ')
            {
                flag = 0;  //数组没有满
                break;
            }
        }
        if (0 == flag)
        {
            break;
        }
    }
    return flag;
}