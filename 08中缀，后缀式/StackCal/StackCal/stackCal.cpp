//ע�����λ��Ϊ��λ���������ѭ�����뼴�ɣ���������λ���������˴���Ҫ����
//��׺����׺ʽ���γ����磺9+��3-1��*3+8/2,����û��ע��count������������
#include"stackCal.h"/*��ջ�ṹ*/
#include<string>
#define Ok 1//�����ɹ�
#define Error 0//����ʧ��
typedef int Statu;//˳������״̬�ظ�
typedef char ElemType;//typedef ����һ������
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
Statu Push(LinkStack *l,ElemType e)
{
	StackNode *n = new StackNode;
	n->Data=e;
	n->next = l->top;
	l->top = n;
	l->count++;
	return Ok;
}
//��ջ
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
	LinkStack *ls = new LinkStack;//����ջ
	LinkStack *lsNum = new LinkStack;//��׺ʽջ
	LinkStack *lsNumCount = new LinkStack;//��׺ʽջ,����
	LinkStack *lsCal= new LinkStack;//��׺ʽ����ʱ������ջ
	ElemType flag=true;
	ls->top = NULL;
	lsNum->top = NULL;
	lsCal->top = NULL;
	lsNumCount->top = NULL;
	string cal;
	int i, j,end,sum[2],result,n=0;
	char calNum[20];
	cout << "������һ�����ʽ��"<<endl;
	cin >> cal;
	strcpy_s(calNum,cal.c_str());//�õ��ַ�����
	//��׺ʽ���ɺ�׺ʽ
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
	while (ls->top!=NULL)//�ѵ���󣬷���ջȫ��
	{
		end = Push(lsNum, Pop(ls));
	}
	//�Ȱ���׺ʽջ������
	while (lsNum->top!=NULL)
	{
		Push(lsNumCount, lsNum->top->Data);
		Pop(lsNum);
	}
	//��׺ʽ����
	while (lsNumCount->top != NULL)
	{
		switch (lsNumCount->top->Data)
		{
		case'/':
			for (j = 0; j < 2; j++)
			{
				sum[j] = (int)Pop(lsCal);//charתint
			}
			result = sum[1] / sum[0];
			Push(lsCal, result);//int תchar
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
