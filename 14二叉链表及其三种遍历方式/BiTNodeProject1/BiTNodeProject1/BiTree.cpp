#include"BiTree.h"
#define Maxsize 20
typedef char Elemtype;//Elemtype用string会报错

//二叉链表及其三种遍历方式
//结点
typedef struct BiNode
{
	Elemtype data;
	BiNode *Lchild, *Rchild;
	
}BiNode,*BiTree;
//生成二叉树，前序方式
void CreateBiTree(BiTree *b)
{
	//构建
	Elemtype data;
	cin >> data;
	if ( data== '#')
		*b = NULL;
	else
	{
		*b = (BiTree)malloc(sizeof(BiNode));
		if (!b)
			exit(OVERFLOW);
		(*b)->data = data;
		CreateBiTree(&(*b)->Lchild);
		CreateBiTree(&(*b)->Rchild);
	}
}
//先序遍历
void PreOrder(BiTree b)
{
	if (b == NULL)
		return;
	cout << (*b).data<<" ";
	PreOrder(b->Lchild);
	PreOrder(b->Rchild);
}
//中序遍历
void InOrder(BiTree b)
{
	if (b == NULL)
		return;
	InOrder(b->Lchild);
	cout << (*b).data << " ";
	InOrder(b->Rchild);
}
//后序遍历
void PostOrder(BiTree b)
{
	if (b == NULL)
		return;
	PostOrder(b->Lchild);
	PostOrder(b->Rchild);
	cout << (*b).data << " ";
}
//主函数
int main()
{
	BiTree *bt=new BiTree;
	int end,i;
	//采用前序遍历的方式构建
	int count;
	cout << "默认其为完全二叉树，无结点处用#号，写出所要构建的二叉树的前序遍历！" << endl;
	CreateBiTree(bt);//创建
	cout << "二叉树创建完成！" << endl;
	cout << "先序遍历" << endl;
	PreOrder(*bt);
	cout << endl;
	cout << "中序遍历" << endl;
	InOrder(*bt);
	cout << endl;
	cout << "后序遍历" << endl;
	PostOrder(*bt);
	cin >> end;
	return 0;
}