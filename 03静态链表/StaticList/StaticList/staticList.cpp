#include "staticList.h"
#define Max 10
#define ok 1
#define error 0
typedef int Statu;
typedef int ElemType;
//���徲̬������ṹ��
typedef struct StaticNode
{
	ElemType data;//����
	int cur;//�α�
}StaticLinkList[Max];//��Ϊ��typedef���Դ˴����Ƕ���
void PrintList(StaticLinkList space)
{
	int i = 1,j=0;
	while (space[j].cur!=0)
	{
		j = i;
		cout << space[i].data << endl;
		i = space[i].cur;
	}
}
//��ʼ������
Statu ListInit(StaticLinkList space,int len)
{
	int i;
	if ((len > Max) || (len < 0))
		return error;
	else
	{
		space[0].cur = len + 1;
		
		for (i = 1; i <=len; i++)
		{
			cin >> space[i].data;
			space[i].cur = i + 1;
			if (i == len)
				space[len].cur = 0;//�յ�
		}
		//�Ѻ����cur���óɹ̶���
		for (i = len + 1; i <= Max; i++)
		{
			space[i].cur = i + 1;
			if (i == Max)
			{
				space[Max].cur = 1;//��¼��㣬�����0�������ǿ�
			}
		}
		return ok;
	}
}
//��ȡ�����±�
int Malloc_SLL(StaticLinkList space)
{
	int i=space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
	}
	return i;
}
//ɾ��
Statu ListRemove(StaticLinkList space, int j)
{
	//����Ҫɾ����λ��
	int i = 1;
	int start = space[Max].cur;
	int nend;
	while (i != j - 1)
	{
		i++;
		start = space[start].cur;
	}
	//ɾ��
	nend = space[start].cur;
	space[start].cur = space[nend].cur;
	//����
	space[nend].cur = space[0].cur;
	space[0].cur = nend;
	return ok;
}
//����
Statu ListInsert(StaticLinkList space,int j,ElemType e)
{
	int i =1;
	int start = space[Max].cur;
	int nend;
	while (i!=j-1)
	{
		i++;
		start = space[start].cur;
	}
	nend = space[space[0].cur].cur;
	space[space[0].cur].data = e;
	space[space[0].cur].cur = space[start].cur;
	space[start].cur = space[0].cur;
	space[0].cur = nend;
	return ok;
}
//������
int main()
{
	Statu end;
	int position, vlaue, length;
	StaticLinkList s ={};
	//��ʼ��
	cout << "�����볤�ȣ�"; cin >> length;
	end = ListInit(s,length);
	PrintList(s);
	//����
	cout << "����λ��:"; cin >> position;
	cout << "ֵ:"; cin >> vlaue;
	end=ListInsert(s, position, vlaue);
	PrintList(s);
	//ɾ��
	cout << "ɾ��λ��:"; cin >> position;
	end = ListRemove(s, position);
	PrintList(s);

	cin >> end;
	return 0;
}
