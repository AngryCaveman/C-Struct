#include"linkStack.h"
/*��ջ�ṹ*/
#define Ok 1//�����ɹ�
#define Error 0//����ʧ��
typedef int Statu;//˳������״̬�ظ�
typedef int ElemType;//typedef ����һ��int����
//ջ���
typedef struct StackNode
{
	ElemType Data;
	StackNode *next;
}*StackLinkList;
//ջ��
typedef struct LinkStack
{
	StackLinkList top;
	int count;
}LinkStack;
//��ջ
Statu Push(LinkStack *l)
{
	StackNode *n = new StackNode;
	cout << n<<endl;
	cin >> n->Data;
	n->next = l->top;
	l->top = n;
	l->count++;
	return Ok;
}
//��ջ
Statu Pop(LinkStack *l)
{
	while (l->top!=NULL)
	{
		cout<<l->top->Data<<endl;
		l->top = l->top->next;
	}
	return Ok;
}
int main()
{
	LinkStack *s = new LinkStack;
	s->count=0;
	s->top = NULL;
	int len,i;
	Statu end;
	cout << "���ݸ���"; cin >> len;
	for (i = 0; i < len;i++)
	{
		end = Push(s);
	}
	end = Pop(s);
	cin >> end;
	return 0;
}