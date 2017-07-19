//注意计算位数为个位，如果采用循环输入即可，计算任意位数，不过此处主要测试
//中缀，后缀式的形成例如：9+（3-1）*3+8/2,另外没关注过count，当它不存在
#include"stackCal.h"/*链栈结构*/
#include<string>
#define Ok 1//操作成功
#define Error 0//操作失败
typedef int Statu;//顺序表操作状态回复
typedef char ElemType;//typedef 声明一个类型
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
Statu Push(LinkStack *l,ElemType e)
{
	StackNode *n = new StackNode;
	n->Data=e;
	n->next = l->top;
	l->top = n;
	l->count++;
	return Ok;
}
//出栈
ElemType Pop(LinkStack *l)
{
	StackNode *t = l->top;
	ElemType e;
	e=t->Data ;
	l->top = t->next;
	free(t);
	return e;
}
int main()
{
	//LinkStack *Ls=(LinkStack)malloc(sizeof(StackNode));
	LinkStack *ls = new LinkStack;//符号栈
	LinkStack *lsNum = new LinkStack;//中缀式栈
	LinkStack *lsNumCount = new LinkStack;//中缀式栈,计算
	LinkStack *lsCal= new LinkStack;//后缀式计算时的数字栈
	ElemType flag=true;
	ls->top = NULL;
	lsNum->top = NULL;
	lsCal->top = NULL;
	lsNumCount->top = NULL;
	string cal;
	int i, j,end,sum[2],result,n=0;
	char calNum[20];
	cout << "请输入一个表达式："<<endl;
	cin >> cal;
	strcpy_s(calNum,cal.c_str());//得到字符数组
	//中缀式化成后缀式
	for (i = 0; i < strlen(calNum); i++)
	{
		switch (calNum[i])
		{
		case'(':
			end = Push(ls, calNum[i]);
			break;
		case')':
			while (ls->top->Data != '(')
			{
				end = Push(lsNum, Pop(ls));
			}
			if (ls->top->Data == '(')
				flag = Pop(ls);
			break;
		case'/':
		case'*':
			if (ls->top == NULL)
				end = Push(ls, calNum[i]);
			else
			{
				while ((ls->top->Data == '*') || (ls->top->Data == '/'))
				{
					end = Push(lsNum, Pop(ls));
				}
				end = Push(ls, calNum[i]);
			}
			break;
		case '+':
		case'-':
			while (ls->top!=NULL)
			{
				if (ls->top->Data == '(')
				{
					end = Push(ls, calNum[i]);
					break;
				}
				else
				{
					end = Push(lsNum, Pop(ls));
				}
			}
			if(ls->top == NULL)
				end = Push(ls, calNum[i]);
			break;
		default:
			end = Push(lsNum, calNum[i]);
			break;
		}
	}
	while (ls->top!=NULL)//已到最后，符号栈全出
	{
		end = Push(lsNum, Pop(ls));
	}
	//先把中缀式栈倒过来
	while (lsNum->top!=NULL)
	{
		Push(lsNumCount, lsNum->top->Data);
		Pop(lsNum);
	}
	//后缀式计算
	while (lsNumCount->top != NULL)
	{
		switch (lsNumCount->top->Data)
		{
		case'/':
			for (j = 0; j < 2; j++)
			{
				sum[j] = (int)Pop(lsCal);//char转int
			}
			result = sum[1] / sum[0];
			Push(lsCal, result);//int 转char
			break;
		case'*':
			for (j = 0; j < 2; j++)
			{
				sum[j] = (int)Pop(lsCal);
			}
			result = sum[1] * sum[0];
			Push(lsCal, result);
			break;
		case '+':
			for (j = 0; j < 2; j++)
			{
				sum[j] = (int)Pop(lsCal);
			}
			result = sum[1] +sum[0];
			Push(lsCal, result);
			break;
		case'-':
			for (j = 0; j < 2;j++)
			{
				sum[j] = (int)Pop(lsCal);
			}
			result = sum[1] - sum[0];
			Push(lsCal, result);
			break;
		default:
			Push(lsCal, lsNumCount->top->Data);
			break;
		}
		flag = Pop(lsNumCount);
	}
	cout << lsCal->top->Data+'0';
	cin >> flag;
	return 0;
}
