#include"03.h"
#define Max 6
//最长非降子序
/*5，3，4，8，6，7
求该数列的最长非降子序
*/

//自己想出来的方法
void Long01(int *A)
{
	int Dp[Max];//记录i位置对应的相应的非降子序的个数
	int i,j;
	Dp[0]=1;//第一个元素为肯定为1
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

//网上提供的方法
void  Long02(int *A)
{
	int d[Max];  
    int len = 1;  
    for(int i=0; i<Max; ++i){  
        d[i] = 1;  
        for(int j=0; j<i; ++j)  //循环i前面的几个元素
            if(A[j]<=A[i] && d[j]+1>d[i])  //i前可能存在多个小于i的值，取最大者，个人觉得此处倒着找好一些
                d[i] = d[j] + 1;  
        if(d[i]>len) len = d[i];  
    }  

    cout<< len<<endl;  

}
//主函数
int main()
{
	int arry[Max]={5,9,4,8,6,7};//主序列

	Long01(arry);
	Long02(arry);
	//结束
	int end;
	cin>>end;
	return 0;
}