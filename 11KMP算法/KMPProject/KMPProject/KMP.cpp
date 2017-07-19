#include"KMP.h"
#define Maxsize 20
//创建next数组
void  Get_Next(char Num[],int *next,int pNumLength)
{
	int i=1, j=0;
	next[0] =pNumLength;//第一个用于匹配串记录数组长度
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
//匹配
int Index_KMP(char Num[], int *next, char pNum[])
{
	int i = 0, j = 1;//j会用到next数组中而next[0]是长度
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
		return i - next[0];//匹配成功，返回位置索引
	}
	else
		return 0;//匹配不成功
}
//主函数
int main()
{
	int i=1,end;
	string Str;//被匹配串
	string pStr;//匹配串
	char StrNum[Maxsize];
	char pStrNum[Maxsize];
	int Next[Maxsize];//next数组
	cout << "请输入被匹配字符串：" << endl; cin >> Str;
	cout << "请输入匹配串：" << endl; cin >> pStr;
	strcpy_s(StrNum, Str.c_str());//得到字符数组
	strcpy_s(pStrNum, pStr.c_str());//得到字符数组
	//得到next数组
    Get_Next(pStrNum,Next,strlen(pStrNum));
	cout << "Next数组："; 
	while (Next[i]>=0)
	{	
		cout << Next[i]<< " ";
		i++;
	}
	//匹配
	end = Index_KMP(StrNum,Next,pStrNum);
	cout << "索引：" << end<<endl;
	if (end!=0)
		cout << Str.substr(0, end) << " " << Str.substr(end, Next[0]) << " " << Str.substr(end + Next[0]);
	cin >> end;
	return 0;
}