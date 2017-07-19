#include "listnode.h"
/*线性链式结构*/
#define Ok 1;//操作成功
#define Error 0;//操作失败

typedef int Statu;//链表操作状态回复
typedef int ElemType;//typedef 声明一个int类型
typedef struct Node
{
	ElemType data;//数据
	Node *next;//长度
};
typedef  Node *LinkList;
//输出链表
void ListPrint(LinkList l)
{
	cout << "输出结果" << endl;
	Node *n=l;
	while (n->next!=NULL)
	{
		 n=l;
		 cout << n<< endl;
		 cout << n->data<<endl;
		 l = n->next;
	}
}
//初始化链式表
Statu ListInit(LinkList l,int len)
{
	int i;
	for (i = 0; i < len;i++)
	{
		Node *n=new Node;
		cout << n<<endl;
		cin >>n->data;
		l->next = n;
		l=n;
	}
	l->next = NULL;
	return Ok;
}
//插入顺序表,i为插入位置，e为插入元素
Statu  ListInsert(LinkList l, int i,ElemType e)
{
	LinkList s;
	int j = 1;
	s = l;
	//查找位置
	while (s != NULL && j<i)//得到i-1的结点
	{
		s = s->next;
		++j;
	}
	//创建结点
	LinkList num = (LinkList)malloc(sizeof(Node));
	num->data = e;
	//插入位置
	num->next = s->next;
	s->next = num;
	return Ok;
}
//获取链表元素
Statu ListGetEle(LinkList l,int i)
{
	int j = 0; ElemType num;
	LinkList s;
	s = l->next;
	while (s!=NULL && j<i)
	{
		j++;
		num = s->data;
		s = s->next;
	}
	cout << num<<endl;
	return Ok;
}
//删除顺序表元素
Statu ListRemove(LinkList l,int i)
{
	LinkList s,q;
	int j = 1;
	s = l;
	while (s != NULL && j<i)
	{
		s = s->next;
		++j;
	}
	q= s->next;
	s->next = q->next;
	free(q);//释放内存
	return Ok;
}
//主函数
int main()
{
	int end, position,length;
	ElemType vlaue;
	LinkList p=(LinkList)malloc(sizeof(Node));//创建头指针
	p->next =NULL;
	cout <<p<<endl;
	cout << "请输入顺序表长度：";cin >>length;
	end = ListInit(p,length);
	ListPrint(p);
	cout << "请输入查找位置："; cin >> position;
    end = ListGetEle(p,position);
	//插入
	cout << "插入位置:"; cin >> position;
	cout << "插入值:"; cin >> vlaue;
	ListInsert(p, position, vlaue);
	ListPrint(p);
	//删除
	cout << "删除位置:"; cin >> position;
	ListRemove(p, position);
	ListPrint(p);
	cin >> end;
	return 0;
}