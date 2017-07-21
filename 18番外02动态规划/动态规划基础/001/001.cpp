#include"001.h"
/*如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？ */
//动态规划：需要确定状态和状态转移方程
//贪心算法：先取最大的
#define Sum 11//最终值
#define Count 3//硬币类型数
int main()
{
	int coin[Count]={1,3,5};//硬币类型
	int Dp[Sum+1];//记录从0-11的银币数目
	
	//算法
	int i,j;
	//初始化，使每一个钱数为相应个数为1的硬币构成
	for(i=0;i<=Sum;i++)
	{
		Dp[i]=i;
	}//Dp[0]=0不使用
	for(i=1;i<=Sum;i++)
	{
		for(j=0;j<Count ;j++)
		{
			if(i>=coin[j]&&Dp[i-coin[j]]+1<Dp[i])
			{
				Dp[i]=Dp[i-coin[j]]+1;
			}
		}
	}
	//打印
	cout<<Dp[Sum]<<endl;
	for(i=1;i<=Sum;i++)
	{
		cout<<Dp[i]<<" ";
	}
	//结束
	int end;
	cin>>end;
	return 0;
}