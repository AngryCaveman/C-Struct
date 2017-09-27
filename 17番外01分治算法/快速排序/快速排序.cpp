//使用快速排序一下数字：8，7，4，2，2，1，19，23，5，3
#include<iostream>
using namespace std;
#define Max 10

int Sort(int a[], int pos, int last){
	int i, j;
	int num;//比较项
	j = last;
	i = pos;
	num = a[i];//默认取第一个为基数
	while (i < j){
		while (i < j&&a[j] >=num)
			j--;
		if (i < j){
			a[i] = a[j];
			i++;
		}
		while (i < j&&num > a[i])
			i++;
		if (i < j){
			a[j] = a[i];
			j--;
		}
	}
	a[i] = num;
	return i;
}
void QuickSort(int a[],int pos,int n){
	if (pos < n){
		int i = Sort(a, pos, n);
		QuickSort(a, pos, i - 1);
		QuickSort(a, i + 1, n);
	}
}
int main(){
	int array[Max] = { 8,7,4,2,2,1,19,23,5,3 };
	QuickSort(array,0,Max-1);
	//打印
	int i;
	for (i = 0; i < Max; i++){
		cout << array[i] << " ";
	}
	return 0;
}