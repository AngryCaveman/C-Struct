//��Ŀ������ֻ��һ�Ҵ����ܳ�2�ˣ����������ٶ�Ϊ2���н���һ�˵��ٶ�
//��ȥ����һ���˰Ѵ����������ʰ�n�����˵��԰���������Ҫ��á�
#include<iostream> 
using namespace std;
#define Max 20
//ð������
void Sort(int *p,int n){
	int i,j,temp;
	for (i = 0; i < n; i++){  
        for (j = i + 1; j < n; j++){  
            if (*(p+i)> *(p+j)){  
                temp=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=temp;
            }  
        }  
    }  
}

int min(int a ,int b){
	if(a>b)
		return b;
	else
		return a;
}
int main(){
	int n;//n����
	int i,j;//ѭ����
	int Arry[Max];//�洢ÿ�����ٶ�
	int sum=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>Arry[i];
	}
	//����
	Sort(Arry,n);
	//ѡ��ÿ�����ͺ�ʱ���һ��˿�,Ҳ���������λ
	//������������ܰѺ�ʱ������ߣ�ͬʱȷ���˴���������ʱ����̡�
	//1,Arry[0]+2*Arry[1]+Arry[n-1];2,2*Arry[0]+Arry[n-2]+Arry[n-1]
	  while(n>3){  
            sum+=min(Arry[0]+2*Arry[1]+Arry[n-1],2*Arry[0]+Arry[n-2]+Arry[n-1]);  
            n-=2;  
      }  
      if(n==3) sum+=Arry[0]+Arry[1]+Arry[2];  
      else if(n==2) sum+=Arry[1];  
      else sum+=Arry[0];  
	  cout<<sum;
	return 0;
}