#include"Tree.h"
#define Maxsize 20//树最多结点数
#define Ok 1
#define Error 0
typedef string Elemtype;
typedef int Statu;

//双亲表示及其显示
//树节点结构
typedef struct PTreeNode
{
	int pos;//自己的位置
	Elemtype data;
	int parent;//还可扩展长子域，兄弟域，同理，此处不做说明
}PTreeNode;
//树结构
typedef struct PTree
{
	//list<PTreeNode> ptn;
	PTreeNode ptn[Maxsize];
	int root, count;//根的位置，结点数目
}PTree;
//构建一个队列给显示用的
typedef struct QueueNode
{
	PTreeNode ptn;
	int layer;//层数
	QueueNode *next;
}QNode, *QueuePtr;
//链表结构体
typedef struct
{
	QueuePtr front, rear;
}LinkQueue;
//初始化
void InitQueue(LinkQueue *l)
{
	QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
	l->front = qn;//第一个结点空出来
	l->rear = l->front;//队列为空
}
//入队
void PutQueue(LinkQueue *l, PTreeNode node,int ly)
{
	QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
	qn->layer = ly;
	//qn->ptn = node;//疑问
	qn->ptn.parent = node.parent;
	qn->ptn.pos = node.pos;
	qn->next = NULL;
	l->rear->next = qn;
	l->rear = qn;
}
//出队01:返回自身位置，和双亲位置
void OutQueue(LinkQueue *l, int *pe, int *ps)
{
	if (l->front == l->rear)//队空
		return;
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
		*pe = qn->ptn.parent;
		*ps = qn->ptn.pos;
		free(qn);
	}
}
//出队返回层数
void OutQueuely(LinkQueue *l, int *ly,int *p)
{
	if (l->front == l->rear)//队空
		return;
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
		*ly = qn->layer;
		*p = qn->ptn.pos;
		free(qn);
	}
}

//01双亲表示法
Statu Parent_Tree(PTree *p)
{
	int i=0;
	cout << "请输入结点的个数:"; cin >> p->count;
	cout << "注意没有双亲，双亲位置填-1!" << endl;
	for (i = 0; i < p->count;i++)
	{
		cout << "第" << i+1<<"个结点："<< endl;
		PTreeNode node;
		cout << "数据："; cin >> node.data;
		cout << "双亲："; cin >> node.parent;
		node.pos = i;
		p->ptn[i] = node;
	}
	return Ok;
}
void IndicateParent_Tree(PTree p)//识别双亲表示法构建树图
{
	int i,j1,j2=1; int layer=1,temp,num,p1,p2,p3;
	int numpos[Maxsize];
	LinkQueue *lq = new LinkQueue; 
	LinkQueue *changelq = new LinkQueue;//这条队列修改temp的值
	InitQueue(lq);//初始化队列
	InitQueue(changelq);//初始化队列
	//查找根结点,遍历数组
	//for (list<PTreeNode>::const_iterator iter = p.ptn.begin(); iter != p.ptn.end();iter++)//知识点
	//{if (iter->parent == -1)//iter是node 的指针
    //      {}}
	for (i = 0; i < p.count; i++)
	{
		if (p.ptn[i].parent==-1)
		{
			p.root = i;//记录根位置
			//入队
			PutQueue(lq,p.ptn[i],layer);
			PutQueue(changelq, p.ptn[i], layer);
			layer++;//层数加1
			break;
		}
	}
	//入队其他元素，分层
	OutQueue(changelq,&p1,&temp); 
	num = p.count-1;
	while(num!=0)
	{
		p2 = p1;
		for (i = 0; i < p.count; i++)
		{
			if (p.ptn[i].parent==temp)
			{
				PutQueue(lq, p.ptn[i], layer);
				PutQueue(changelq, p.ptn[i], layer);
				num--;
			}
		}
		OutQueue(changelq,&p1, &temp);
		if (p2!=p1)
			layer++;
		
	}
	//输出
	int numof = 2 * (lq->rear->layer+1);
	while (lq->front != lq->rear)
	{
		OutQueuely(lq, &j1,&p3);
		if (j1 == j2 + 1)
		{
			cout << endl;
			numof = numof / 2;
			//cout <<setw(p.count * 3 - j2)<<'|' << endl;
		}
		cout<<setw(numof)<<"_("<<p.ptn[p3].data<<","<<p.ptn[p.ptn[p3].parent].data<<")_"  ;
		j2 = j1;
	}
}
//主函数
int main()
{
	Statu end;
	PTree *pt=new PTree;
	end = Parent_Tree(pt);
	IndicateParent_Tree(*pt);
	cin >> end;
	return 0;
}