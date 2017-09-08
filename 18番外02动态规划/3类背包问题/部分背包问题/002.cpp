#include"002.h"
#define V 10
#define N 5
#define max(a,b) (a)>(b)?(a):(b)
double Dp[N+1][V+1];
unsigned int f[V+1];//全局变量，自动初始化为0  
int main(){
	int Weight[N+1]={0,2,3,1,2,5}; //第一个不用
	int Value[N+1]={0,2,2,4,5,1};
	int i,j,temp;
	
	for(i=1;i<=N;i++){
		for(j=1;j<=V;j++){
			if(Weight[i]<=j){
				temp=max(Dp[i-1][j],Value[i]+Dp[i][j-Weight[i]]);
				Dp[i][j]=max(temp,Value[i]+Dp[i][j-Weight[i]]);
			}
			else
				Dp[i][j]=Dp[i][j];
		}
	}
	cout <<Dp[N][V];
	/*
	 for (int i=1; i<=N; i++)  {
        for (int j=1; j<=V; j++)  
        {  
            if (Weight[i]<=j)  
            {  
                f[j]=max(f[j],f[j-Weight[i]]+Value[i]);  
            }             
        }  
	 } 
	
    cout<<f[V]<<endl;//输出最优解  */ 
	return 0;
}