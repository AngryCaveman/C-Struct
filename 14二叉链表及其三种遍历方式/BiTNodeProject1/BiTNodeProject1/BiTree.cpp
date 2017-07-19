#include"BiTree.h"
#define Maxsize 20
typedef char Elemtype;//Elemtype��string�ᱨ��

//�������������ֱ�����ʽ
//���
typedef struct BiNode
{
	Elemtype data;
	BiNode *Lchild, *Rchild;
	
}BiNode,*BiTree;
//���ɶ�������ǰ��ʽ
void CreateBiTree(BiTree *b)
{
	//����
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
//�������
void PreOrder(BiTree b)
{
	if (b == NULL)
		return;
	cout << (*b).data<<" ";
	PreOrder(b->Lchild);
	PreOrder(b->Rchild);
}
//�������
void InOrder(BiTree b)
{
	if (b == NULL)
		return;
	InOrder(b->Lchild);
	cout << (*b).data << " ";
	InOrder(b->Rchild);
}
//�������
void PostOrder(BiTree b)
{
	if (b == NULL)
		return;
	PostOrder(b->Lchild);
	PostOrder(b->Rchild);
	cout << (*b).data << " ";
}
//������
int main()
{
	BiTree *bt=new BiTree;
	int end,i;
	//����ǰ������ķ�ʽ����
	int count;
	cout << "Ĭ����Ϊ��ȫ���������޽�㴦��#�ţ�д����Ҫ�����Ķ�������ǰ�������" << endl;
	CreateBiTree(bt);//����
	cout << "������������ɣ�" << endl;
	cout << "�������" << endl;
	PreOrder(*bt);
	cout << endl;
	cout << "�������" << endl;
	InOrder(*bt);
	cout << endl;
	cout << "�������" << endl;
	PostOrder(*bt);
	cin >> end;
	return 0;
}