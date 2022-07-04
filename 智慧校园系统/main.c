
#include "head.h"

int main()
{
    //PlaneGraph ( );
    VexMesge ( );
    //ArcWeight ( );
    Menu ( );
    return 0;
}

void PlaneGraph ( )  //输出平面图
{
    printf("                                                                                \n");
    printf("河-------------北-------------地-------------质--------------大--------------学 \n");
    printf("                                                                                \n");
    printf("------------------------------------------------------------------------------- \n");
    printf(" |         ------------                                                       | \n");
    printf(" |         |1.北苑宿舍|                                                       | \n");
    printf(" |         ------------                                                       | \n");
    printf(" |         ------------        ------------  ------------                     | \n");
    printf(" |         |2.北苑食堂|        |3.菜鸟驿站|  |4.学苑超市|                     | \n");
    printf(" |         ------------        ------------  ------------     |      |        | \n");
    printf(" |------------------------------------------------------------|  天  |------- | \n");
    printf(" |                        马路                                |      |        | \n");
    printf(" |------------------------------------------------------------|  桥  |------- | \n");
    printf(" |                                                            |      |        | \n");
    printf(" |                                                                            | \n");
    printf(" |                                                                            | \n");
    printf(" |                                --------    ----------  --------            | \n");
    printf(" |                                |6.北门|    |7.校医院|  |  8.  |            | \n");
    printf(" |              ----------        --------    ----------  |  运  |            | \n");
    printf(" |              |5.综合楼|                                |  动  |            | \n");
    printf(" |              ----------                    ----------  |  场  |            | \n");
    printf(" |                                            |9.篮球场|  --------            | \n");
    printf(" |                                            ----------                      | \n");
    printf(" |                            -----------       -----------                   | \n");
    printf(" |                            |10.老食堂|       |11.网球场|                   | \n");
    printf(" |                            -----------       -----------                   | \n");
    printf(" |                ---------          ---------                                | \n");
    printf(" |                |12.教一|          |13.教二|                                | \n");
    printf(" |                ---------          ---------                                | \n");
    printf(" |     --------                                        ---------              | \n");
    printf(" |     |14.西门|                                       |15.主楼|              | \n");
    printf(" |     --------                                        ---------              | \n");
    printf(" |        -----------          ---------------                 ---------      | \n");
    printf(" |        |16.图书馆|          |17.地大博物馆|                 |18.电教|      | \n");
    printf(" |        -----------          ---------------                 ---------      | \n");
    printf(" |        -------------                                         -----------   | \n");
    printf(" |        |19.国大超市|                                         |20.实验楼|   | \n");
    printf(" |        -------------                                         -----------   | \n");
    printf(" |                                                                            | \n");
    printf("------------------------------------------------------------------------------- \n");
}

void Menu ( )  //菜单
{
    int c;
    while (1)
    {
        printf ("                                                                               \n");
        printf ("-----------------------------------菜单--------------------------------------  \n");
        printf ("| ------------   --------------   ------------   ------------   ------------ | \n");
        printf ("| |0:退出系统|   |1:查看平面图|   |2:建筑查询|   |3:路径查询|   |4:Prim算法| | \n");
        printf ("| ------------   --------------   ------------   ------------   ------------ | \n");
        printf ("-----------------------------------------------------------------------------  \n");
        printf ("请进行选择:");
        scanf ("%d" , &c);
        if (c == 0)
        {
            printf ("成功退出系统\n");
            break;
        }
        switch (c)
        {
            case 1 : {PlaneGraph ( );break;}
            case 2 : {Archtec_Inqu ( ); break;}
            case 3 : {Route_Inque ( ); break;}
            case 4 : {Prim ( ); break;}
            default : {printf ("输入错误,请重新选择哟(:\n"); break;}
        }
    }
}

void VexMesge ( )  //从文件中读取各个建筑(顶点)的信息
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

void Archtec_Inqu ( )  //根据所选择的建筑进行输出
{
    int i;
    while (1)
    {
        printf ("根据平面图输入你想查询的建筑编号:1-20 , 如果不想查询请输入0\n");
        printf ("请进行选择:");
        scanf ("%d" , &i);
        if (i == 0)
        {
            break;
        }
        else if (i>=1 && i<=V.VexNum)
        {
            printf ("建筑编号:%d , 建筑名字:%s , 建筑简介:%s , 大概方位:%s\n" , V.vexs[i].NO , V.vexs[i].name , V.vexs[i].BrIndu , V.vexs[i].orien );
        }
        else
        {
            printf ("输入错误,请重新选择\n");
        }
        printf ("\n");
    }
}

void ArcWeight ( )  //从文件中读取各个边的权重(走路)
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

void ArcWeight2 ( )  //从文件中读取各个边的权重(开车)
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

void Dijkstra ( int start , int end )  //Dijkstra算法 根据输入的起点和终点来计算最短路径
{
    int route[MVNum][3];
    int i , k , temp;
    for (i=1 ; i<=G.vexnum ; i++)
    {
        route[i][0] = 0;  //为0表示没加入集合
        route[i][1] = MaxInt;  //初时距离为无穷大
        route[i][2] = -1;  //表示前面的结点 -1表示前面无结点即起点
    }
    route[start][0] = 1;  //上面步骤为初始化
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
        for (i=1 ; i<=G.vexnum ; i++)  //找到最小的
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
        route[k][0] = 1;  //加入集合
    }



    int *p = (int *) malloc ( (MVNum) * sizeof(int) );
    p[1] = end;
    p[0] = 1;  //存储有多少个顶点
    k = route[end][2];
    while (k != -1)
    {
        p[0]++;
        p[ p[0] ] = k;
        k = route[k][2];
    }

    printf ("最短路径为:");
    for (i=p[0] ; i>=1 ; i--)
    {
        printf ("->%d(%s)" , p[i] , V.vexs[p[i]].name);
    }

    printf ("\n");
    printf("所经过的各个建筑间的距离:\n");
    int j;
    for (i=p[0] , j=p[0]-1 ; j>=1 ; i-- , j--)
    {
        printf ("%d(%s)->%d(%s) 距离为%d米\n" , p[i] , V.vexs[p[i]].name , p[j] , V.vexs[p[j]].name , G.arcs[p[i]][p[j]]);
    }
    printf ("最短路径总的距离为%d米\n" , route[end][1]);
    printf ("\n");




    //printf ("\n");

    //for (i=1 ; i<=G.vexnum ; i++)
    //{
    //    printf ( "route[%d][0]=%d , route[%d][1]=%d , route[%d][2]=%d\n" , i , route[i][0] , i , route[i][1] , i , route[i][2] );
    //}

}

void Route_Inque ( )  //路径查询
{
    int a , b , start , end;
    while (1)
    {
        printf ("是否继续查询 1:是 0:否\n");
        printf ("请进行选择:");
        scanf ("%d" , &a);
        if (a == 0)
        {
            break;
        }
        else if (a == 1)
        {
            while (1)
            {
                printf ("请问你是走路到达还是开车到达？0:返回上一级 1:走路 2:开车\n");
                printf ("请进行选择:");
                scanf ("%d" , &b);
                if (b == 0)
                {
                    break;
                }
                else if (b == 1)
                {
                    ArcWeight ( );
                    printf ("根据平面图输入你想查询路径的起点和终点编号:1-20(格式:15 3)\n");
                    printf ("请进行输入:");
                    scanf ("%d %d" , &start , &end);
                    if ( (start != end) && (start >=1) && (start <= G.vexnum) && (end >= 1) && (end <= G.vexnum) )
                    {
                        Dijkstra ( start , end );
                    }
                    else
                    {
                        printf ("输入的起点和终逻辑上有错误\n");
                    }
                }
                else if (b == 2)
                {
                    ArcWeight2 ( );
                    printf ("根据平面图输入你想查询路径的起点和终点编号:1-20(格式:15 3)\n");
                    printf ("请进行输入:");
                    scanf ("%d %d" , &start , &end);
                    if ( (start != end) && (start >=1) && (start <= G.vexnum) && (end >= 1) && (end <= G.vexnum) )
                    {
                        Dijkstra ( start , end );
                    }
                    else
                    {
                        printf ("输入的起点和终逻辑上有错误\n");
                    }
                }
                else
                {
                    printf ("您的输入有误,请选择是走路还是开车或者返回上一级\n");
                }
                /*
                printf ("根据平面图输入你想查询路径的起点和终点编号:1-20(格式:15 3)\n");
                printf ("请进行输入:");
                scanf ("%d %d" , &start , &end);
                if ( (start != end) && (start >=1) && (start <= G.vexnum) && (end >= 1) && (end <= G.vexnum) )
                {
                    Dijkstra ( start , end );
                }
                else
                {
                    printf ("输入的起点和终逻辑上有错误\n");
                }*/
            }
        }
        else
        {
            printf ("输入错误,请重新选择\n");
        }
    }
}

void Prim ( )  //Prim算法求水管铺设方案
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
    printf ("Prim算法求出的水管铺设方案为:\n");
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

        printf ("%d(%s)->%d(%s) 距离为:%d米\n" , mst[k][2] , V.vexs[mst[k][2]].name , k , V.vexs[k].name , G.arcs[mst[k][2]][k]);
        M += G.arcs[mst[k][2]][k];
    }
    printf ("水管铺设总共长度为:%d米\n" , M);
}















