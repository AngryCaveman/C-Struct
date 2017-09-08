#include"001.h"
//01背包问题：一个背包总容量为V，现在有N个物品，第i个 物品体积为weight[i]
//价值为value[i]，现在往背包里面装东西，怎么装能使背包的内物品价值最大？
#define V 10
#define N 5
#define max(a,b) (a)>(b)?(a):(b)
double Dp[N+1][V+1];
unsigned int f[V+1];//全局变量，自动初始化为0 
int main(){
	int Weight[N+1]={0,2,3,1,2,5}; //第一个不用
	int Value[N+1]={0,2,2,4,5,1};
	int i,j;
	/*
	for(i=1;i<=N;i++){
		for(j=1;j<=V;j++){
			if(Weight[i]<=j){
				Dp[i][j]=max(Dp[i-1][j],Value[i]+Dp[i-1][j-Weight[i]]);
			}
			else
				Dp[i][j]=Dp[i-1][j];
		}
	}
	cout <<Dp[N][V];
	*/
	  for (int i=1; i<=N; i++)  {
        for (int j=V; j>=1; j--)  
        {  
            if (Weight[i]<=j)  
            {  
                f[j]=max(f[j],f[j-Weight[i]]+Value[i]);  
            }             
        }  
	  } 
    cout<<f[V]<<endl;//输出最优解  
  
	return 0;
}