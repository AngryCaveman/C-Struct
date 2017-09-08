/*有N种物品和一个容量为V的背包。第i种物品最多有n[i]件可用，
每件费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。*/
#include<iostream>
using namespace std;
#define V 10
#define N 5
#define max(a,b) (a)>(b)?(a):(b)
double Dp[N+1][V+1];
unsigned int f[V+1];//全局变量，自动初始化为0  
int main(){
	int Weight[N+1]={0,2,3,1,2,5}; //第一个不用
	int Value[N+1]={0,2,2,4,5,1};
	int n[N+1]={0,3,2,4,1,1};//每个物品对应的个数
	int count[N+1];//实时更改数量
	int i,j;
	//初始化Count
	for(i=0;i<=N;i++)
		count[i]=0;
	for(i=1;i<=N;i++){
		for(j=1;j<=V;j++){
			if(Weight[i]<=j && count[i]<n[i]){
				Dp[i][j]=max(Dp[i-1][j],Value[i]+Dp[i][j-Weight[i]]);
				count[i]++;
			}
		}
	}
	cout <<Dp[N][V];
	return 0;
}