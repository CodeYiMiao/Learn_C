
#include "head.h"

int main()
{
    //PlaneGraph ( );
    VexMesge ( );
    //ArcWeight ( );
    Menu ( );
    return 0;
}

void PlaneGraph ( )  //���ƽ��ͼ
{
    printf("                                                                                \n");
    printf("��-------------��-------------��-------------��--------------��--------------ѧ \n");
    printf("                                                                                \n");
    printf("------------------------------------------------------------------------------- \n");
    printf(" |         ------------                                                       | \n");
    printf(" |         |1.��Է����|                                                       | \n");
    printf(" |         ------------                                                       | \n");
    printf(" |         ------------        ------------  ------------                     | \n");
    printf(" |         |2.��Էʳ��|        |3.������վ|  |4.ѧԷ����|                     | \n");
    printf(" |         ------------        ------------  ------------     |      |        | \n");
    printf(" |------------------------------------------------------------|  ��  |------- | \n");
    printf(" |                        ��·                                |      |        | \n");
    printf(" |------------------------------------------------------------|  ��  |------- | \n");
    printf(" |                                                            |      |        | \n");
    printf(" |                                                                            | \n");
    printf(" |                                                                            | \n");
    printf(" |                                --------    ----------  --------            | \n");
    printf(" |                                |6.����|    |7.УҽԺ|  |  8.  |            | \n");
    printf(" |              ----------        --------    ----------  |  ��  |            | \n");
    printf(" |              |5.�ۺ�¥|                                |  ��  |            | \n");
    printf(" |              ----------                    ----------  |  ��  |            | \n");
    printf(" |                                            |9.����|  --------            | \n");
    printf(" |                                            ----------                      | \n");
    printf(" |                            -----------       -----------                   | \n");
    printf(" |                            |10.��ʳ��|       |11.����|                   | \n");
    printf(" |                            -----------       -----------                   | \n");
    printf(" |                ---------          ---------                                | \n");
    printf(" |                |12.��һ|          |13.�̶�|                                | \n");
    printf(" |                ---------          ---------                                | \n");
    printf(" |     --------                                        ---------              | \n");
    printf(" |     |14.����|                                       |15.��¥|              | \n");
    printf(" |     --------                                        ---------              | \n");
    printf(" |        -----------          ---------------                 ---------      | \n");
    printf(" |        |16.ͼ���|          |17.�ش����|                 |18.���|      | \n");
    printf(" |        -----------          ---------------                 ---------      | \n");
    printf(" |        -------------                                         -----------   | \n");
    printf(" |        |19.������|                                         |20.ʵ��¥|   | \n");
    printf(" |        -------------                                         -----------   | \n");
    printf(" |                                                                            | \n");
    printf("------------------------------------------------------------------------------- \n");
}

void Menu ( )  //�˵�
{
    int c;
    while (1)
    {
        printf ("                                                                               \n");
        printf ("-----------------------------------�˵�--------------------------------------  \n");
        printf ("| ------------   --------------   ------------   ------------   ------------ | \n");
        printf ("| |0:�˳�ϵͳ|   |1:�鿴ƽ��ͼ|   |2:������ѯ|   |3:·����ѯ|   |4:Prim�㷨| | \n");
        printf ("| ------------   --------------   ------------   ------------   ------------ | \n");
        printf ("-----------------------------------------------------------------------------  \n");
        printf ("�����ѡ��:");
        scanf ("%d" , &c);
        if (c == 0)
        {
            printf ("�ɹ��˳�ϵͳ\n");
            break;
        }
        switch (c)
        {
            case 1 : {PlaneGraph ( );break;}
            case 2 : {Archtec_Inqu ( ); break;}
            case 3 : {Route_Inque ( ); break;}
            case 4 : {Prim ( ); break;}
            default : {printf ("�������,������ѡ��Ӵ(:\n"); break;}
        }
    }
}

void VexMesge ( )  //���ļ��ж�ȡ��������(����)����Ϣ
{
    int i;
    FILE *fp1;
    fp1 = fopen ("message.txt" , "r");
    fscanf (fp1 , "%d" , &V.VexNum);
    for (i=1 ; i<=V.VexNum ; i++)
    {
        V.vexs[i].NO = i;
        fscanf (fp1 , "%s %s %s" , V.vexs[i].name , V.vexs[i].BrIndu , V.vexs[i].orien);
    }
    fclose (fp1);
}

void Archtec_Inqu ( )  //������ѡ��Ľ����������
{
    int i;
    while (1)
    {
        printf ("����ƽ��ͼ���������ѯ�Ľ������:1-20 , ��������ѯ������0\n");
        printf ("�����ѡ��:");
        scanf ("%d" , &i);
        if (i == 0)
        {
            break;
        }
        else if (i>=1 && i<=V.VexNum)
        {
            printf ("�������:%d , ��������:%s , �������:%s , ��ŷ�λ:%s\n" , V.vexs[i].NO , V.vexs[i].name , V.vexs[i].BrIndu , V.vexs[i].orien );
        }
        else
        {
            printf ("�������,������ѡ��\n");
        }
        printf ("\n");
    }
}

void ArcWeight ( )  //���ļ��ж�ȡ�����ߵ�Ȩ��(��·)
{
    int i , j , w;
    FILE *fp2;
    fp2 = fopen ("ArcWighSid.txt" , "r");
    fscanf (fp2 , "%d %d" , &G.vexnum , &G.arcnum);
    for (i=1 ; i<=G.vexnum ; i++)
    {
        for (j=1 ; j<=G.vexnum ; j++)
        {
            G.arcs[i][j] = MaxInt;
        }
    }
    while ( fscanf (fp2 , "%d %d %d" , &i , &j , &w) !=EOF )
    {
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
    fclose (fp2);



    //for (i=1 ; i<=G.vexnum ; i++)
    //{
    //    for (j=1 ; j<=G.vexnum ; j++)
    //    {
    //        printf ( "(arcs[%d][%d] = %d) " , i , j , G.arcs[i][j] );
    //    }
    //    printf ("\n");
    //}
}

void ArcWeight2 ( )  //���ļ��ж�ȡ�����ߵ�Ȩ��(����)
{
    int i , j , w;
    FILE *fp2;
    fp2 = fopen ("ArcWighRod.txt" , "r");
    fscanf (fp2 , "%d %d" , &G.vexnum , &G.arcnum);
    for (i=1 ; i<=G.vexnum ; i++)
    {
        for (j=1 ; j<=G.vexnum ; j++)
        {
            G.arcs[i][j] = MaxInt;
        }
    }
    while ( fscanf (fp2 , "%d %d %d" , &i , &j , &w) !=EOF )
    {
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
    fclose (fp2);



    //for (i=1 ; i<=G.vexnum ; i++)
    //{
    //    for (j=1 ; j<=G.vexnum ; j++)
    //    {
    //        printf ( "(arcs[%d][%d] = %d) " , i , j , G.arcs[i][j] );
    //    }
    //    printf ("\n");
    //}
}

void Dijkstra ( int start , int end )  //Dijkstra�㷨 ��������������յ����������·��
{
    int route[MVNum][3];
    int i , k , temp;
    for (i=1 ; i<=G.vexnum ; i++)
    {
        route[i][0] = 0;  //Ϊ0��ʾû���뼯��
        route[i][1] = MaxInt;  //��ʱ����Ϊ�����
        route[i][2] = -1;  //��ʾǰ��Ľ�� -1��ʾǰ���޽�㼴���
    }
    route[start][0] = 1;  //���沽��Ϊ��ʼ��
    route[start][1] = 0;
    route[start][2] = -1;
    k=start;

    while (!route[end][0])
    {
        for (i=1 ; i<=G.vexnum ; i++)
        {
            if ( (! route[i][0]) && (G.arcs[k][i] != MaxInt) && (route[k][1] + G.arcs[k][i] < route[i][1]) )
            {
                {
                    route[i][1] = route[k][1] + G.arcs[k][i];
                    route[i][2] = k;
                }
            }
        }

        temp=MaxInt;
        for (i=1 ; i<=G.vexnum ; i++)  //�ҵ���С��
        {
            if ( ( ! route[i][0] ) && ( route[i][1] !=MaxInt ) )
            {
                if (route[i][1] < temp)
                {
                    temp = route[i][1];
                    k = i;
                }
            }
        }
        route[k][0] = 1;  //���뼯��
    }



    int *p = (int *) malloc ( (MVNum) * sizeof(int) );
    p[1] = end;
    p[0] = 1;  //�洢�ж��ٸ�����
    k = route[end][2];
    while (k != -1)
    {
        p[0]++;
        p[ p[0] ] = k;
        k = route[k][2];
    }

    printf ("���·��Ϊ:");
    for (i=p[0] ; i>=1 ; i--)
    {
        printf ("->%d(%s)" , p[i] , V.vexs[p[i]].name);
    }

    printf ("\n");
    printf("�������ĸ���������ľ���:\n");
    int j;
    for (i=p[0] , j=p[0]-1 ; j>=1 ; i-- , j--)
    {
        printf ("%d(%s)->%d(%s) ����Ϊ%d��\n" , p[i] , V.vexs[p[i]].name , p[j] , V.vexs[p[j]].name , G.arcs[p[i]][p[j]]);
    }
    printf ("���·���ܵľ���Ϊ%d��\n" , route[end][1]);
    printf ("\n");




    //printf ("\n");

    //for (i=1 ; i<=G.vexnum ; i++)
    //{
    //    printf ( "route[%d][0]=%d , route[%d][1]=%d , route[%d][2]=%d\n" , i , route[i][0] , i , route[i][1] , i , route[i][2] );
    //}

}

void Route_Inque ( )  //·����ѯ
{
    int a , b , start , end;
    while (1)
    {
        printf ("�Ƿ������ѯ 1:�� 0:��\n");
        printf ("�����ѡ��:");
        scanf ("%d" , &a);
        if (a == 0)
        {
            break;
        }
        else if (a == 1)
        {
            while (1)
            {
                printf ("����������·���ﻹ�ǿ������0:������һ�� 1:��· 2:����\n");
                printf ("�����ѡ��:");
                scanf ("%d" , &b);
                if (b == 0)
                {
                    break;
                }
                else if (b == 1)
                {
                    ArcWeight ( );
                    printf ("����ƽ��ͼ���������ѯ·���������յ���:1-20(��ʽ:15 3)\n");
                    printf ("���������:");
                    scanf ("%d %d" , &start , &end);
                    if ( (start != end) && (start >=1) && (start <= G.vexnum) && (end >= 1) && (end <= G.vexnum) )
                    {
                        Dijkstra ( start , end );
                    }
                    else
                    {
                        printf ("������������߼����д���\n");
                    }
                }
                else if (b == 2)
                {
                    ArcWeight2 ( );
                    printf ("����ƽ��ͼ���������ѯ·���������յ���:1-20(��ʽ:15 3)\n");
                    printf ("���������:");
                    scanf ("%d %d" , &start , &end);
                    if ( (start != end) && (start >=1) && (start <= G.vexnum) && (end >= 1) && (end <= G.vexnum) )
                    {
                        Dijkstra ( start , end );
                    }
                    else
                    {
                        printf ("������������߼����д���\n");
                    }
                }
                else
                {
                    printf ("������������,��ѡ������·���ǿ������߷�����һ��\n");
                }
                /*
                printf ("����ƽ��ͼ���������ѯ·���������յ���:1-20(��ʽ:15 3)\n");
                printf ("���������:");
                scanf ("%d %d" , &start , &end);
                if ( (start != end) && (start >=1) && (start <= G.vexnum) && (end >= 1) && (end <= G.vexnum) )
                {
                    Dijkstra ( start , end );
                }
                else
                {
                    printf ("������������߼����д���\n");
                }*/
            }
        }
        else
        {
            printf ("�������,������ѡ��\n");
        }
    }
}

void Prim ( )  //Prim�㷨��ˮ�����跽��
{
    ArcWeight ( );
    int mst[MVNum][3];
    int i;
    for (i=1 ; i<=G.vexnum ; i++)
    {
        mst[i][0] = 0;
        mst[i][1] = MaxInt;
        mst[i][2] = -1;
    }
    mst[1][0] = 1;
    mst[1][1] = 0;
    mst[1][2] = -1;

    int sum=0;
    int M=0;
    int k=1;
    int temp;
    printf ("Prim�㷨�����ˮ�����跽��Ϊ:\n");
    while ( sum != (G.vexnum-1) )
    {
        for (i=1 ; i<=G.vexnum ; i++)
        {
            if ( (! mst[i][0]) && (G.arcs[k][i] != MaxInt) && (G.arcs[k][i] < mst[i][1]) )
            {
                mst[i][1] = G.arcs[k][i];
                mst[i][2] = k;
            }
        }

        temp=MaxInt;
        for (i=1 ; i<=G.vexnum ; i++)
        {
            if ( (! mst[i][0]) && (mst[i][1] != MaxInt) )
            {
                if (mst[i][1] < temp)
                {
                    temp = mst[i][1];
                    k=i;
                }
            }
        }
        mst[k][0] = 1;
        sum++;

        printf ("%d(%s)->%d(%s) ����Ϊ:%d��\n" , mst[k][2] , V.vexs[mst[k][2]].name , k , V.vexs[k].name , G.arcs[mst[k][2]][k]);
        M += G.arcs[mst[k][2]][k];
    }
    printf ("ˮ�������ܹ�����Ϊ:%d��\n" , M);
}















