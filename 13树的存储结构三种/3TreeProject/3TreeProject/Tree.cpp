#include"Tree.h"
#define Maxsize 20//���������
#define Ok 1
#define Error 0
typedef string Elemtype;
typedef int Statu;

//˫�ױ�ʾ������ʾ
//���ڵ�ṹ
typedef struct PTreeNode
{
	int pos;//�Լ���λ��
	Elemtype data;
	int parent;//������չ�������ֵ���ͬ���˴�����˵��
}PTreeNode;
//���ṹ
typedef struct PTree
{
	//list<PTreeNode> ptn;
	PTreeNode ptn[Maxsize];
	int root, count;//����λ�ã������Ŀ
}PTree;
//����һ�����и���ʾ�õ�
typedef struct QueueNode
{
	PTreeNode ptn;
	int layer;//����
	QueueNode *next;
}QNode, *QueuePtr;
//����ṹ��
typedef struct
{
	QueuePtr front, rear;
}LinkQueue;
//��ʼ��
void InitQueue(LinkQueue *l)
{
	QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
	l->front = qn;//��һ�����ճ���
	l->rear = l->front;//����Ϊ��
}
//���
void PutQueue(LinkQueue *l, PTreeNode node,int ly)
{
	QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
	qn->layer = ly;
	//qn->ptn = node;//����
	qn->ptn.parent = node.parent;
	qn->ptn.pos = node.pos;
	qn->next = NULL;
	l->rear->next = qn;
	l->rear = qn;
}
//����01:��������λ�ã���˫��λ��
void OutQueue(LinkQueue *l, int *pe, int *ps)
{
	if (l->front == l->rear)//�ӿ�
		return;
	else
	{
		QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
		qn = l->front->next;
		if (qn == l->rear)//���һ��
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
//���ӷ��ز���
void OutQueuely(LinkQueue *l, int *ly,int *p)
{
	if (l->front == l->rear)//�ӿ�
		return;
	else
	{
		QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
		qn = l->front->next;
		if (qn == l->rear)//���һ��
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

//01˫�ױ�ʾ��
Statu Parent_Tree(PTree *p)
{
	int i=0;
	cout << "��������ĸ���:"; cin >> p->count;
	cout << "ע��û��˫�ף�˫��λ����-1!" << endl;
	for (i = 0; i < p->count;i++)
	{
		cout << "��" << i+1<<"����㣺"<< endl;
		PTreeNode node;
		cout << "���ݣ�"; cin >> node.data;
		cout << "˫�ף�"; cin >> node.parent;
		node.pos = i;
		p->ptn[i] = node;
	}
	return Ok;
}
void IndicateParent_Tree(PTree p)//ʶ��˫�ױ�ʾ��������ͼ
{
	int i,j1,j2=1; int layer=1,temp,num,p1,p2,p3;
	int numpos[Maxsize];
	LinkQueue *lq = new LinkQueue; 
	LinkQueue *changelq = new LinkQueue;//���������޸�temp��ֵ
	InitQueue(lq);//��ʼ������
	InitQueue(changelq);//��ʼ������
	//���Ҹ����,��������
	//for (list<PTreeNode>::const_iterator iter = p.ptn.begin(); iter != p.ptn.end();iter++)//֪ʶ��
	//{if (iter->parent == -1)//iter��node ��ָ��
    //      {}}
	for (i = 0; i < p.count; i++)
	{
		if (p.ptn[i].parent==-1)
		{
			p.root = i;//��¼��λ��
			//���
			PutQueue(lq,p.ptn[i],layer);
			PutQueue(changelq, p.ptn[i], layer);
			layer++;//������1
			break;
		}
	}
	//�������Ԫ�أ��ֲ�
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
	//���
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
//������
int main()
{
	Statu end;
	PTree *pt=new PTree;
	end = Parent_Tree(pt);
	IndicateParent_Tree(*pt);
	cin >> end;
	return 0;
}