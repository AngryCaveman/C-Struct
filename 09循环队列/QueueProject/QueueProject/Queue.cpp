//循环队列：对队列顺序存储结构的改进,注意判断队满的条件
//头文件
#include"Queue.h"
#define OK 0//成功
#define ERROR 1//失败
#define MAXSIZE 11//队列最大值10,空出一个
typedef int Statu;//函数操作状态
typedef int ElemType;//数据类型
//结构
typedef struct Queue
{
	int front;
	int rear;
	ElemType data[MAXSIZE];
}SqQueue;
//初始化
Statu InitQueue(SqQueue *s)
{
	s->front = 0;
	s->rear = 0;
	return OK;
}
//入队
Statu PutQueue(SqQueue *s,ElemType e)
{
	if ((s->rear +1)%MAXSIZE==s->front)//队满
	{
		return ERROR;
	}
	else
	{
		s->data[s->rear] = e;
		s->rear = (s->rear+1)%MAXSIZE;
		return OK;
	}
}
//出队
Statu OutQueue(SqQueue *s,ElemType *e)
{
	if (s->rear ==s->front)
	{
		return ERROR;
	}
	else
	{
		*e = s->data[s->front];//没有删除，新值会覆盖的
		s->front = (s->front+1)%MAXSIZE;
		return OK;
	}
}
//队长
int  LenQueue(SqQueue *s)
{
	return (s->rear - s->front + MAXSIZE) % MAXSIZE;
}
//主函数
int main()
{
	SqQueue *sq=new SqQueue;//创建一个队列
	int i,j,length;
	ElemType elem;
	Statu end;
	end = InitQueue(sq);//初始化
	for (i = 0; i < MAXSIZE - 1;i++)//入队
	{
		cin >> elem;
		end = PutQueue(sq, elem);
	}
	length = LenQueue(sq);
	cout << "newlength=" << length<<endl;
	for (j = 0; j < MAXSIZE - 1; j++)//出队
	{
		end = OutQueue(sq,&elem);
		cout << elem << endl;
	}
	length = LenQueue(sq);
	cout << "lastlength=" << length;
	cin >> end;
	return 0;
}