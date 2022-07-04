//#ifndef HEAD_H_INCLUDED
//#define HEAD_H_INCLUDED
#ifndef __HEAD_H__
#define __HEAD_H__


#include <stdio.h>
#include <stdlib.h>

#define MVNum 21  //��������
#define MaxInt 32767  //��ʾ�ڽӾ����е������


typedef struct   //�������������
{
    int NO;  //������
    char name[21];  //��������
    char BrIndu[151];  //�������
    char orien[51];  //��ŷ�λ
}VexType;
typedef struct
{
    VexType vexs[MVNum];  //�����
    int VexNum;  //ͼ�ĵ�ǰ������
}VerTex;
VerTex V;

typedef int ArcType;  //�ߵ�Ȩֵ����
typedef struct
{
    ArcType arcs[MVNum][MVNum];  //�ڽӾ���
    int vexnum , arcnum;  //ͼ�ĵ�ǰ����ͱ���
}AMGraph;
AMGraph G;


void PlaneGraph ( );  //���ƽ��ͼ
void Menu ();  //�˵�
void VexMesge ( );  //���ļ��ж�ȡ��������(����)����Ϣ
void Archtec_Inqu ( );  //������ѡ��Ľ����������
void ArcWeight ( );  //���ļ��ж�ȡ�����ߵ�Ȩ��(��·)
void ArcWeight2 ( );  //���ļ��ж�ȡ�����ߵ�Ȩ��(����)
void Dijkstra ( int start , int end );  //Dijkstra�㷨 ��������������յ����������·��
void Route_Inque ( );  //·����ѯ
void Prim ( );  //Prim�㷨��ˮ�����跽��


#endif // HEAD_H_INCLUDED  //__HEAD_H__
