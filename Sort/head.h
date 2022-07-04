#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
#define MAXSIZE 10  //数据量的范围
#define NumberScope 100  //数据大小的范围

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

void MakeRandomNumber (SqList &L);  //产生随机数
void OutPut (SqList &L);  //输出

//1:直接插入排序
void InsertSort (SqList &L);

//2:折半插入排序
void BInsertSort (SqList &L);

//3:希尔排序
void ShellSort (SqList &L , int dk2[35] );
void ShellInsert (SqList &L , int dk);  //希尔排序以dk为增量的直接插入排序  思考:尔排序以dk为增量的折半插入排序可以吗
void ShellSort_dk_select (SqList &L , int dk_Select[35] );  //希尔排序dk选择
void IncrementSequenceBuild_Sedgewick(int IncrementSequence_Sedgewick[30]);  //增量序列Sedgewick  //1,5,19,41,109,209,505,929,
                                                                                                  //2161,3905,8929,16001,36289,64769,146305,260609,
                                                                                                  //587521,1045505,2354689,4188161,9427969,16764929,37730305,67084289,
                                                                                                  //150958081,268386305,603906049,1073643521
void IncrementSequenceBuild_Hibbard( int IncrementSequence_Hibbard[35] );  //增量序列Hibbard  //1,3,7,15,31,63,127,255,
                                                                                              //511,1023,2047,4095,8191,16383,32767,65535,
                                                                                              //131071,262143,524287,1048575,2097151,4194303,8388607,16777215,
                                                                                              //33554431,67108863,134217727,268435455,536870911,1073741823
void IncrementSequenceBuild_Knuth(int IncrementSequence_Knuth[25]);  //增量序列Knuth  //1,4,13,40,121,364,1093,3280,
                                                                                      //9841,29524,88573,265720,797161,2391484,7174453,21523360,
                                                                                      //64570081,193710244,581130733,1743392200
int Bisearch_Location_dk ( SqList &L , int a[35] );  //利用折半查找来从增量序列a[35]找到第一个小于L.length的增量dk

//4:冒泡排序
void BubbleSort (SqList &L);

//5:快速排序
void QSort (SqList &L , int low , int high);
int Partition (SqList &L , int low , int high);  //分割待排序序列 并返回枢轴元素位置

//6:简单选择排序
void SelectSort (SqList &L);

//7:堆排序(大顶堆)
void HeapSort (SqList &L);
void HeapAdjust (SqList &L , int s , int m);  //s,m分别是待调整完全二叉树(数组)的第一个和最后一个元素  //调整为一个大顶堆

//8:归并排序(2－路归并排序)
void MergeSort (SqList &L);
void Merge_NoSpace (SqList &L , int i , int m , int n);  //L.r[i...m m+1 ...n]  //每次两两合并调用的函数


#endif // HEAD_H_INCLUDED
