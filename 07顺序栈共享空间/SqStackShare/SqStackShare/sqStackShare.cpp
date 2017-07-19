//两栈公用一个数组，从两头往中间,进栈，出栈
#include"sqStackShare.h"
#define Max 10 //顺序表最大长度
#define Ok 1//操作成功
#define Error 0//操作失败
int StackNum=1;//用于区分是哪个栈数据进入
typedef int Statu;//顺序表操作状态回复
typedef int ElemType;//typedef 声明一个int类型
typedef struct
{
	ElemType Data[Max];
	int top1;//1栈
	int top2;//2栈

}SqStackShare;
Statu Push(SqStackShare *s)
{
	if (s->top1 + 1 == s->top2)
		return Error;
	if (StackNum == 1)//1栈入栈
		cin >> s->Data[++s->top1];
	if (StackNum == 2)//1栈入栈
		cin >> s->Data[--s->top2];
	return Ok;
}
Statu Pop(SqStackShare *s)
{
	cout << "1出栈" << endl;
	while (s->top1 != -1)
	{
		cout << s->Data[s->top1--]<<" ";
	}
	cout << endl;
	cout << "2出栈" << endl;
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
	Sq->top1 = -1;//设1栈空
	Sq->top2 = Max;//设2栈空
	//入栈
	//1来6个
	StackNum = 1;
	cout << "1入栈"<< endl;
	for (i = 0; i < 6; i++)
	{
		end = Push(Sq);
	}
	//2来4个
	StackNum = 2;
	cout << "2入栈" << endl;
	for (i = 0; i < 4; i++)
	{
		end = Push(Sq);
	}
	//出栈
	end=Pop(Sq);
	cin >> end;
	return 0;
}