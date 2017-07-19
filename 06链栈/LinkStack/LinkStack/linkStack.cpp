#include"linkStack.h"
/*链栈结构*/
#define Ok 1//操作成功
#define Error 0//操作失败
typedef int Statu;//顺序表操作状态回复
typedef int ElemType;//typedef 声明一个int类型
//栈结点
typedef struct StackNode
{
	ElemType Data;
	StackNode *next;
}*StackLinkList;
//栈顶
typedef struct LinkStack
{
	StackLinkList top;
	int count;
}LinkStack;
//入栈
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
//出栈
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
	cout << "数据个数"; cin >> len;
	for (i = 0; i < len;i++)
	{
		end = Push(s);
	}
	end = Pop(s);
	cin >> end;
	return 0;
}