/*��N����Ʒ��һ������ΪV�ı�������i����Ʒ�����n[i]�����ã�
ÿ��������c[i]����ֵ��w[i]����⽫��Щ��Ʒװ�뱳����ʹ��Щ��Ʒ�ķ����ܺͲ����������������Ҽ�ֵ�ܺ����*/
#include<iostream>
using namespace std;
#define V 10
#define N 5
#define max(a,b) (a)>(b)?(a):(b)
double Dp[N+1][V+1];
unsigned int f[V+1];//ȫ�ֱ������Զ���ʼ��Ϊ0  
int main(){
	int Weight[N+1]={0,2,3,1,2,5}; //��һ������
	int Value[N+1]={0,2,2,4,5,1};
	int n[N+1]={0,3,2,4,1,1};//ÿ����Ʒ��Ӧ�ĸ���
	int count[N+1];//ʵʱ��������
	int i,j;
	//��ʼ��Count
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