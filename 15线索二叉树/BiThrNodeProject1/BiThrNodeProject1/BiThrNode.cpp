#include"BiThrNode.h"
typedef char Elemtype;
//线索二叉树
//枚举
typedef enum
{
	Link=0,//指向左右孩子
	Thread=1//指向前驱后继
}PointerTag;
//结构体
typedef struct TNode
{
	Elemtype data;
	TNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
}TNode,*LinkNode;
//前序构建二叉树
void Create(LinkNode *l)
{
	//构建
	Elemtype data;
	cin >> data;
	if (data == '#')
		*l = NULL;
	else
	{
		*l = (LinkNode)malloc(sizeof(TNode));
		if (!l)
			exit(OVERFLOW);
		(*l)->data = data;
		(*l)->ltag = Link;
		(*l)->rtag = Link;
		Create(&(*l)->lchild);
		Create(&(*l)->rchild);
	}
}
//构建中序线索二叉树
LinkNode pre=(LinkNode)malloc(sizeof(TNode));
void CreatT(TNode *l)
{
	if (l)
	{
		CreatT(l->lchild);
		if (!l->lchild)
		{
			l->ltag = Thread;
			l->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = l;
		}
		pre = l;
		CreatT(l->rchild);
	}	
}
//遍历线索二叉树
void Inorder(LinkNode *l)
{
	LinkNode p = *l;
	while (p!=NULL)
	{
		while (p->ltag == Link)
		{
			p = p->lchild;
		}
		cout << p->data <<" ";
		while (p->rtag == Thread && p->rchild  != NULL)
		{
			p = p->rchild;
			cout << p->data<<" ";
		}
		p = p->rchild;
	}
}
//主函数
int main()
{
	LinkNode *ln =new LinkNode;
//	LinkNode *nln = new LinkNode;
	int end;
	Create(ln);
	CreatT(*ln);
	Inorder(ln);
	cin >> end;
	return 0;
}