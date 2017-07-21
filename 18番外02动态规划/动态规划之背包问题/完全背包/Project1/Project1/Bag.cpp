#include"Bag.h"
int max(int a,int b)
{
	int temb;
	if (a > b)
		temb = a;
	else
		temb = b;
	return temb;
}
int main()
{
	int w[300], c[300], f[300];
	int V, n;

	cin>>V>>n;
	for (int i = 1; i <= n; i++)
	{cin>>w[i]>>c[i]; }
	for (int i = 1; i <= n; i++)
	for (int j = w[i]; j <= V; j++)f[j] = max(f[j], f[j - w[i]] + c[i]);
	cout<<f[V-1];
	return 0;

	//½áÊø
	int end;
	cin >> end;
	return 0;
}