#include "head.h"

using namespace std;

/* ˼��:Ϊʲô�����ﶨ��L Ϊʲô�洢�����Ƚ϶�(һ�ڸ���)ʱ�ں����ڶ���ᵼ���ڹ����ڳ��� ( Process returned -1073741571 (0xC00000FD) )
��������д���� ջ����� ջ��Ĭ���ڴ�ռ�Ϊ1M����������ж��������̫��ᵼ���ڴ������  �ֲ�����������ڴ��е�ջ�� ȫ�ֱ���,��̬ȫ�ֱ���,��̬�ֲ����������ȫ��������
����취:��static�������Ϊ�ھ�̬���������Լ����루new,�ڶ���. int *aa= new int[n] */
//SqList L;  //һ�ڸ��� ��������

int main()
{
    int n;
    int dk1[35];  //ϣ�������������д洢����

    static SqList L;  //һ�ڸ��� �������� static:��̬���� �ں�����Ϊ��̬�ֲ�����,�ں�����Ϊ��̬ȫ�ֱ���

    //SqList L;  //һ�ڸ��� ����������
    MakeRandomNumber (L);  //���������
    OutPut (L);  //���

    double duration;
    clock_t start,finish;

    printf ("��ѡ�������㷨:\n1:ֱ�Ӳ������� 2:�۰�������� 3:ϣ������ 4:ð������ 5:�������� 6:��ѡ������ 7:������(�󶥶�) 8:�鲢����(2��·�鲢����) 9:��������(Ͱ����)(û��дQaQ)\n");
    scanf ("%d",&n);
    switch(n)
    {
        case 1 :{start=clock(); InsertSort(L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("�㷨����ʱ��Ϊ:%f seconds\n",duration); break;}
        case 2 :{start=clock(); BInsertSort(L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("�㷨����ʱ��Ϊ:%f seconds\n",duration); break;}
        case 3 :{ShellSort(L , dk1); break;}
        case 4 :{start=clock(); BubbleSort (L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("�㷨����ʱ��Ϊ:%f seconds\n",duration); break;}
        case 5 :{start=clock(); QSort (L,1,L.length); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("�㷨����ʱ��Ϊ:%f seconds\n",duration); break;}
        case 6 :{start=clock(); SelectSort (L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("�㷨����ʱ��Ϊ:%f seconds\n",duration); break;}
        case 7 :{start=clock(); HeapSort (L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("�㷨����ʱ��Ϊ:%f seconds\n",duration); break;}
        case 8 :{start=clock(); MergeSort (L); finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("�㷨����ʱ��Ϊ:%f seconds\n",duration); break;}
        case 9 :{start=clock();  finish=clock(); duration = (double)(finish-start)/CLOCKS_PER_SEC; printf ("�㷨����ʱ��Ϊ:%f seconds\n",duration); break;}
        default :{printf ("�������\n"); break;}
    }

    OutPut (L);  //���
    return 0;
}

//���������
void MakeRandomNumber (SqList &L)
{
    int n;
    srand ((unsigned)time(NULL));
    for (n=1,L.length = 0;n<=MAXSIZE;n++,L.length++)
    {
        L.r[n].key = ((rand()%NumberScope)+1);
    }
}

//���
void OutPut (SqList &L)
{
    int i;
    for (i=1;i<=L.length;i++)
    {
        printf ("%d ",L.r[i].key);
    }
}

//1:ֱ�Ӳ�������
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

//2:�۰��������
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

//3:ϣ������
void ShellSort (SqList &L , int dk2[35] )
{
    double duration;
    clock_t start,finish;

    ShellSort_dk_select (L , dk2 );
    int t;  //��һ��С��L.length������dk��λ�ü�dk2[t];
    t = Bisearch_Location_dk ( L , dk2 );
    if ( t >= 1 )  //����ϣ����������д���1�����Ҫ����
    {
        start=clock();
        for ( ; t > 0 ; t--)
        {
            ShellInsert (L , dk2[t]);
        }
        finish=clock();
        duration = (double)(finish-start)/CLOCKS_PER_SEC;
        printf ("�㷨����ʱ��Ϊ:%f seconds\n",duration);
    }
    else   //��t=0��ʱ�� ��ʱ ����ϣ����������г���L.lengthС�ڵ���1����˲�������
    {
        printf("����ϣ����������г���С�ڵ���1����˲�������\n");
    }
}

/* ˼��:��������dkΪ�������۰������������� */
void ShellInsert (SqList &L , int dk)  //ϣ��������dkΪ������ֱ�Ӳ�������
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

/* ˼��:ϣ������dk��ѡ���Ǵ� ����:dk2[35] ��һ��С��L.length������dk��λ�ÿ�ʼ���¼��ٵ�dkΪ1 ����������ȷ��dk�ķ������ش� ����:dk2[35] ��һ��С��L.length������dk��λ�ÿ�ʼ���¼��ٵ�dkΪ1
����������dk�ķ����Ƿ����㷨�������õĽ�� ��ʱ�临�ӶȻή���� */
void ShellSort_dk_select (SqList &L , int dk_Select[35] )  //ϣ������dkѡ��
{
    int n;
    printf ("��ѡ����������dk \n 1:Sedgewick�������� 2:Hibbard�������� 3:Knuth��������\n");
    scanf ("%d",&n);
    switch(n)
    {
        case 1 :{ IncrementSequenceBuild_Sedgewick( dk_Select ) ; break;}
        case 2 :{ IncrementSequenceBuild_Hibbard( dk_Select ) ; break;}
        case 3 :{ IncrementSequenceBuild_Knuth( dk_Select ) ; break;}
        default :{printf("��û��ѡ����������,���û������\n"); break;}
    }
}

//h(i)=max{9*4^j-9*2^j+1 , 4^k-3*2^k+1}
void IncrementSequenceBuild_Sedgewick(int IncrementSequence_Sedgewick[30])  //��������Sedgewick 1,5,19,41,109,,,1073643521 �ʱ�临�Ӷ�Ϊ O(N ^(4/3))  ƽ��ʱ�临�Ӷ�ԼΪ O(N^(7/6))
{
    IncrementSequence_Sedgewick[0]=28;
    IncrementSequence_Sedgewick[1]=1;
    for(int i=1,j=2;i<=13||j<=15;)
        if(i<=13&&9*(1<<i*2)-9*(1<<i)+1<(1<<j*2)-3*(1<<j)+1)
            IncrementSequence_Sedgewick[i+j-1]=9*(1<<i*2)-9*(1<<i)+1,i++;
        else
            IncrementSequence_Sedgewick[i+j-1]=(1<<j*2)-3*(1<<j)+1,j++;
}

//ͨ�ʽ:h(i)=2^i-1 ���ƹ�ʽ:h(1)=1 , h(i)=2*h(i-1)+1
void IncrementSequenceBuild_Hibbard( int IncrementSequence_Hibbard[35] )  //��������Hibbard  �ʱ�临�Ӷ�Ϊ ��(N^(3/2))  ƽ��ʱ�临�Ӷ�ԼΪ O(N^(5/4))
{
    IncrementSequence_Hibbard[0]=30;
    IncrementSequence_Hibbard[1]=1;
    for(int i=2;i<=30;i++)
        IncrementSequence_Hibbard[i]=IncrementSequence_Hibbard[i-1]*2+1;
}

//ͨ�ʽ:h(i)=(1/2)(3^i-1) ���ƹ�ʽ:h(1)=1 , h(i)=3*h(i-1)+1
void IncrementSequenceBuild_Knuth(int IncrementSequence_Knuth[25])  //��������Knuth
{
    IncrementSequence_Knuth[0]=20;
    IncrementSequence_Knuth[1]=1;
    for(int i=2;i<=20;i++)
        IncrementSequence_Knuth[i]=IncrementSequence_Knuth[i-1]*3+1;
}

int Bisearch_Location_dk ( SqList &L , int a[35] )  //�����۰����������������a[35]�ҵ���һ��С��L.length������dk
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

//4:ð������
void BubbleSort (SqList &L)
{
    int i , j , flag=1 ;  //flag��Ϊ�Ƿ񽻻��ı�־
    for (i=1;flag==1&&i<=L.length-1;i++)  //�ܹ�Ҫ��L.length-1��
    {
        flag=0;
        for (j=1;j<=L.length-i;j++)  //ÿ�˱Ƚϴ���=L.length-����
        {
            if (L.r[j+1].key < L.r[j].key)  //��������
            {
                flag=1;
                L.r[0]=L.r[j+1];
                L.r[j+1]=L.r[j];
                L.r[j]=L.r[0];
            }
        }
    }
}

//5:��������
void QSort (SqList &L , int low , int high)
{
    int PivotLoc;  //��¼����Ԫ��λ��
    if (low<high)  //����>1 ��Ϊ=1ʱֻҪһ��Ԫ�� �ݹ����
    {
        PivotLoc=Partition (L , low , high);
        QSort (L , low , PivotLoc-1);  //�Ե��ӱ���еݹ�����
        QSort (L , PivotLoc+1 , high);  //�Ը��ӱ���еݹ�����
    }
}

/*˼��: ((low<high)&&(L.r[high].key>=L.r[0].key)) (((low<high)&&(L.r[low].key<=L.r[0].key))) Ϊʲô�� >=(<=) ������ >(<) ����ȥ�� = �ᵼ�³�����ִ���*/
int Partition (SqList &L , int low , int high)  //�ָ���������� ����������Ԫ��λ��
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
    L.r[low]=L.r[0];  //������Ԫ�طŵ��м�λ��
    return low;
}

//6:��ѡ������
void SelectSort (SqList &L)
{
    int i , j , k;
    for (i=1;i<L.length;i++)  //�ܹ���L.length-1��
    {
        k=i;
        for (j=i+1;j<=L.length;j++)
        {
            if (L.r[j].key<L.r[k].key)
            {
                k=j;  //��¼��Сֵ��λ��
            }
        }
        if (k!=i)  //��Сֵ��λ����i��ͬ ����
        {
            L.r[0]=L.r[k];
            L.r[k]=L.r[i];
            L.r[i]=L.r[0];
        }
    }
}

//7:������(�󶥶�)
void HeapSort (SqList &L)
{
    int i;
    for (i=L.length/2;i>=1;i--)  //��ȫ���������һ����������Ԫ�ص��±���L.length/2
    {
        HeapAdjust (L , i , L.length);  //�������ϵ���Ϊһ���󶥶�
    }
    for (i=L.length;i>1;i--)  //Ҫ����L.length-1������ ÿ����������Ԫ���Ƶ����һ��λ�� ��ʣ���һ��ʱ�����������
    {
        L.r[0]=L.r[i];
        L.r[i]=L.r[1];
        L.r[1]=L.r[0];
        HeapAdjust (L , 1 , i-1);
    }
}

void HeapAdjust (SqList &L , int s , int m)  //s,m�ֱ��Ǵ�������ȫ������(����)�ĵ�һ�������һ��Ԫ��  //����Ϊһ���󶥶�
{
    int j;
    L.r[0]=L.r[s];  //�����һ��Ԫ��
    for (j=2*s;j<=m;j *= 2)
    {
        if ((j<m) && (L.r[j].key<L.r[j+1].key))  //jΪkey�ϴ��¼���±�
        {
            j++;
        }
        if (L.r[0].key >= L.r[j].key)
        {
            break;  //����ѭ��
        }
        L.r[s]=L.r[j];  //�ϴ��¼������
        s=j;  //s������
    }
    L.r[s]=L.r[0];  //������ĵ�һ��Ԫ���Ƶ���λ��
}

//8:�鲢����(2��·�鲢����)
void MergeSort (SqList &L)
{
    int s , t , i;
    t=1;
    while (t < L.length)
    {
        s=t;  //ÿ�κϲ������Ԫ�ظ���
        t=2*s;  //ÿ�κϲ����Ԫ�ظ���
        i=0;  //ÿ�ζ����㿪ʼ
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

void Merge_NoSpace (SqList &L , int i , int m , int n)  //L.r[i...m m+1 ...n]  //ÿ�������ϲ����õĺ���
{
    while (i <= m)  //ÿ�ζ�����С��Ԫ���õ�ǰ��һ������ ����һ�����������һ���Ƚϴ� ��ô�Ժ���һ�����н�������
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
        if (L.r[m+1].key > L.r[m+2].key)  //���۰��������ķ����Ժ���һ�����н�������  //Ҳ���������������򷽷�
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
            for (j=m+2; j<=high; j++)  //���۰�������� ���е㲻ͬ ������ǰ�ƶ�
            {
                L.r[j-1]=L.r[j];
            }
            L.r[high]=L.r[0];  //����λ����L.r[high] ��Ϊ����ǰ�ƶ� ���������ƶ����� L.r[high+1]
        }
    }
}



//9:��������(Ͱ����)































