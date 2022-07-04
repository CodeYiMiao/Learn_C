#include "head.h"

using namespace std;

/* 思考:为什么在这里定义L 为什么存储的数比较多(一亿个数)时在函数内定义会导致在管理窗口出现 ( Process returned -1073741571 (0xC00000FD) )
网上搜索写的是 栈溢出了 栈的默认内存空间为1M，如果函数中定义的数组太大会导致内存溢出。  局部变量存放在内存中的栈区 全局变量,静态全局变量,静态局部变量存放在全局数据区
解决办法:加static后数组改为在静态区。或者自己申请（new,在堆区. int *aa= new int[n] */
//SqList L;  //一亿个数 可以排列

int main()
{
    int n;
    int dk1[35];  //希尔排序增量序列存储数组

    static SqList L;  //一亿个数 可以排列 static:静态变量 在函数内为静态局部变量,在函数外为静态全局变量

    //SqList L;  //一亿个数 不可以排列
    MakeRandomNumber (L);  //产生随机数
    OutPut (L);  //输出

    double duration;
    clock_t start,finish;

    printf ("请选择排序算法:\n1:直接插入排序 2:折半插入排序 3:希尔排序 4:冒泡排序 5:快速排序 6:简单选择排序 7:堆排序(大顶堆) 8:归并排序(2－路归并排序) 9:基数排序(桶排序)(没有写QaQ)\n");
    scanf ("%d",&n);
    switch(n)
    {
        case 1 :{start=clock(); InsertSort(L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("算法运行时间为:%f seconds\n",duration); break;}
        case 2 :{start=clock(); BInsertSort(L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("算法运行时间为:%f seconds\n",duration); break;}
        case 3 :{ShellSort(L , dk1); break;}
        case 4 :{start=clock(); BubbleSort (L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("算法运行时间为:%f seconds\n",duration); break;}
        case 5 :{start=clock(); QSort (L,1,L.length); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("算法运行时间为:%f seconds\n",duration); break;}
        case 6 :{start=clock(); SelectSort (L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("算法运行时间为:%f seconds\n",duration); break;}
        case 7 :{start=clock(); HeapSort (L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("算法运行时间为:%f seconds\n",duration); break;}
        case 8 :{start=clock(); MergeSort (L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("算法运行时间为:%f seconds\n",duration); break;}
        case 9 :{start=clock();  finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("算法运行时间为:%f seconds\n",duration); break;}
        default :{printf ("输入错误\n"); break;}
    }

    OutPut (L);  //输出
    return 0;
}

//产生随机数
void MakeRandomNumber (SqList &L)
{
    int n;
    srand ((unsigned)time(NULL));
    for (n=1,L.length = 0;n<=MAXSIZE;n++,L.length++)
    {
        L.r[n].key = ((rand()%NumberScope)+1);
    }
}

//输出
void OutPut (SqList &L)
{
    int i;
    for (i=1;i<=L.length;i++)
    {
        printf ("%d ",L.r[i].key);
    }
}

//1:直接插入排序
void InsertSort (SqList &L)
{
    int i,j;
    for (i=2;i<=L.length;i++)
    {
        if(L.r[i].key < L.r[i-1].key)
        {
            L.r[0]=L.r[i];
            for (j=i-1;L.r[0].key<L.r[j].key;j--)
            {
                L.r[j+1]=L.r[j];
            }
            L.r[j+1]=L.r[0];
        }
    }
}

//2:折半插入排序
void BInsertSort (SqList &L)
{
    int i,j,low,mid,high;
    for (i=2;i<=L.length;i++)
    {
        if (L.r[i-1].key>L.r[i].key)
        {
            L.r[0]=L.r[i];
            low=1; high=i-1;
            while (low<=high)
            {
                mid=(low+high)/2;
                if (L.r[0].key<L.r[mid].key)
                {
                    high=mid-1;
                }
                else {low=mid+1;}
            }
            for (j=i-1;j>=high+1;j--)
            {
                L.r[j+1]=L.r[j];
            }
            L.r[high+1]=L.r[0];
        }
    }
}

//3:希尔排序
void ShellSort (SqList &L , int dk2[35] )
{
    double duration;
    clock_t start,finish;

    ShellSort_dk_select (L , dk2 );
    int t;  //第一个小于L.length的增量dk的位置及dk2[t];
    t = Bisearch_Location_dk ( L , dk2 );
    if ( t >= 1 )  //进行希尔排序的序列大于1，因此要排序
    {
        start=clock();
        for ( ; t > 0 ; t--)
        {
            ShellInsert (L , dk2[t]);
        }
        finish=clock();
        duration = (double)(finish-start)/CLOCKS_PER_SEC;
        printf ("算法运行时间为:%f seconds\n",duration);
    }
    else   //即t=0的时候 此时 进行希尔排序的序列长度L.length小于等于1，因此不用排序
    {
        printf("进行希尔排序的序列长度小于等于1，因此不用排序\n");
    }
}

/* 思考:尔排序以dk为增量的折半插入排序可以吗 */
void ShellInsert (SqList &L , int dk)  //希尔排序以dk为增量的直接插入排序
{
    int i,j;
    for (i=dk+1;i<=L.length;i++)
    {
        if (L.r[i].key < L.r[i-dk].key)
        {
            L.r[0]=L.r[i];
            for (j=i-dk;j>0&&L.r[j].key>L.r[0].key;j=j-dk)
            {
                L.r[j+dk]=L.r[j];
            }
            L.r[j+dk]=L.r[0];
        }
    }
}

/* 思考:希尔排序dk的选择是从 数组:dk2[35] 第一个小于L.length的增量dk的位置开始往下减少到dk为1 还是有其他确定dk的方法不必从 数组:dk2[35] 第一个小于L.length的增量dk的位置开始往下减少到dk为1
并且其他找dk的方法是否会对算法产生更好的结果 及时间复杂度会降低吗 */
void ShellSort_dk_select (SqList &L , int dk_Select[35] )  //希尔排序dk选择
{
    int n;
    printf ("请选择增量序列dk \n 1:Sedgewick增量序列 2:Hibbard增量序列 3:Knuth增量序列\n");
    scanf ("%d",&n);
    switch(n)
    {
        case 1 :{ IncrementSequenceBuild_Sedgewick( dk_Select ) ; break;}
        case 2 :{ IncrementSequenceBuild_Hibbard( dk_Select ) ; break;}
        case 3 :{ IncrementSequenceBuild_Knuth( dk_Select ) ; break;}
        default :{printf("你没有选择增量序列,因此没有排序\n"); break;}
    }
}

//h(i)=max{9*4^j-9*2^j+1 , 4^k-3*2^k+1}
void IncrementSequenceBuild_Sedgewick(int IncrementSequence_Sedgewick[30])  //增量序列Sedgewick 1,5,19,41,109,,,1073643521 最坏时间复杂度为 O(N ^(4/3))  平均时间复杂度约为 O(N^(7/6))
{
    IncrementSequence_Sedgewick[0]=28;
    IncrementSequence_Sedgewick[1]=1;
    for(int i=1,j=2;i<=13||j<=15;)
        if(i<=13&&9*(1<<i*2)-9*(1<<i)+1<(1<<j*2)-3*(1<<j)+1)
            IncrementSequence_Sedgewick[i+j-1]=9*(1<<i*2)-9*(1<<i)+1,i++;
        else
            IncrementSequence_Sedgewick[i+j-1]=(1<<j*2)-3*(1<<j)+1,j++;
}

//通项公式:h(i)=2^i-1 递推公式:h(1)=1 , h(i)=2*h(i-1)+1
void IncrementSequenceBuild_Hibbard( int IncrementSequence_Hibbard[35] )  //增量序列Hibbard  最坏时间复杂度为 Θ(N^(3/2))  平均时间复杂度约为 O(N^(5/4))
{
    IncrementSequence_Hibbard[0]=30;
    IncrementSequence_Hibbard[1]=1;
    for(int i=2;i<=30;i++)
        IncrementSequence_Hibbard[i]=IncrementSequence_Hibbard[i-1]*2+1;
}

//通项公式:h(i)=(1/2)(3^i-1) 递推公式:h(1)=1 , h(i)=3*h(i-1)+1
void IncrementSequenceBuild_Knuth(int IncrementSequence_Knuth[25])  //增量序列Knuth
{
    IncrementSequence_Knuth[0]=20;
    IncrementSequence_Knuth[1]=1;
    for(int i=2;i<=20;i++)
        IncrementSequence_Knuth[i]=IncrementSequence_Knuth[i-1]*3+1;
}

int Bisearch_Location_dk ( SqList &L , int a[35] )  //利用折半查找来从增量序列a[35]找到第一个小于L.length的增量dk
{
    int low = 1 , high = a[0] , mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.length <= a[mid])
        {
            high = mid-1;
        }
        else low = mid+1;
    }
    return high;
}

//4:冒泡排序
void BubbleSort (SqList &L)
{
    int i , j , flag=1 ;  //flag作为是否交换的标志
    for (i=1;flag==1&&i<=L.length-1;i++)  //总共要比L.length-1趟
    {
        flag=0;
        for (j=1;j<=L.length-i;j++)  //每趟比较次数=L.length-趟数
        {
            if (L.r[j+1].key < L.r[j].key)  //发生交换
            {
                flag=1;
                L.r[0]=L.r[j+1];
                L.r[j+1]=L.r[j];
                L.r[j]=L.r[0];
            }
        }
    }
}

//5:快速排序
void QSort (SqList &L , int low , int high)
{
    int PivotLoc;  //记录枢轴元素位置
    if (low<high)  //长度>1 因为=1时只要一个元素 递归结束
    {
        PivotLoc=Partition (L , low , high);
        QSort (L , low , PivotLoc-1);  //对低子表进行递归排序
        QSort (L , PivotLoc+1 , high);  //对高子表进行递归排序
    }
}

/*思考: ((low<high)&&(L.r[high].key>=L.r[0].key)) (((low<high)&&(L.r[low].key<=L.r[0].key))) 为什么是 >=(<=) 而不是 >(<) 并且去掉 = 会导致程序出现错误*/
int Partition (SqList &L , int low , int high)  //分割待排序序列 并返回枢轴元素位置
{
    L.r[0]=L.r[low];
    while (low<high)
    {
        while ((low<high)&&(L.r[high].key>=L.r[0].key))
        {
            high--;
        }
        L.r[low]=L.r[high];
        while ((low<high)&&(L.r[low].key<=L.r[0].key))
        {
            low++;
        }
        L.r[high]=L.r[low];
    }
    L.r[low]=L.r[0];  //将枢轴元素放到中间位置
    return low;
}

//6:简单选择排序
void SelectSort (SqList &L)
{
    int i , j , k;
    for (i=1;i<L.length;i++)  //总共有L.length-1趟
    {
        k=i;
        for (j=i+1;j<=L.length;j++)
        {
            if (L.r[j].key<L.r[k].key)
            {
                k=j;  //记录最小值的位置
            }
        }
        if (k!=i)  //最小值的位置与i不同 交换
        {
            L.r[0]=L.r[k];
            L.r[k]=L.r[i];
            L.r[i]=L.r[0];
        }
    }
}

//7:堆排序(大顶堆)
void HeapSort (SqList &L)
{
    int i;
    for (i=L.length/2;i>=1;i--)  //完全二叉树最后一个有子树的元素的下标是L.length/2
    {
        HeapAdjust (L , i , L.length);  //从下往上调整为一个大顶堆
    }
    for (i=L.length;i>1;i--)  //要进行L.length-1趟排序 每趟排序将最大的元素移到最后一个位置 还剩最后一个时就是有序的了
    {
        L.r[0]=L.r[i];
        L.r[i]=L.r[1];
        L.r[1]=L.r[0];
        HeapAdjust (L , 1 , i-1);
    }
}

void HeapAdjust (SqList &L , int s , int m)  //s,m分别是待调整完全二叉树(数组)的第一个和最后一个元素  //调整为一个大顶堆
{
    int j;
    L.r[0]=L.r[s];  //保存第一个元素
    for (j=2*s;j<=m;j *= 2)
    {
        if ((j<m) && (L.r[j].key<L.r[j+1].key))  //j为key较大记录的下标
        {
            j++;
        }
        if (L.r[0].key >= L.r[j].key)
        {
            break;  //跳出循环
        }
        L.r[s]=L.r[j];  //较大记录往上移
        s=j;  //s向下移
    }
    L.r[s]=L.r[0];  //将保存的第一个元素移到新位置
}

//8:归并排序(2－路归并排序)
void MergeSort (SqList &L)
{
    int s , t , i;
    t=1;
    while (t < L.length)
    {
        s=t;  //每次合并的项的元素个数
        t=2*s;  //每次合并后的元素个数
        i=0;  //每次都从零开始
        while (i+t <= L.length)
        {
            Merge_NoSpace (L , i+1 , i+s , i+t);
            i=i+t;
        }
        if (i+s < L.length)
        {
            Merge_NoSpace (L , i+1 , i+s , L.length);
        }
    }
}

void Merge_NoSpace (SqList &L , int i , int m , int n)  //L.r[i...m m+1 ...n]  //每次两两合并调用的函数
{
    while (i <= m)  //每次都将最小的元素拿到前面一个序列 后面一个序列如果第一个比较大 那么对后面一个序列进行排序
    {
        if (L.r[m+1].key < L.r[i].key)
        {
            L.r[0]=L.r[m+1];
            L.r[m+1]=L.r[i];
            L.r[i]=L.r[0];
            i++;
        }
        else
        {
            i++;
        }
        if (L.r[m+1].key > L.r[m+2].key)  //用折半插入排序的方法对后面一个序列进行排序  //也可以用其他的排序方法
        {
            int low , high , mid;
            int j;
            L.r[0]=L.r[m+1];
            low=m+2;
            high=n;
            while (low <= high)
            {
                mid = (low+high)/2;
                if (L.r[0].key < L.r[mid].key)
                {
                    high=mid-1;
                }
                else {low=mid+1;}
            }
            for (j=m+2; j<=high; j++)  //和折半插入排序 有有点不同 这是向前移动
            {
                L.r[j-1]=L.r[j];
            }
            L.r[high]=L.r[0];  //插入位置是L.r[high] 因为是向前移动 如果是向后移动则是 L.r[high+1]
        }
    }
}



//9:基数排序(桶排序)































