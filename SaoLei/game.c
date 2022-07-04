
#include "game.h"

void Game()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("��ѡ��>:");
        scanf("%d", &input);
        switch (input)
        {
        case 0:
        {
            printf("�˳���Ϸ\n");
            break;
        }
        case 1:
        {
            saolei();
            break;
        }
        default:
        {
            printf("�������\n");
            break;
        }
        }
    } while (input);
    return;
}

void menu() //�˵�
{
    printf("******************************************\n");
    printf("******    0.exit         1.play     ******\n");
    printf("******************************************\n");
    return;
}

// 1.������
// 2.�Ų���(ɨ��)
// ��������һ�����׵���Ϣ һ�����Ų��׵���Ϣ
void saolei() //��Ϸ����
{
    char mine[ROWS][COLS] = {0};      // ROWS*COLS  �����׵�����  '0'��ʾû���� '1'��ʾ����
    char show[ROWS][COLS] = {0};      // ROWS*COLS  �Ų��׵�����  '0'~'8' ��ʾ��Χ�м����� ��ʼ����'*'
    InitBoard(mine, ROWS, COLS, '0'); //��ʼ�������׵�����
    InitBoard(show, ROWS, COLS, '*'); //��ʼ���Ų��׵�����
    // DisplayBoard(mine , ROW , COL);  //��������׵�����
    printf("������Ϸ��%d����.\n" , EASY_COUNT);
    DisplayBoard(show, ROW, COL);   //����Ų��׵�����
    SetMine(mine, ROW, COL);        //������
    DisplayBoard(mine, ROW, COL);   //��������׵�����
    FindMine(mine, show, ROW, COL); //�Ų���(ɨ��)
    return;
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) //��ʼ������
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

void DisplayBoard(char board[ROWS][COLS], int row, int col) //�������  ROW*COL
{
    int i = 0;
    int j = 0;
    //��ӡ�к�
    for (i = 0; i <= row; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        //��ӡ�к�
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return;
}

void SetMine(char board[ROWS][COLS], int row, int col) //������
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = (rand() % row) + 1;
        int y = (rand() % col) + 1;
        if (board[x][y] == '0') //�ж��Ƿ�����
        {
            board[x][y] = '1';
            count--;
        }
    }
    return;
}

// void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) //�Ų���(ɨ��)
// {
//     int x = 0;
//     int y = 0;
//     int win = 0;
//     // 9*9-10=71
//     while (win < row * col - EASY_COUNT)
//     {
//         printf("�������Ų��׵�����:>");
//         scanf("%d%d", &x, &y);
//         if (x >= 1 && x <= row && y >= 1 && x <= col) //����Ϸ�
//         {
//             if (mine[x][y] == '1') // 1.����
//             {
//                 printf("���ź�,�㱻ը����.\n");
//                 DisplayBoard(mine, row, col); //��������׵�����
//                 break;
//             }
//             else if (mine[x][y] == '0' && show[x][y] != '*')
//             {
//                 printf("���λ���Ѿ��Ų����,����������\n");
//             }
//             else //������ ����û���Ų��
//             {
//                 int count = get_mine_count(mine, x, y); //����x,y������Χ�м�����
//                 show[x][y] = count + '0';
//                 DisplayBoard(show, ROW, COL); //����Ų��׵�����
//                 win++;
//             }
//         }
//         else
//         {
//             printf("��������Ƿ�,����������!\n");
//         }
//     }
//     if (win == row * col - EASY_COUNT)
//     {
//         printf("��ϲ��,���׳ɹ�.\n");
//         DisplayBoard(mine, ROW, COL); //��������׵�����
//     }
//     return;
// }

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) //�Ų���(ɨ��)
{
    int x = 0;
    int y = 0;
    int win = 0;
    // 9*9-10=71
    while (win < row * col - EASY_COUNT)
    {
        printf("�������Ų��׵�����(�� ��):>");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && x <= col) //����Ϸ�
        {
            if (mine[x][y] == '1') // 1.����
            {
                printf("���ź�,�㱻ը����.\n");
                DisplayBoard(mine, row, col); //��������׵�����
                break;
            }
            else if (mine[x][y] == '0' && show[x][y] != '*')
            {
                printf("���λ���Ѿ��Ų����,����������\n");
            }
            else //������ ����û���Ų��
            {
                int count = get_mine_count(mine, x, y); //����x,y������Χ�м�����
                if (count == 0)                         //ɨ����Χû����
                {
                    // show[x][y] = ' ';
                    Diffuse(mine, show, ROW, COL, x, y, &win);
                }
                else //ɨ����Χ����
                {
                    show[x][y] = count + '0';
                    win++;
                }
                DisplayBoard(show, ROW, COL); //����Ų��׵�����
            }
        }
        else
        {
            printf("��������Ƿ�,����������!\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        printf("��ϲ��,���׳ɹ�.\n");
        DisplayBoard(mine, ROW, COL); //��������׵�����
    }
    return;
}

int get_mine_count(char mine[ROWS][COLS], int x, int y) //����x,y������Χ�м�����
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

void Diffuse(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int *win_D) //��ɨ����Χû����ʱ ����Χ��ɢ �����Ϸ������
{
    int count = 0;
    count = get_mine_count(mine, x, y);
    if (mine[x][y] == '1') //�ݹ麯������ ����������ǵ���
    {
        return;
    }
    else if (mine[x][y] == '0' && count != 0) //�ݹ麯������ ���������Χ�е���
    {
        show[x][y] = count + '0';
        (*win_D)++;
        return;
    }
    else if (mine[x][y] == '0' && count == 0) //��������겻�ǵ��ײ������������Χû�е���  ����Χ8��������еݹ�
    {
        show[x][y] = ' '; //�ո�
        (*win_D)++;
        if (x >= 1 && x <= row && y >= 1 && y <= col) //�������һȦ�����еݹ�
        {
            if (show[x - 1][y] == '*' && x - 1 >= 1) //���Ѿ��ݹ�Ĳ����еݹ�
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