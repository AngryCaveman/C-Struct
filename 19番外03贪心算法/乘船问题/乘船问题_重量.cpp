//乘船问题_重量。有n个人，第i个人重量为wi。每艘船的最大载重量均为C，且最多只能乘两个人。用最少的船装载所有人。
#include<iostream>
using namespace std;
#define Max 20
//冒泡排序
void Sort(int *p,int n){
	int i,j,temp;
	for (i = 0; i < n; i++)  
    {  
        for (j = i + 1; j < n; j++)  
        {  
            if (*(p+i)> *(p+j))  
            {  
                temp=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=temp;
            }  
        }  
    }  
}
int main(){
	int C,N;//C为每艘船最大载重量，N为总人数
	int W[Max];//每个人重量
	int TotalCount=0;//船的总条数
	int i ,j;
	cin>>C>>N;
	for(i=0;i<N;i++){
		cin>>W[i];
	}
	//从小到达排序
	Sort(W,N);
	//选择
	j=N-1;
	i=0;
	while(i<=j){
		if(W[i]+W[j]<=C && i<j)
			i++;
		TotalCount++;
		j--;
	}
	cout<<"船条数："<<TotalCount;
	return 0;
}