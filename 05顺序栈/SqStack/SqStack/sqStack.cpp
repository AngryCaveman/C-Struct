//˳��ջ:ջû�в��룬ɾ��
#include"sqStack.h"
#define ok 1
#define error 0
#define Max 10
typedef int Statu;
typedef int ElemType;
typedef struct
{
	ElemType data[Max];
	int top;
}SqStack;
//������������ǳ�ջ����ջ��count�ĳ�s->top����
void PrintList(SqStack *s)
{
	cout << "��������"<<endl;
	int count = s->top;
	while (count!=-1)//����-1Ϊ��ָ��
	{
		cout << s->data[count]<<endl;
		count--;
	}
}
//��ʼ��
Statu ListInit(SqStack *s,int len)
{
	int i;
	s->top = -1;
	if ((len<1) || (len>Max))
		return error;
	else
	{
		for (i = 0; i < len;i++)
		{
			cin >> s->data[i];
			s->top++;
		}
		return ok;
	}
}
//����:��ջ��������
Statu ListGet(SqStack *s,int p)
{
	int i;
	int t=s->top;
	for (i = 1; i < p;i++)
	{
		t--;
	}
	cout << "���ݣ�"<<s->data[t];
	return ok;
}
int main()
{
	int end;
	int length, vlaue, position;
	SqStack *sqstack=new SqStack;
	//��ʼ��
	cout << "������ջ���ȣ�"; cin >> length;
	end = ListInit(sqstack,length);
	PrintList(sqstack);
	//����
	cout << "������λ�ã�"; cin >> position;
	end = ListGet(sqstack,position);
	//����
	cin >> end;
	return 0;
}