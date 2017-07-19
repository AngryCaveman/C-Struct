//顺序栈:栈没有插入，删除
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
//输出遍历：不是出栈，出栈把count改成s->top即可
void PrintList(SqStack *s)
{
	cout << "输出结果！"<<endl;
	int count = s->top;
	while (count!=-1)//等于-1为空指针
	{
		cout << s->data[count]<<endl;
		count--;
	}
}
//初始化
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
//查找:从栈顶往下找
Statu ListGet(SqStack *s,int p)
{
	int i;
	int t=s->top;
	for (i = 1; i < p;i++)
	{
		t--;
	}
	cout << "数据："<<s->data[t];
	return ok;
}
int main()
{
	int end;
	int length, vlaue, position;
	SqStack *sqstack=new SqStack;
	//初始化
	cout << "请输入栈长度："; cin >> length;
	end = ListInit(sqstack,length);
	PrintList(sqstack);
	//查找
	cout << "请输入位置："; cin >> position;
	end = ListGet(sqstack,position);
	//插入
	cin >> end;
	return 0;
}