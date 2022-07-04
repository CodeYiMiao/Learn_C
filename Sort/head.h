#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
#define MAXSIZE 10  //�������ķ�Χ
#define NumberScope 100  //���ݴ�С�ķ�Χ

typedef int KeyType;
typedef struct
{
    KeyType key;
}RedType;
typedef struct
{
    RedType r[MAXSIZE+1];
    int length;
}SqList;

void MakeRandomNumber (SqList &L);  //���������
void OutPut (SqList &L);  //���

//1:ֱ�Ӳ�������
void InsertSort (SqList &L);

//2:�۰��������
void BInsertSort (SqList &L);

//3:ϣ������
void ShellSort (SqList &L , int dk2[35] );
void ShellInsert (SqList &L , int dk);  //ϣ��������dkΪ������ֱ�Ӳ�������  ˼��:��������dkΪ�������۰�������������
void ShellSort_dk_select (SqList &L , int dk_Select[35] );  //ϣ������dkѡ��
void IncrementSequenceBuild_Sedgewick(int IncrementSequence_Sedgewick[30]);  //��������Sedgewick  //1,5,19,41,109,209,505,929,
                                                                                                  //2161,3905,8929,16001,36289,64769,146305,260609,
                                                                                                  //587521,1045505,2354689,4188161,9427969,16764929,37730305,67084289,
                                                                                                  //150958081,268386305,603906049,1073643521
void IncrementSequenceBuild_Hibbard( int IncrementSequence_Hibbard[35] );  //��������Hibbard  //1,3,7,15,31,63,127,255,
                                                                                              //511,1023,2047,4095,8191,16383,32767,65535,
                                                                                              //131071,262143,524287,1048575,2097151,4194303,8388607,16777215,
                                                                                              //33554431,67108863,134217727,268435455,536870911,1073741823
void IncrementSequenceBuild_Knuth(int IncrementSequence_Knuth[25]);  //��������Knuth  //1,4,13,40,121,364,1093,3280,
                                                                                      //9841,29524,88573,265720,797161,2391484,7174453,21523360,
                                                                                      //64570081,193710244,581130733,1743392200
int Bisearch_Location_dk ( SqList &L , int a[35] );  //�����۰����������������a[35]�ҵ���һ��С��L.length������dk

//4:ð������
void BubbleSort (SqList &L);

//5:��������
void QSort (SqList &L , int low , int high);
int Partition (SqList &L , int low , int high);  //�ָ���������� ����������Ԫ��λ��

//6:��ѡ������
void SelectSort (SqList &L);

//7:������(�󶥶�)
void HeapSort (SqList &L);
void HeapAdjust (SqList &L , int s , int m);  //s,m�ֱ��Ǵ�������ȫ������(����)�ĵ�һ�������һ��Ԫ��  //����Ϊһ���󶥶�

//8:�鲢����(2��·�鲢����)
void MergeSort (SqList &L);
void Merge_NoSpace (SqList &L , int i , int m , int n);  //L.r[i...m m+1 ...n]  //ÿ�������ϲ����õĺ���


#endif // HEAD_H_INCLUDED
