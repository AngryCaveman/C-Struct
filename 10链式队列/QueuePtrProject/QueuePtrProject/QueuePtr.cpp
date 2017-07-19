//队列链式结构
//头文件
#include"QueuePtr.h"
#define OK 0//成功
#define ERROR 1//失败
typedef int Statu;//函数操作状态
typedef int ElemType;//数据类型
//结点结构体
typedef struct QueueNode
{
	ElemType data;
	QueueNode *next;
}QNode,*QueuePtr;
//链表结构体
typedef struct
{
	QueuePtr front, rear;
	int length;
}LinkQueue;
//初始化
Statu InitQueue(LinkQueue *l)
{
	QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
	l->front = qn;//第一个结点空出来
	l->rear = l->front;//队列为空
	l->length = 0;
	return OK;
}
//入队
Statu PutQueue(LinkQueue *l, ElemType e)
{
	QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
	qn->data = e;
	qn->next = NULL;
	l->rear->next = qn;
	l->rear = qn;
	l->length += 1;
	return OK;
}
//出队
Statu OutQueue(LinkQueue *l,ElemType *e)
{
	if (l->front == l->rear)//队空
		return ERROR;
	else
	{
		QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
		qn = l->front->next;
		if (qn == l->rear)//最后一个
		{
			l->rear = l->front;
			qn->next = NULL;
		}
		else
			l->front->next = qn->next;
		*e = qn->data;
		free(qn);
		l->length -= 1;
	}
	return OK;
}
//主函数
int main()
{
	int i,  end;
	ElemType data;
	LinkQueue *lq = new LinkQueue;
	end = InitQueue(lq);
	//10个数据
	for (i = 0; i < 10;i++)
	{
		cin >> data;
		end = PutQueue(lq,data);
	}
	cout << "NewLength=" << lq->length<<endl;
	//出队
	while (end!=ERROR)
	{
		end = OutQueue(lq, &data);
		cout << data<<endl;
	}
	cout << "LastLength=" << lq->length << endl;
	cin >> end;
	return 0;
}