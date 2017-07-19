//ѭ�����У��Զ���˳��洢�ṹ�ĸĽ�,ע���ж϶���������
//ͷ�ļ�
#include"Queue.h"
#define OK 0//�ɹ�
#define ERROR 1//ʧ��
#define MAXSIZE 11//�������ֵ10,�ճ�һ��
typedef int Statu;//��������״̬
typedef int ElemType;//��������
//�ṹ
typedef struct Queue
{
	int front;
	int rear;
	ElemType data[MAXSIZE];
}SqQueue;
//��ʼ��
Statu InitQueue(SqQueue *s)
{
	s->front = 0;
	s->rear = 0;
	return OK;
}
//���
Statu PutQueue(SqQueue *s,ElemType e)
{
	if ((s->rear +1)%MAXSIZE==s->front)//����
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
//����
Statu OutQueue(SqQueue *s,ElemType *e)
{
	if (s->rear ==s->front)
	{
		return ERROR;
	}
	else
	{
		*e = s->data[s->front];//û��ɾ������ֵ�Ḳ�ǵ�
		s->front = (s->front+1)%MAXSIZE;
		return OK;
	}
}
//�ӳ�
int  LenQueue(SqQueue *s)
{
	return (s->rear - s->front + MAXSIZE) % MAXSIZE;
}
//������
int main()
{
	SqQueue *sq=new SqQueue;//����һ������
	int i,j,length;
	ElemType elem;
	Statu end;
	end = InitQueue(sq);//��ʼ��
	for (i = 0; i < MAXSIZE - 1;i++)//���
	{
		cin >> elem;
		end = PutQueue(sq, elem);
	}
	length = LenQueue(sq);
	cout << "newlength=" << length<<endl;
	for (j = 0; j < MAXSIZE - 1; j++)//����
	{
		end = OutQueue(sq,&elem);
		cout << elem << endl;
	}
	length = LenQueue(sq);
	cout << "lastlength=" << length;
	cin >> end;
	return 0;
}