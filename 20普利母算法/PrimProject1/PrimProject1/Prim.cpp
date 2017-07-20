#include "Prim.h"
#define Maxvex 9//�����
#define INFINITY 65535//���ֵ
//����ľ�㷨
void Prim(int M[Maxvex][Maxvex])
{
	//��0��㿪ʼ
	int adjvex[Maxvex];//�洢��Ӧ�����ٽ��
	int lowcost[Maxvex];//�洢��Ӧ����Ȩֵ
	adjvex[0] = 0;
	lowcost[0] = 0;//0ֵ�����Ѿ����Ըý���Ѿ�ѡ�й���

	//��ʼ��
	int i,j=0,min,k;//k��������ʱ�洢Ȩֵ��С��
	for (i = 1; i < Maxvex;i++)
	{
		lowcost[i] = M[0][i];
		adjvex[i] = 0;
	}
	//��ʼ����
	for (i = 1; i < Maxvex;i++)
	{
		min = INFINITY;
		j = 1;
		k = 0;
		//ѡ����ǰ��㣬���ڽ��Ȩֵ��С��
		while (j < Maxvex)
		{
			if (lowcost[j]!=0&&lowcost[j]<min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		//��ӡ
		cout << adjvex[k] << " " << k << endl;
		lowcost[k] = 0;//k��ѡ��
		//��k������ڵĽ���Ȩֵ��������lastcost����
		for (j = 1; j < Maxvex; j++)
		{
			if (lowcost[j] != 0 && M[k][j]<lowcost[j])
			{
				lowcost[j] = M[k][j];
				adjvex[j] = k;//ǰ��j����ٽ��Ϊk
			}
		}
	}
}
//������
int main()
{
	//����ͼ����
	int MyGraph[Maxvex][Maxvex] = {
		{ 0, 10, INFINITY, INFINITY, INFINITY, 11, INFINITY, INFINITY, INFINITY },
		{ 10, 0, 18, INFINITY, INFINITY, INFINITY,16 , INFINITY, 12 },
		{ INFINITY, INFINITY, 0, 22, INFINITY, INFINITY, INFINITY, INFINITY, 8 },
		{ INFINITY, INFINITY, 22, 0, 20, INFINITY, INFINITY, 16, 21 },
		{ INFINITY, INFINITY, INFINITY, 20, 0, 26, INFINITY, 7, INFINITY },
		{ 11, INFINITY, INFINITY, INFINITY, 20, 0, 17, INFINITY, INFINITY },
		{ INFINITY, 16, INFINITY, INFINITY, INFINITY, 17, 0, 19, INFINITY },
		{ INFINITY, INFINITY, INFINITY, 16, 7, INFINITY, 19, 0, INFINITY },
		{ INFINITY, 12, 8, 21, INFINITY, INFINITY, INFINITY, INFINITY, 0 } };
	Prim(MyGraph);
	//����
	int end;
	cin >> end;
	return 0;
}