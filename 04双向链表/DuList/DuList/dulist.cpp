//双向链表:此处只提供了构造，遍历，反向遍历双向指针，插入删除跟单链表一致
#include"dulist.h"
#define ok 1;
#define error 0;
typedef int Statu;
typedef int ElemType;
typedef struct duListNode
{
	ElemType data;//数据
	duListNode *front;//前指针:从前往后指
	duListNode *rear;//后指针：从后往前指
}*Node;
//输出
void PrintList(Node head)
{
	Node n = head;
	Node start = n;
	//向后输出
	while (n!=NULL)
	{
		cout << n << " "<<n->data<<endl;
		start = n;
		n = n->front;
	}
	//向前输出
	while (start!=NULL)
	{
		cout << start << " " << start->data << endl;
		start = start->rear;
	}
	
}
//初始化
Statu ListInit(Node head,int len)
{
	int i;
	Node temp;
	head->rear = NULL;//从后往前末尾
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
	head->front = NULL;//末尾
	return ok;
}
int main()
{
	int length,end;
	//初始化
	Node s = (Node)malloc(sizeof(duListNode));
	cout << "请输入长度："; cin >> length;
	end=ListInit(s, length);
	PrintList(s);
	cin >> end;
	return 0;
}