#include"Tree01.h"
#define Maxsize 10
typedef string Elemtype;
//���ĺ��ӱ�ʾ��
//���
typedef struct TNode
{
	int child;
	TNode *next;
}*TNodeStr;
//ͷ���
typedef struct HeadNode
{
	Elemtype data;
	TNodeStr FirstHead;
}HeadNode;
//�������н��
typedef struct Tree
{
	HeadNode nodes[Maxsize];
	int count;//�����
}Tree;
//����
void Input(Tree *t)
{
	int i, j,num;
	cout << "�����������:"; cin >> t->count;
	for (i = 0; i < t->count;i++)
	{
		HeadNode headnode;
		cout <<"��"<<i+1 <<"ͷ���:";cin >> headnode.data;
		cout << "��ý�������Ľ�����:"; cin >> num;
		if (num != 0){
			TNode *tn = new TNode;//����firstheadָ��ĵ�һ�����
			cout << "��1������:"; cin >> tn->child;
			tn->next = NULL;
			headnode.FirstHead = tn;
			for (j = 1; j < num; j++)
			{
				TNode *td = new TNode;
				cout << "��" << j + 1 << "����:"; cin >> td->child;
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
//����
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
//������
int main()
{
	int end;
	Tree *tr=new Tree;
	Input(tr);
	Output(tr);
	cin >> end;
	return 0;
}