#include"BiThrNode.h"
typedef char Elemtype;
//����������
//ö��
typedef enum
{
	Link=0,//ָ�����Һ���
	Thread=1//ָ��ǰ�����
}PointerTag;
//�ṹ��
typedef struct TNode
{
	Elemtype data;
	TNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
}TNode,*LinkNode;
//ǰ�򹹽�������
void Create(LinkNode *l)
{
	//����
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
//������������������
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
//��������������
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
//������
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