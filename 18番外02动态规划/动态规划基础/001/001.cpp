#include"001.h"
/*�����������ֵΪ1Ԫ��3Ԫ��5Ԫ��Ӳ������ö����������ٵ�Ӳ�Ҵչ�11Ԫ�� */
//��̬�滮����Ҫȷ��״̬��״̬ת�Ʒ���
//̰���㷨����ȡ����
#define Sum 11//����ֵ
#define Count 3//Ӳ��������
int main()
{
	int coin[Count]={1,3,5};//Ӳ������
	int Dp[Sum+1];//��¼��0-11��������Ŀ
	
	//�㷨
	int i,j;
	//��ʼ����ʹÿһ��Ǯ��Ϊ��Ӧ����Ϊ1��Ӳ�ҹ���
	for(i=0;i<=Sum;i++)
	{
		Dp[i]=i;
	}//Dp[0]=0��ʹ��
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
	//��ӡ
	cout<<Dp[Sum]<<endl;
	for(i=1;i<=Sum;i++)
	{
		cout<<Dp[i]<<" ";
	}
	//����
	int end;
	cin>>end;
	return 0;
}