//��ջ����һ�����飬����ͷ���м�,��ջ����ջ
#include"sqStackShare.h"
#define Max 10 //˳�����󳤶�
#define Ok 1//�����ɹ�
#define Error 0//����ʧ��
int StackNum=1;//�����������ĸ�ջ���ݽ���
typedef int Statu;//˳������״̬�ظ�
typedef int ElemType;//typedef ����һ��int����
typedef struct
{
	ElemType Data[Max];
	int top1;//1ջ
	int top2;//2ջ

}SqStackShare;
Statu Push(SqStackShare *s)
{
	if (s->top1 + 1 == s->top2)
		return Error;
	if (StackNum == 1)//1ջ��ջ
		cin >> s->Data[++s->top1];
	if (StackNum == 2)//1ջ��ջ
		cin >> s->Data[--s->top2];
	return Ok;
}
Statu Pop(SqStackShare *s)
{
	cout << "1��ջ" << endl;
	while (s->top1 != -1)
	{
		cout << s->Data[s->top1--]<<" ";
	}
	cout << endl;
	cout << "2��ջ" << endl;
	while (s->top2 != Max)
	{
		cout << s->Data[s->top2++]<<" ";
	}
	return Ok;
	return Ok;
}
int main()
{
	int end,i;
	ElemType vlaue;
	SqStackShare *Sq=new SqStackShare;
	Sq->top1 = -1;//��1ջ��
	Sq->top2 = Max;//��2ջ��
	//��ջ
	//1��6��
	StackNum = 1;
	cout << "1��ջ"<< endl;
	for (i = 0; i < 6; i++)
	{
		end = Push(Sq);
	}
	//2��4��
	StackNum = 2;
	cout << "2��ջ" << endl;
	for (i = 0; i < 4; i++)
	{
		end = Push(Sq);
	}
	//��ջ
	end=Pop(Sq);
	cin >> end;
	return 0;
}