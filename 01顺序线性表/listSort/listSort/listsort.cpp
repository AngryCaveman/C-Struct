/*���Ա�˳��ṹ*/
#include"listsort.h"
#define Max 10 //˳�����󳤶�
#define Ok 1;//�����ɹ�
#define Error 0;//����ʧ��
typedef int Statu;//˳������״̬�ظ�
typedef int ElemType;//typedef ����һ��int����
typedef struct
{
	ElemType data[Max];//����
	int length;//����
}SqList;
//����˳���
void ListPrint(SqList l)
{
	int i;
	for (i = 0; i<l.length; i++)
	{
		cout << l.data[i]<< endl;
	}
	cout << "���ȣ�" << l.length << endl;
}
//��ʼ��˳���
Statu ListInit(SqList *l)
{
	if ((l->length <= Max)&&(l->length>0))
	{

		int i = 0;
		for (i = 0; i < l->length; i++)
		{
			cout << "�������"<<(i+1)<<"��Ԫ��:";
			cin >> l->data[i];
		}
		return Ok;
	}
	else
	{
		cout << "���볤�Ȳ��ܴ���10" << endl;
		return Error;
	}
}
//����˳���,iΪ����λ�ã�eΪ����Ԫ��
Statu  ListInsert(SqList *l,int i,ElemType e)
{
	if (l->length == Max)//˳�������
		return Error;
	if ((i<1) || (i>l->length + 1))
		return Error;
	if (i <= l->length)
	{
		int j = 0;
		ElemType temp;
		for (j = l->length-1; j >= i - 1;j--)
		{
			l->data[j + 1] = l->data[j];
		}
		l->data[i - 1] = e;
		l->length++;
	}
}
//��ȡ˳���Ԫ��
Statu ListGetEle(SqList *l)
{
	int num;
	cout << "�������ȡԪ����ţ�" << endl;
	cin >> num;
	if ((num > 0) && (num <= l->length))
	{
		cout << l->data[num - 1]<<endl;
		return Ok;
	}
	else
	{
		cout << "���볤�Ȳ��Ϸ���" << endl;
		return Error;
	}
}
//ɾ��˳���Ԫ��
Statu ListRemove(SqList *l,int i)
{
	if (l->length == 0)//˳���Ϊ��
		return Error;
	if ((i<1) || (i>l->length + 1))
		return Error;
	if (i < l->length)
	{
		int j;
		for (j = i ; j < l->length;j++)
		{
			l->data[j - 1] = l->data[j];
		}
		l->length--;
	}
}
//������
int main()
{
	int end, position;
	ElemType vlaue;
	SqList *p = new SqList;
	cout << "������˳����ȣ�";
	cin >> p->length;
	end =ListInit(p);
	end = ListGetEle(p);
	//����
	cout << "����λ��:"; cin >> position;
	cout << "����ֵ:"; cin >> vlaue;
	ListInsert(p, position, vlaue);
	ListPrint(*p);
	//ɾ��
	cout << "ɾ��λ��:"; cin >> position;
	ListRemove(p, position);
	ListPrint(*p);
	cin >> end;
	return 0;
}