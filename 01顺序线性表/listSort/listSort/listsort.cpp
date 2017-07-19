/*线性表顺序结构*/
#include"listsort.h"
#define Max 10 //顺序表最大长度
#define Ok 1;//操作成功
#define Error 0;//操作失败
typedef int Statu;//顺序表操作状态回复
typedef int ElemType;//typedef 声明一个int类型
typedef struct
{
	ElemType data[Max];//数据
	int length;//长度
}SqList;
//输入顺序表
void ListPrint(SqList l)
{
	int i;
	for (i = 0; i<l.length; i++)
	{
		cout << l.data[i]<< endl;
	}
	cout << "长度：" << l.length << endl;
}
//初始化顺序表
Statu ListInit(SqList *l)
{
	if ((l->length <= Max)&&(l->length>0))
	{

		int i = 0;
		for (i = 0; i < l->length; i++)
		{
			cout << "请输入第"<<(i+1)<<"个元素:";
			cin >> l->data[i];
		}
		return Ok;
	}
	else
	{
		cout << "输入长度不能大于10" << endl;
		return Error;
	}
}
//插入顺序表,i为插入位置，e为插入元素
Statu  ListInsert(SqList *l,int i,ElemType e)
{
	if (l->length == Max)//顺序表已满
		return Error;
	if ((i<1) || (i>l->length + 1))
		return Error;
	if (i <= l->length)
	{
		int j = 0;
		ElemType temp;
		for (j = l->length-1; j >= i - 1;j--)
		{
			l->data[j + 1] = l->data[j];
		}
		l->data[i - 1] = e;
		l->length++;
	}
}
//获取顺序表元素
Statu ListGetEle(SqList *l)
{
	int num;
	cout << "请输入获取元素序号：" << endl;
	cin >> num;
	if ((num > 0) && (num <= l->length))
	{
		cout << l->data[num - 1]<<endl;
		return Ok;
	}
	else
	{
		cout << "输入长度不合法！" << endl;
		return Error;
	}
}
//删除顺序表元素
Statu ListRemove(SqList *l,int i)
{
	if (l->length == 0)//顺序表为空
		return Error;
	if ((i<1) || (i>l->length + 1))
		return Error;
	if (i < l->length)
	{
		int j;
		for (j = i ; j < l->length;j++)
		{
			l->data[j - 1] = l->data[j];
		}
		l->length--;
	}
}
//主函数
int main()
{
	int end, position;
	ElemType vlaue;
	SqList *p = new SqList;
	cout << "请输入顺序表长度：";
	cin >> p->length;
	end =ListInit(p);
	end = ListGetEle(p);
	//插入
	cout << "插入位置:"; cin >> position;
	cout << "插入值:"; cin >> vlaue;
	ListInsert(p, position, vlaue);
	ListPrint(*p);
	//删除
	cout << "删除位置:"; cin >> position;
	ListRemove(p, position);
	ListPrint(*p);
	cin >> end;
	return 0;
}