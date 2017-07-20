#include "Prim.h"
#define Maxvex 9//结点数
#define INFINITY 65535//最大值
//普利木算法
void Prim(int M[Maxvex][Maxvex])
{
	//从0结点开始
	int adjvex[Maxvex];//存储对应结点的临结点
	int lowcost[Maxvex];//存储对应结点的权值
	adjvex[0] = 0;
	lowcost[0] = 0;//0值代表已经，对该结点已经选中过了

	//初始化
	int i,j=0,min,k;//k是用来临时存储权值最小点
	for (i = 1; i < Maxvex;i++)
	{
		lowcost[i] = M[0][i];
		adjvex[i] = 0;
	}
	//开始计算
	for (i = 1; i < Maxvex;i++)
	{
		min = INFINITY;
		j = 1;
		k = 0;
		//选出当前结点，相邻结点权值最小点
		while (j < Maxvex)
		{
			if (lowcost[j]!=0&&lowcost[j]<min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		//打印
		cout << adjvex[k] << " " << k << endl;
		lowcost[k] = 0;//k被选中
		//求k结点相邻的结点的权值，并更新lastcost数组
		for (j = 1; j < Maxvex; j++)
		{
			if (lowcost[j] != 0 && M[k][j]<lowcost[j])
			{
				lowcost[j] = M[k][j];
				adjvex[j] = k;//前往j点的临结点为k
			}
		}
	}
}
//主函数
int main()
{
	//构建图矩阵
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
	//结束
	int end;
	cin >> end;
	return 0;
}