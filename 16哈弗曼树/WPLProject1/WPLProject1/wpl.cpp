#include"wpl.h"
#define Max 100
typedef char Elem;
typedef int  Val;//��¼Ȩֵ
//�������������������
typedef struct HNode
{
	Elem data;//��ֵ
	Val v_data;//Ȩֵ
	HNode *LChild;//����
	HNode *RChild;//�ҽ��
}HNode,*Hlink;

//�������ֵ����Ȩֵ��С��������
void Sort(HNode *h,int num)
{
	int i,j;
	for (i = 1; i <=num;i++)//ð��
	{
		for (j = num - 1; j >=i; j--)
		{
			if (h[j].v_data > h[j + 1].v_data)
			{
				h[0] = h[j];
				h[j] = h[j + 1];
				h[j + 1] = h[0];
			}
		}
	}
}
//������������
void Creat(Hlink *h,HNode *h_arry,int num)
{
	int i = 0;
	//������
	for (i = 2; i <= num; i++)
	{
		HNode *tempNode = new HNode;
		tempNode->data = ' ';
		tempNode->LChild = NULL;
		tempNode->RChild = NULL;
		tempNode->v_data = h_arry[i-1].v_data + h_arry[i].v_data;
		if (h_arry[i - 1].v_data > h_arry[i].v_data)
		{
			tempNode->LChild = &h_arry[i];
			tempNode->RChild = &h_arry[i - 1];
		}
		else
		{
			tempNode->LChild = &h_arry[i-1];
			tempNode->RChild = &h_arry[i];
		}
		h_arry[i] = *tempNode;
		*h = tempNode;
	}
}
int main()
{
	int count,i;
	HNode hNum[Max];
	Hlink *hl=new Hlink;
	cout << "��ĸ������"; cin >> count;
	//����,0λ���ڽ���
	for (i = 1; i <=count;i++)
	{
		HNode n ;
		cout << "��ĸ��"; cin >> n.data;
		cout << "Ȩֵ��"; cin >> n.v_data;
		hNum[i] = n;
	}
	//����
	Sort(hNum,count);
	//������������
	Creat(hl,hNum,count);
	//
	return 0;
}