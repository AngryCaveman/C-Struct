//˫������:�˴�ֻ�ṩ�˹��죬�������������˫��ָ�룬����ɾ����������һ��
#include"dulist.h"
#define ok 1;
#define error 0;
typedef int Statu;
typedef int ElemType;
typedef struct duListNode
{
	ElemType data;//����
	duListNode *front;//ǰָ��:��ǰ����ָ
	duListNode *rear;//��ָ�룺�Ӻ���ǰָ
}*Node;
//���
void PrintList(Node head)
{
	Node n = head;
	Node start = n;
	//������
	while (n!=NULL)
	{
		cout << n << " "<<n->data<<endl;
		start = n;
		n = n->front;
	}
	//��ǰ���
	while (start!=NULL)
	{
		cout << start << " " << start->data << endl;
		start = start->rear;
	}
	
}
//��ʼ��
Statu ListInit(Node head,int len)
{
	int i;
	Node temp;
	head->rear = NULL;//�Ӻ���ǰĩβ
	for (i = 1; i <= len;i++)
	{
		Node n = (Node)malloc(sizeof(duListNode));
		cin >> n->data;
		head->front = n;
		n->rear = head;
		//temp = n;
		head = n;
		//head->rear = temp;
	}
	head->front = NULL;//ĩβ
	return ok;
}
int main()
{
	int length,end;
	//��ʼ��
	Node s = (Node)malloc(sizeof(duListNode));
	cout << "�����볤�ȣ�"; cin >> length;
	end=ListInit(s, length);
	PrintList(s);
	cin >> end;
	return 0;
}