#include"01.h"
#define N 3 //3����Ʒ
#define W 50 //����������
int f[N+1][W+1];//��̬�滮����¼��ͬ��Ʒ����ͬ����ʱ�ļ�ֵ
//ȫ�ֱ����Զ���ʼ��Ϊ0
//01��������
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
//������
int main()
{
	int weight[N+1] = {0,10,20,30};  //ÿ����Ʒ������
	int vlaue[N+1] = {0,60,100,120}; //ÿ����Ʒ�ļ�ֵ
	//��ֹ���
	Bag(weight,vlaue);
    //����
	int end;
	cin>>end;
	return 0;
}