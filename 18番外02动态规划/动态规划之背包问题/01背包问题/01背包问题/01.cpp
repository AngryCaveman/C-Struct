#include"01.h"
#define N 3 //3个物品
#define W 50 //背包总重量
int f[N+1][W+1];//动态规划，记录不同物品，不同重量时的价值
//全局变量自动初始化为0
//01背包问题
void Bag(int *w,int *v)
{
	int i,j,max;
	for (i=1;i<=N;i++ )
	{
		for(j=1;j<=W;j++)
		{
			if(w[i]<=j)
			{
				if(f[i-1][j]<f[i-1][j-w[i]]+v[i])
				{
					max=f[i-1][j-w[i]]+v[i];
				}
				else
					max=f[i-1][j];
				f[i][j]=max;
			}
			else
				f[i][j]=f[i-1][j];
		}
	}
	cout<<f[N][W]<<endl;
}
//主函数
int main()
{
	int weight[N+1] = {0,10,20,30};  //每个物品的重量
	int vlaue[N+1] = {0,60,100,120}; //每个物品的价值
	//防止溢出
	Bag(weight,vlaue);
    //结束
	int end;
	cin>>end;
	return 0;
}