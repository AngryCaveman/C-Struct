#include"Tree01.h"
#define Maxsize 10
typedef string Elemtype;
//树的孩子表示法
//结点
typedef struct TNode
{
	int child;
	TNode *next;
}*TNodeStr;
//头结点
typedef struct HeadNode
{
	Elemtype data;
	TNodeStr FirstHead;
}HeadNode;
//树中所有结点
typedef struct Tree
{
	HeadNode nodes[Maxsize];
	int count;//结点数
}Tree;
//输入
void Input(Tree *t)
{
	int i, j,num;
	cout << "请输入结点个数:"; cin >> t->count;
	for (i = 0; i < t->count;i++)
	{
		HeadNode headnode;
		cout <<"第"<<i+1 <<"头结点:";cin >> headnode.data;
		cout << "与该结点相连的结点个数:"; cin >> num;
		if (num != 0){
			TNode *tn = new TNode;//处理firsthead指向的第一个结点
			cout << "第1个数据:"; cin >> tn->child;
			tn->next = NULL;
			headnode.FirstHead = tn;
			for (j = 1; j < num; j++)
			{
				TNode *td = new TNode;
				cout << "第" << j + 1 << "数据:"; cin >> td->child;
				td->next = NULL;
				tn->next = td;
				tn = td;
			}
		}
		else
			headnode.FirstHead = NULL;
		t->nodes[i] = headnode;
	}
}
//遍历
void Output(Tree *t)
{
	int i, j;
	string num;
	for (i = 0; i < t->count;i++)
	{
		num = t->nodes[i].data;
		TNodeStr hd;
		hd = t->nodes[i].FirstHead;
		while (hd!=NULL)
		{
			cout << "(" << num <<","<<t->nodes[hd->child].data<< ")"<<endl;
			hd = hd->next;
		}
	}
}
//主函数
int main()
{
	int end;
	Tree *tr=new Tree;
	Input(tr);
	Output(tr);
	cin >> end;
	return 0;
}