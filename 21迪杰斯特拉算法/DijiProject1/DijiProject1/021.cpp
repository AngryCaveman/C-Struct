#include"021.h"
//�Ͻ�˹�����㷨��ʵ��
#define Maxvex 9 //�������
#define INFINITY 65535 //����ֵ
typedef int Patharc[Maxvex];//�洢·������(�����������෴)
typedef int ShortPathTable[Maxvex];//�洢���ý���ǰ�����
void ShortestPath_Dijkstra(int v0, int G[Maxvex][Maxvex], Patharc *p, ShortPathTable *s)
{
	int w,k;
	int fin[Maxvex];//��ֹ�ظ��ж���������·���ĵ㣬1Ϊ���жϣ�0Ϊδ�ж�
	for (w = 0; w < Maxvex; w++)
	{
		(*p)[w] = G[v0][w];//��ʼ��·��
		(*s)[w] = 0;//û��ǰ�����
		fin[w] = 0;
	}
	fin[v0] = 1;
	for (int i = 0; i < Maxvex;i++)
	{
		int min = INFINITY;
		for (w = 0; w < Maxvex;w++)
		{
			if (!fin[w]&&(*p)[w]<min)
			{
				k = w;//�����ǰ�����������ĵ㣬�ѳ䵱���ĵ����
				min = (*p)[w];
			}
		}
		
		fin[k] = 1;
		for (w = 0; w < Maxvex;w++)
		{
			if (!fin[w] && (min + G[k][w] < (*p)[w]))
			{
				(*p)[w] = min + G[k][w];
				(*s)[w] = k;//ǰ��w��ǰ����k
			}
		}
	}
}
//������
int main()
{
	//����ͼ����7
	int MyGraph[Maxvex][Maxvex] = { 
	{ 0, 1, 5, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY },
	{ 1, 0, 3, 7, 5, INFINITY, INFINITY, INFINITY, INFINITY },
	{ 5, 3, 0, INFINITY, 1, 7, INFINITY, INFINITY, INFINITY },
	{ INFINITY, 7, INFINITY, 0, 2, INFINITY, 3, INFINITY, INFINITY },
	{ INFINITY, 5, 1, 2, 0, 3, 6, 9, INFINITY },
	{ INFINITY, INFINITY, 7, INFINITY, 3, 0, INFINITY, 5, INFINITY },
	{ INFINITY, INFINITY, INFINITY, 3, 6, INFINITY, 0, 2, 7 },
	{ INFINITY, INFINITY, INFINITY, INFINITY ,9,5,2,0,4},
	{ INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY ,7,4,0} };
	int v;//���
	cin >> v;
	Patharc p;
	ShortPathTable s;
	ShortestPath_Dijkstra(v,MyGraph,&p,&s);//����
	//������յ��·����
	int e=-1;
	cin >> e;//�����յ�
	cout << "�ܳ��ȣ�" << p[e]<<endl;
	while (e != v){	
		cout << e << "<-";
		e = s[e];
	}
	cout << v << endl;
	//��ֹ���ڹر�
	int end;
	cin >> end;
	return 0;
}