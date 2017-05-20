#include<iostream>
using namespace std;

int jiecheng(int num)
{
	if (num == 1)
		return 1;
	else
		return num*jiecheng(num-1);
}
int main()
{
	int n, i, right0,temp;
	float num[100], right, sum = 1, nnum, sum0 = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
		num[i] = num[i] / 100;
	}
	right0 = n*0.6;
	right = n*0.6;
	if (right0<right && right<right0 + 1)
	{
		right = right0 + 1;
	}
	for (i = 0; i < n;i++)
	{
		sum *= num[i];
	}
	nnum = jiecheng(n);
	for (i = right; i < n;i++)
	{
		temp = jiecheng(n - i)*nnum;
		sum0 += jiecheng(i) / temp;
	}
	cout << sum;
	return 0;
}