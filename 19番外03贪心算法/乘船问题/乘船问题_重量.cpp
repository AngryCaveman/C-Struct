//�˴�����_��������n���ˣ���i��������Ϊwi��ÿ�Ҵ��������������ΪC�������ֻ�ܳ������ˡ������ٵĴ�װ�������ˡ�
#include<iostream>
using namespace std;
#define Max 20
//ð������
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
	int C,N;//CΪÿ�Ҵ������������NΪ������
	int W[Max];//ÿ��������
	int TotalCount=0;//����������
	int i ,j;
	cin>>C>>N;
	for(i=0;i<N;i++){
		cin>>W[i];
	}
	//��С��������
	Sort(W,N);
	//ѡ��
	j=N-1;
	i=0;
	while(i<=j){
		if(W[i]+W[j]<=C && i<j)
			i++;
		TotalCount++;
		j--;
	}
	cout<<"��������"<<TotalCount;
	return 0;
}