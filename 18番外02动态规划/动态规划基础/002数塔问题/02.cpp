#include"02.h"
//��������
/*
				9
			12		15
		10		6		8
	2		18		9		5
19		7		10		4		16
�Ӷ���������ÿһ���ڵ����ѡ��������������ߣ�һֱ�ߵ��ײ㣬
Ҫ���ҳ�һ��·����ʹ��·���ϵ�����֮�����.
*/
#define Max 5//�ױ��
int Dp[Max][Max];//ȫ�ֱ����Զ���ʼ��Ϊ0
int M[Max][Max]={
		{9,0,0,0,0},
		{12,15,0,0,0},
		{10,6,8,0,0},
		{2,18,9,5,0},
		{19,7,10,4,16}
	};//����ͼ
//�������⴦�������Ե�����Ѱ��
void DataTower()
{
	int i,j;
	//��ʼ��
	for (i=0;i<Max;i++)
	{
		Dp[Max-1][i]=M[Max-1][i];//����ͼ���һ��
	}

	//����
	for(i=Max-2;i>=0;i--)//���һ���Ѿ���ֵ������Max-1��û�и�ֵ
	{
		for(j=0;j<=i;j++)//��i�о���i��
		{
			//�ҳ������ӽڵ�����һ��
			if(Dp[i+1][j]>Dp[i+1][j+1])
				Dp[i][j]=Dp[i+1][j]+M[i][j];
			else
				Dp[i][j]=Dp[i+1][j+1]+M[i][j];
		}
	}
}
//��Dp����,��ӡ���ս��
void print ()
{
	cout << "���·���ͣ�" << Dp[0][0] << '\n';
    int node_value;
    // �����������Ԫ��
    cout << "���·����" << M[0][0];
    int j = 0;
    for (int i = 1; i < Max; ++i)
    {
        node_value = Dp[i - 1][j] - M[i - 1][j];
        /* ���node_value == dp[i][j]��˵����һ��Ӧ����data[i][j]�����node_value == dp[i][j + 1]��˵����һ��Ӧ����data[i][j + 1]*/
        if (node_value == Dp[i][j + 1]) ++j;
        cout << "->" << M[i][j];
    }
    cout << endl;
}
//������
int main ()
{
	
	DataTower();
	print();
	//����
	int end;
	cin>>end;
	return 0;
}