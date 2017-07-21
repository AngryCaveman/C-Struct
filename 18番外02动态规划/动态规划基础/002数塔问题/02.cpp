#include"02.h"
//数塔问题
/*
				9
			12		15
		10		6		8
	2		18		9		5
19		7		10		4		16
从顶部出发在每一个节点可以选择向左或者向右走，一直走到底层，
要求找出一条路径，使得路径上的数字之和最大.
*/
#define Max 5//底边最长
int Dp[Max][Max];//全局变量自动初始化为0
int M[Max][Max]={
		{9,0,0,0,0},
		{12,15,0,0,0},
		{10,6,8,0,0},
		{2,18,9,5,0},
		{19,7,10,4,16}
	};//构建图
//数塔问题处理函数，自底向上寻找
void DataTower()
{
	int i,j;
	//初始化
	for (i=0;i<Max;i++)
	{
		Dp[Max-1][i]=M[Max-1][i];//复制图最后一列
	}

	//计算
	for(i=Max-2;i>=0;i--)//最后一行已经赋值，还有Max-1行没有赋值
	{
		for(j=0;j<=i;j++)//第i行就有i列
		{
			//找出左右子节点最大的一个
			if(Dp[i+1][j]>Dp[i+1][j+1])
				Dp[i][j]=Dp[i+1][j]+M[i][j];
			else
				Dp[i][j]=Dp[i+1][j+1]+M[i][j];
		}
	}
}
//由Dp数组,打印最终结果
void print ()
{
	cout << "最大路径和：" << Dp[0][0] << '\n';
    int node_value;
    // 首先输出塔顶元素
    cout << "最大路径：" << M[0][0];
    int j = 0;
    for (int i = 1; i < Max; ++i)
    {
        node_value = Dp[i - 1][j] - M[i - 1][j];
        /* 如果node_value == dp[i][j]则说明下一步应该是data[i][j]；如果node_value == dp[i][j + 1]则说明下一步应该是data[i][j + 1]*/
        if (node_value == Dp[i][j + 1]) ++j;
        cout << "->" << M[i][j];
    }
    cout << endl;
}
//主函数
int main ()
{
	
	DataTower();
	print();
	//结束
	int end;
	cin>>end;
	return 0;
}