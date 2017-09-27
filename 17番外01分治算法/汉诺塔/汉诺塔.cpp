/*��ŵ��������һ����������⡣��ŵ����Hanoi Tower�����ֳƺ�������
Դ��ӡ��һ�����ϴ�˵�������촴�������ʱ�������������ʯ���ӣ�
��һ�������ϴ������ϰ��մ�С˳������64Ƭ�ƽ�Բ�̡�
���������������Ű�Բ�̴����濪ʼ����С˳�����°ڷ�����һ�������ϡ�
���ҹ涨���κ�ʱ����СԲ���϶����ܷŴ�Բ�̣�������������֮��һ��ֻ���ƶ�һ��Բ�̡���Ӧ����β�����*/
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
	Hanoi(n - 1, a,c,b);//��1��n-1Ƭ���ƶ���A�ƶ���B
	MoveOutput(a,c);//����ײ�����A�ƶ���C
	Hanoi(n - 1, b,a,c);//��1��n-1Ƭ���ƶ���B�ƶ���C
}

int main(){
	int num;
	cout << "����������"; cin >> num;
	Hanoi(num, 'A', 'B', 'C');
	return 0;
}