#include"001.h"
//01�������⣺һ������������ΪV��������N����Ʒ����i�� ��Ʒ���Ϊweight[i]
//��ֵΪvalue[i]����������������װ��������ôװ��ʹ����������Ʒ��ֵ���
#define V 10
#define N 5
#define max(a,b) (a)>(b)?(a):(b)
double Dp[N+1][V+1];
unsigned int f[V+1];//ȫ�ֱ������Զ���ʼ��Ϊ0 
int main(){
	int Weight[N+1]={0,2,3,1,2,5}; //��һ������
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
    cout<<f[V]<<endl;//������Ž�  
  
	return 0;
}