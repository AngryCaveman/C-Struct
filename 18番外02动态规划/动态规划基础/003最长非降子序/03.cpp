#include"03.h"
#define Max 6
//��ǽ�����
/*5��3��4��8��6��7
������е���ǽ�����
*/

//�Լ�������ķ���
void Long01(int *A)
{
	int Dp[Max];//��¼iλ�ö�Ӧ����Ӧ�ķǽ�����ĸ���
	int i,j;
	Dp[0]=1;//��һ��Ԫ��Ϊ�϶�Ϊ1
	for (i=1;i<Max;i++)
	{
		if(A[i]>=A[i-1])
		{
			Dp[i]=Dp[i-1]+1;
		}
		else
		{
			for(j=i-1;j>=0;j--)
			{
				if(A[i]>A[j])
				{
					Dp[i]=Dp[j]+1;
					break;
				}
			}
			if(j<0)
			{
				Dp[i]=1;
			}
		}
	}
}

//�����ṩ�ķ���
void  Long02(int *A)
{
	int d[Max];  
    int len = 1;  
    for(int i=0; i<Max; ++i){  
        d[i] = 1;  
        for(int j=0; j<i; ++j)  //ѭ��iǰ��ļ���Ԫ��
            if(A[j]<=A[i] && d[j]+1>d[i])  //iǰ���ܴ��ڶ��С��i��ֵ��ȡ����ߣ����˾��ô˴������Һ�һЩ
                d[i] = d[j] + 1;  
        if(d[i]>len) len = d[i];  
    }  

    cout<< len<<endl;  

}
//������
int main()
{
	int arry[Max]={5,9,4,8,6,7};//������

	Long01(arry);
	Long02(arry);
	//����
	int end;
	cin>>end;
	return 0;
}