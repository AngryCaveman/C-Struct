//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	char Num1[20],Num2[20];
//	int Num[20];
//	string numStr1, numStr2;
//	int n, sum=0, i,j;
//	cin >> n;
//	cin >> numStr1;
//	cin >> numStr2;
//	strcpy_s(Num1, numStr1.c_str());
//	strcpy_s(Num2, numStr2.c_str());
//	for (i = 0; i < n;i++)
//	{
//		if (Num1[i] == Num2[i])
//		{
//			Num[i] = 0;
//		}
//		else
//			Num[i] = 1;
//	}
//	for (j = 0; j < n;j++)
//	{
//		sum += Num[j] * (int)pow(2,n-1-j);
//	}
//	cout << sum;
//	return 0;
//}