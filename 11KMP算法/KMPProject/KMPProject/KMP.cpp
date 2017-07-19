#include"KMP.h"
#define Maxsize 20
//����next����
void  Get_Next(char Num[],int *next,int pNumLength)
{
	int i=1, j=0;
	next[0] =pNumLength;//��һ������ƥ�䴮��¼���鳤��
	next[1] = 0;
	while (i<next[0])
	{
		if (j==0||Num[i-1]==Num[j-1])
		{
			++j;
			++i;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
//ƥ��
int Index_KMP(char Num[], int *next, char pNum[])
{
	int i = 0, j = 1;//j���õ�next�����ж�next[0]�ǳ���
	while (i < strlen(Num) && j-1 < next[0])
	{
		if (j == 0 || Num[i] == pNum[j-1])
		{
			++j;
			++i;
		}
		else
			j = next[j];

	}
	if (j > next[0])
	{
		return i - next[0];//ƥ��ɹ�������λ������
	}
	else
		return 0;//ƥ�䲻�ɹ�
}
//������
int main()
{
	int i=1,end;
	string Str;//��ƥ�䴮
	string pStr;//ƥ�䴮
	char StrNum[Maxsize];
	char pStrNum[Maxsize];
	int Next[Maxsize];//next����
	cout << "�����뱻ƥ���ַ�����" << endl; cin >> Str;
	cout << "������ƥ�䴮��" << endl; cin >> pStr;
	strcpy_s(StrNum, Str.c_str());//�õ��ַ�����
	strcpy_s(pStrNum, pStr.c_str());//�õ��ַ�����
	//�õ�next����
    Get_Next(pStrNum,Next,strlen(pStrNum));
	cout << "Next���飺"; 
	while (Next[i]>=0)
	{	
		cout << Next[i]<< " ";
		i++;
	}
	//ƥ��
	end = Index_KMP(StrNum,Next,pStrNum);
	cout << "������" << end<<endl;
	if (end!=0)
		cout << Str.substr(0, end) << " " << Str.substr(end, Next[0]) << " " << Str.substr(end + Next[0]);
	cin >> end;
	return 0;
}