//使用归并排序一下数字：8，7，4，2，2，1，19，23，5，3
#include<iostream>
using namespace std;
#define Max 10

//归并排序
void MergeSort(int first,int last,int mid,int a[],int temp[]){
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void SplitSort(int first,int last,int a[],int temp[]){
	if (last>first){
		int mid = (first + last) / 2;
		SplitSort(first,mid,a,temp);
		SplitSort(mid+1,last,a,temp);
		MergeSort(first,last,mid,a,temp);
	}
}
bool Merge(int a[],int n){
	int *temp = new int[n];
	if (temp == NULL)
		return false;
	SplitSort(0,n-1,a,temp);
	return true;
}
int main(){
	int array[Max] = { 8, 7, 4, 2, 2, 1, 19, 23, 5, 3 };
	Merge(array,Max);
	//打印
	int i;
	for (i = 0; i < Max;i++){
		cout << array[i] << " ";
	}
	return 0;
}