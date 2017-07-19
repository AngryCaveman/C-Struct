//������ʽ�ṹ
//ͷ�ļ�
#include"QueuePtr.h"
#define OK 0//�ɹ�
#define ERROR 1//ʧ��
typedef int Statu;//��������״̬
typedef int ElemType;//��������
//���ṹ��
typedef struct QueueNode
{
	ElemType data;
	QueueNode *next;
}QNode,*QueuePtr;
//����ṹ��
typedef struct
{
	QueuePtr front, rear;
	int length;
}LinkQueue;
//��ʼ��
Statu InitQueue(LinkQueue *l)
{
	QueuePtr qn = (QueuePtr)malloc(sizeof(QueueNode));
	l->front = qn;//��һ�����ճ���
	l->rear = l->front;//����Ϊ��
	l->length = 0;
	return OK;
}
//���
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
//����
Statu OutQueue(LinkQueue *l,ElemType *e)
{
	if (l->front == l->rear)//�ӿ�
		return ERROR;
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
		*e = qn->data;
		free(qn);
		l->length -= 1;
	}
	return OK;
}
//������
int main()
{
	int i,  end;
	ElemType data;
	LinkQueue *lq = new LinkQueue;
	end = InitQueue(lq);
	//10������
	for (i = 0; i < 10;i++)
	{
		cin >> data;
		end = PutQueue(lq,data);
	}
	cout << "NewLength=" << lq->length<<endl;
	//����
	while (end!=ERROR)
	{
		end = OutQueue(lq, &data);
		cout << data<<endl;
	}
	cout << "LastLength=" << lq->length << endl;
	cin >> end;
	return 0;
}