/*�ó�����Vs2013�б�д���
*/

#include"002.h"
/*������ʽ�ṹ*/
#define Ok 1//�����ɹ�
#define Error 0//����ʧ��
#define MaxSize 100//ջ��
int CurCount=0;//��ǰ�ڵ���
int head;
typedef int Statu;//�������״̬�ظ�
typedef int ElemType;//typedef ����һ��int����
typedef struct Node
{
	ElemType item;//����
	int age;//����
	Node *next;//��һ��
};
typedef  Node *LinkList;
//�������
void ListPrint(LinkList l)
{
	cout << "������" << endl;
	Node *n = l->next;
	while (n != NULL)
	{			
		cout << n->item<< " ";
		cout << n->age << "|";
		l = n->next;
		n = l;
	}
}
//��ʼ��50������
Statu ListInit(LinkList l)
{
	int i;
	int len = 50;
	for (i = 0; i < len; i++)
	{
		++CurCount;
		Node *n = new Node;
		n->item=i+1;
		n->age = rand()%11;//�������һ��1-10��������ֳ䵱����
		l->next = n;
		l = n;
	}
	l->next = NULL;
	return Ok;
}

//�����,iΪ����λ�ã�eΪ����Ԫ��
Statu  ListInsert(LinkList l, int i,ElemType n)
{
	LinkList s;
	int j = 1;
	s = l;
	//����λ��
	while (s != NULL && j<i)//�õ�i-1�Ľ��
	{
		s = s->next;
		++j;
	}
	//�������
	LinkList num = (LinkList)malloc(sizeof(Node));
	num->item = n;
	num->age = 0;//Ĭ����Ϊ0
	//����λ��
	num->next = s->next;
	s->next = num;
	return Ok;
}
//ɾ����Ԫ��
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
	free(q);//�ͷ��ڴ�
	return Ok;
}
//��λ��ɾ��
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
	free(q);//�ͷ��ڴ�
	return Ok;
}
//������
int main()
{
	int end;//����ִ��״̬����
	int count=0;//����210��
	int position;//����λ��
	bool remflag,insflag;//�Ƿ����ɾ��
	int numCount;//�����,�����������Χ
	LinkList p = (LinkList)malloc(sizeof(Node));//����ͷָ��
	LinkList ls;//����
	end = ListInit(p);//��ʼ��50��
	numCount = CurCount;
	head = p->next->item;
	//����ģ��200��
	while (count <= 210)
	{
		count++;
		insflag = true;
		remflag = true;
		ls = p->next;
		cout << count << "�Σ�"<<endl;
		Sleep(1000);//����1s
		//ѭ���������Ĳ���
		while (ls->next!=NULL)
		{
			//��̭
			if (numCount >= 100 && (remflag))
			{
				end=PositionListRemove(p, 1);
				remflag = false;
				numCount--;
			}
			else if ((ls->next->age>10) && (remflag))
			{
				cout << "ɾ����Item="<<ls->next->item<<"Age="<<ls->next->age<<endl;
				end = ListRemove(ls,ls->item);
				remflag = false;
				numCount--;
			}
			if (insflag)
			{
				//����
				position = (rand() % numCount) + 1;/*��������[1,numCount]�ϵ������*/;
				numCount++;
				CurCount++;
				cout << "������Item=" << CurCount <<"λ�ã�"<<position<< endl;
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