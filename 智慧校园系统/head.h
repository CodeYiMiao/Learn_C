//#ifndef HEAD_H_INCLUDED
//#define HEAD_H_INCLUDED
#ifndef __HEAD_H__
#define __HEAD_H__


#include <stdio.h>
#include <stdlib.h>

#define MVNum 21  //最大项点数
#define MaxInt 32767  //表示邻接矩阵中的无穷大


typedef struct   //顶点的数据类型
{
    int NO;  //顶点编号
    char name[21];  //建筑名字
    char BrIndu[151];  //建筑简介
    char orien[51];  //大概方位
}VexType;
typedef struct
{
    VexType vexs[MVNum];  //顶点表
    int VexNum;  //图的当前顶点数
}VerTex;
VerTex V;

typedef int ArcType;  //边的权值类型
typedef struct
{
    ArcType arcs[MVNum][MVNum];  //邻接矩阵
    int vexnum , arcnum;  //图的当前顶点和边数
}AMGraph;
AMGraph G;


void PlaneGraph ( );  //输出平面图
void Menu ();  //菜单
void VexMesge ( );  //从文件中读取各个建筑(顶点)的信息
void Archtec_Inqu ( );  //根据所选择的建筑进行输出
void ArcWeight ( );  //从文件中读取各个边的权重(走路)
void ArcWeight2 ( );  //从文件中读取各个边的权重(开车)
void Dijkstra ( int start , int end );  //Dijkstra算法 根据输入的起点和终点来计算最短路径
void Route_Inque ( );  //路径查询
void Prim ( );  //Prim算法求水管铺设方案


#endif // HEAD_H_INCLUDED  //__HEAD_H__
