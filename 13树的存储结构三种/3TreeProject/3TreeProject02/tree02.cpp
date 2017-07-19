#include"tree02.h"
typedef string Elemtype;
//孩子兄弟表示法
typedef struct Node02
{
	Elemtype data;
	Node02 *firstChild, *rightBother,*parent;
}TNode02,*Tree02;
//输入
void InPut(Tree02 t)
{
	int i,j,num,count,temp=0;
	cout << "总结点数："; cin >> count;
	TNode02 *tn = new TNode02;
	cout << "第1个结点的数据"; cin >> tn->data;
	for (i = 0; i < count; i++)
	{
		cout << tn->data << endl;
		cout << "该结点子结点个数："; cin >> num;
		TNode02 *temp = new TNode02;
		if (i == 0)//root
		{
			t->firstChild = tn;
		}
		else
		{
			if (temp == 0)
				tn = temp->firstChild;
			else
			{
				if (temp==num)
				temp = 0;
			}
		}
		/*cout << "第" << i + 1 << "个结点的数据"; cin >> tn->data;
		cout << "该结点子结点个数："; cin >> num;*/
	
		if (num != 0)
		{
			for (j = 0; j < num; j++)
			{
				TNode02 *t1 = new TNode02;	
				
				cout << "第" << j+1 << "结点的数据"; cin >> t1->data;
				t1->parent = tn;
				if (j == 0)
				{
					tn->firstChild = t1;
					temp = t1;
					temp->rightBother = NULL;
				}
				else
				{
					temp->rightBother = t1;
					temp = t1;
				}
				++temp;
			}
		}
		else
			tn->firstChild = NULL;
	}
}
int main()
{
	Tree02 tr=(Tree02)malloc(sizeof(TNode02));
	//Tree02 tr;
	InPut(tr);
	return 0;
}