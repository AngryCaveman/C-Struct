#include "listnode.h"
/*������ʽ�ṹ*/
#define Ok 1;//�����ɹ�
#define Error 0;//����ʧ��

typedef int Statu;//�������״̬�ظ�
typedef int ElemType;//typedef ����һ��int����
typedef struct Node
{
	ElemType data;//����
	Node *next;//����
};
typedef  Node *LinkList;
//�������
void ListPrint(LinkList l)
{
	cout << "������" << endl;
	Node *n=l;
	while (n->next!=NULL)
	{
		 n=l;
		 cout << n<< endl;
		 cout << n->data<<endl;
		 l = n->next;
	}
}
//��ʼ����ʽ��
Statu ListInit(LinkList l,int len)
{
	int i;
	for (i = 0; i < len;i++)
	{
		Node *n=new Node;
		cout << n<<endl;
		cin >>n->data;
		l->next = n;
		l=n;
	}
	l->next = NULL;
	return Ok;
}
//����˳���,iΪ����λ�ã�eΪ����Ԫ��
Statu  ListInsert(LinkList l, int i,ElemType e)
{
	LinkList s;
	int j = 1;
	s = l;
	//����λ��
	while (s != NULL && j<i)//�õ�i-1�Ľ��
	{
		s = s->next;
		++j;
	}
	//�������
	LinkList num = (LinkList)malloc(sizeof(Node));
	num->data = e;
	//����λ��
	num->next = s->next;
	s->next = num;
	return Ok;
}
//��ȡ����Ԫ��
Statu ListGetEle(LinkList l,int i)
{
	int j = 0; ElemType num;
	LinkList s;
	s = l->next;
	while (s!=NULL && j<i)
	{
		j++;
		num = s->data;
		s = s->next;
	}
	cout << num<<endl;
	return Ok;
}
//ɾ��˳���Ԫ��
Statu ListRemove(LinkList l,int i)
{
	LinkList s,q;
	int j = 1;
	s = l;
	while (s != NULL && j<i)
	{
		s = s->next;
		++j;
	}
	q= s->next;
	s->next = q->next;
	free(q);//�ͷ��ڴ�
	return Ok;
}
//������
int main()
{
	int end, position,length;
	ElemType vlaue;
	LinkList p=(LinkList)malloc(sizeof(Node));//����ͷָ��
	p->next =NULL;
	cout <<p<<endl;
	cout << "������˳����ȣ�";cin >>length;
	end = ListInit(p,length);
	ListPrint(p);
	cout << "���������λ�ã�"; cin >> position;
    end = ListGetEle(p,position);
	//����
	cout << "����λ��:"; cin >> position;
	cout << "����ֵ:"; cin >> vlaue;
	ListInsert(p, position, vlaue);
	ListPrint(p);
	//ɾ��
	cout << "ɾ��λ��:"; cin >> position;
	ListRemove(p, position);
	ListPrint(p);
	cin >> end;
	return 0;
}