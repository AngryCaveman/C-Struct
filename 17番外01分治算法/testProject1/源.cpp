#include<iostream>  
using namespace std;
int main()
{
	void hanoi(int n, char one, char two, char three);
	int m;
	cout << "ÊäÈëÅÌ×ÓÊý:";
	cin >> m;;
	hanoi(m, 'A', 'B', 'C');
}


void hanoi(int n, char one, char two, char three)
{
	void move(char x, char y);
	if (n == 1)
	{
		move(one, three);
	}
	else
	{
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}


void move(char x, char y)
{
	cout << x << "-->" << y << endl;
}

