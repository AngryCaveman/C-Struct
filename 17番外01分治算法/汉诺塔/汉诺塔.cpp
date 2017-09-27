/*汉诺塔问题是一个经典的问题。汉诺塔（Hanoi Tower），又称河内塔，
源于印度一个古老传说。大梵天创造世界的时候做了三根金刚石柱子，
在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。
大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。
并且规定，任何时候，在小圆盘上都不能放大圆盘，且在三根柱子之间一次只能移动一个圆盘。问应该如何操作？*/
#include<iostream>
using namespace std;
void MoveOutput(char c1, char c2){
	cout << c1 << "-->" << c2 << endl;
}
void Hanoi(int n,char a,char b ,char c){
	if (n==1){
		MoveOutput(a, c);
		return;
	}
	Hanoi(n - 1, a,c,b);//将1到n-1片盘移动由A移动到B
	MoveOutput(a,c);//将最底层盘由A移动到C
	Hanoi(n - 1, b,a,c);//将1到n-1片盘移动由B移动到C
}

int main(){
	int num;
	cout << "输入盘数："; cin >> num;
	Hanoi(num, 'A', 'B', 'C');
	return 0;
}