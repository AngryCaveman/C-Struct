/*该程序在Vs2013中编写完成
*/

#include"002.h"
/*线性链式结构*/
#define Ok 1//操作成功
#define Error 0//操作失败
#define MaxSize 100//栈满
int CurCount=0;//当前节点数
int head;
typedef int Statu;//链表操作状态回复
typedef int ElemType;//typedef 声明一个int类型
typedef struct Node
{
	ElemType item;//数据
	int age;//年龄
	Node *next;//下一个
};
typedef  Node *LinkList;
//输出链表
void ListPrint(LinkList l)
{
	cout << "输出结果" << endl;
	Node *n = l->next;
	while (n != NULL)
	{			
		cout << n->item<< " ";
		cout << n->age << "|";
		l = n->next;
		n = l;
	}
}
//初始化50个数据
Statu ListInit(LinkList l)
{
	int i;
	int len = 50;
	for (i = 0; i < len; i++)
	{
		++CurCount;
		Node *n = new Node;
		n->item=i+1;
		n->age = rand()%11;//随机产生一个1-10的随机数字充当年龄
		l->next = n;
		l = n;
	}
	l->next = NULL;
	return Ok;
}

//插入表,i为插入位置，e为插入元素
Statu  ListInsert(LinkList l, int i,ElemType n)
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
	num->item = n;
	num->age = 0;//默认秒为0
	//插入位置
	num->next = s->next;
	s->next = num;
	return Ok;
}
//删除表元素
Statu ListRemove(LinkList l, ElemType e)
{
	LinkList s,q;
	int i = 0;
	s = l;
	while (e!=s->item)
	{
		s = s->next;
	}
	q = s->next;
	s->next = q->next;
	free(q);//释放内存
	return Ok;
}
//按位置删除
Statu PositionListRemove(LinkList l, int i)
{
	LinkList s, q;
	int j = 1;
	s = l;
	while (s != NULL && j<i)
	{
		s = s->next;
		++j;
	}
	q = s->next;
	s->next = q->next;
	free(q);//释放内存
	return Ok;
}
//主函数
int main()
{
	int end;//函数执行状态反馈
	int count=0;//计数210次
	int position;//插入位置
	bool remflag,insflag;//是否继续删除
	int numCount;//结点数,生成随机数范围
	LinkList p = (LinkList)malloc(sizeof(Node));//创建头指针
	LinkList ls;//遍历
	end = ListInit(p);//初始化50个
	numCount = CurCount;
	head = p->next->item;
	//至少模拟200次
	while (count <= 210)
	{
		count++;
		insflag = true;
		remflag = true;
		ls = p->next;
		cout << count << "次："<<endl;
		Sleep(1000);//休眠1s
		//循环遍历更改参数
		while (ls->next!=NULL)
		{
			//淘汰
			if (numCount >= 100 && (remflag))
			{
				end=PositionListRemove(p, 1);
				remflag = false;
				numCount--;
			}
			else if ((ls->next->age>10) && (remflag))
			{
				cout << "删除：Item="<<ls->next->item<<"Age="<<ls->next->age<<endl;
				end = ListRemove(ls,ls->item);
				remflag = false;
				numCount--;
			}
			if (insflag)
			{
				//新增
				position = (rand() % numCount) + 1;/*产生区间[1,numCount]上的随机数*/;
				numCount++;
				CurCount++;
				cout << "新增：Item=" << CurCount <<"位置："<<position<< endl;
				end=ListInsert(ls, position, numCount);
				insflag = false;
			}
			//age +1
			ls->age += 1;
			ls = ls->next;
		}
		
	}
	cin>>end;
	return 0;
}