#include"021.h"
//迪杰斯特拉算法的实现
#define Maxvex 9 //最大结点数
#define INFINITY 65535 //无穷值
typedef int Patharc[Maxvex];//存储到该结点的前驱结点
typedef int ShortPathTable[Maxvex];//存储路径长度
void ShortestPath_Dijkstra(int v0, int G[Maxvex][Maxvex], Patharc *p, ShortPathTable *s)
{
	int w,k;
	int fin[Maxvex];//防止重复判断已求出最短路径的点，1为已判断，0为未判断
	for (w = 0; w < Maxvex; w++)
	{
		(*s)[w] = G[v0][w];//初始化路径
		(*p)[w] = 0;//没有前驱结点
		fin[w] = 0;
	}
	fin[v0] = 1;
	for (int i = 0; i < Maxvex;i++)
	{
		int min = INFINITY;
		for (w = 0; w < Maxvex;w++)
		{
			if (!fin[w]&&(*s)[w]<min)
			{
				k = w;//求出当前距离起点最近的点，已充当过的点除外
				min = (*s)[w];
			}
		}
		
		fin[k] = 1;
		for (w = 0; w < Maxvex;w++)
		{
			if (!fin[w] && (min + G[k][w] < (*s)[w]))
			{
				(*s)[w] = min + G[k][w];
				(*p)[w] = k;//前往w的前驱是k
			}
		}
	}
}
//主函数
int main()
{
	//构建图矩阵7
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
	int v;//起点
	cin >> v;
	Patharc p;
	ShortPathTable s;
	ShortestPath_Dijkstra(v,MyGraph,&p,&s);//调用
	//输出到终点的路径，
	int e=-1;
	cin >> e;//输入终点
	cout << "总长度：" << s[e]<<endl;
	while (e != v){	
		cout << e << "<-";
		e = p[e];
	}
	cout << v << endl;
	//防止窗口关闭
	int end;
	cin >> end;
	return 0;
}