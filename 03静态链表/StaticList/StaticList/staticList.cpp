#include "staticList.h"
#define Max 10
#define ok 1
#define error 0
typedef int Statu;
typedef int ElemType;
//定义静态链表结点结构体
typedef struct StaticNode
{
	ElemType data;//数据
	int cur;//游标
}StaticLinkList[Max];//因为有typedef所以此处不是对象
void PrintList(StaticLinkList space)
{
	int i = 1,j=0;
	while (space[j].cur!=0)
	{
		j = i;
		cout << space[i].data << endl;
		i = space[i].cur;
	}
}
//初始化函数
Statu ListInit(StaticLinkList space,int len)
{
	int i;
	if ((len > Max) || (len < 0))
		return error;
	else
	{
		space[0].cur = len + 1;
		
		for (i = 1; i <=len; i++)
		{
			cin >> space[i].data;
			space[i].cur = i + 1;
			if (i == len)
				space[len].cur = 0;//终点
		}
		//把后面的cur设置成固定的
		for (i = len + 1; i <= Max; i++)
		{
			space[i].cur = i + 1;
			if (i == Max)
			{
				space[Max].cur = 1;//记录起点，如果是0，代表是空
			}
		}
		return ok;
	}
}
//获取分配下标
int Malloc_SLL(StaticLinkList space)
{
	int i=space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
	}
	return i;
}
//删除
Statu ListRemove(StaticLinkList space, int j)
{
	//查找要删除的位置
	int i = 1;
	int start = space[Max].cur;
	int nend;
	while (i != j - 1)
	{
		i++;
		start = space[start].cur;
	}
	//删除
	nend = space[start].cur;
	space[start].cur = space[nend].cur;
	//回收
	space[nend].cur = space[0].cur;
	space[0].cur = nend;
	return ok;
}
//插入
Statu ListInsert(StaticLinkList space,int j,ElemType e)
{
	int i =1;
	int start = space[Max].cur;
	int nend;
	while (i!=j-1)
	{
		i++;
		start = space[start].cur;
	}
	nend = space[space[0].cur].cur;
	space[space[0].cur].data = e;
	space[space[0].cur].cur = space[start].cur;
	space[start].cur = space[0].cur;
	space[0].cur = nend;
	return ok;
}
//主函数
int main()
{
	Statu end;
	int position, vlaue, length;
	StaticLinkList s ={};
	//初始化
	cout << "请输入长度："; cin >> length;
	end = ListInit(s,length);
	PrintList(s);
	//插入
	cout << "插入位置:"; cin >> position;
	cout << "值:"; cin >> vlaue;
	end=ListInsert(s, position, vlaue);
	PrintList(s);
	//删除
	cout << "删除位置:"; cin >> position;
	end = ListRemove(s, position);
	PrintList(s);

	cin >> end;
	return 0;
}
