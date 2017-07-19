#include"wpl.h"
#define Max 100
typedef char Elem;
typedef int  Val;//记录权值
//哈弗曼树与哈弗曼编码
typedef struct HNode
{
	Elem data;//数值
	Val v_data;//权值
	HNode *LChild;//左结点
	HNode *RChild;//右结点
}HNode,*Hlink;

//对输入的值，按权值从小到大排序
void Sort(HNode *h,int num)
{
	int i,j;
	for (i = 1; i <=num;i++)//冒泡
	{
		for (j = num - 1; j >=i; j--)
		{
			if (h[j].v_data > h[j + 1].v_data)
			{
				h[0] = h[j];
				h[j] = h[j + 1];
				h[j + 1] = h[0];
			}
		}
	}
}
//构建哈弗曼树
void Creat(Hlink *h,HNode *h_arry,int num)
{
	int i = 0;
	//处理结点
	for (i = 2; i <= num; i++)
	{
		HNode *tempNode = new HNode;
		tempNode->data = ' ';
		tempNode->LChild = NULL;
		tempNode->RChild = NULL;
		tempNode->v_data = h_arry[i-1].v_data + h_arry[i].v_data;
		if (h_arry[i - 1].v_data > h_arry[i].v_data)
		{
			tempNode->LChild = &h_arry[i];
			tempNode->RChild = &h_arry[i - 1];
		}
		else
		{
			tempNode->LChild = &h_arry[i-1];
			tempNode->RChild = &h_arry[i];
		}
		h_arry[i] = *tempNode;
		*h = tempNode;
	}
}
int main()
{
	int count,i;
	HNode hNum[Max];
	Hlink *hl=new Hlink;
	cout << "字母个数："; cin >> count;
	//输入,0位用于交换
	for (i = 1; i <=count;i++)
	{
		HNode n ;
		cout << "字母："; cin >> n.data;
		cout << "权值："; cin >> n.v_data;
		hNum[i] = n;
	}
	//排序
	Sort(hNum,count);
	//构建哈弗曼树
	Creat(hl,hNum,count);
	//
	return 0;
}