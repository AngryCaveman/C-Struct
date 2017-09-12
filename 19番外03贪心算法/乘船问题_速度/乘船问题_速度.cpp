//题目大意是只有一艘船，能乘2人，船的运行速度为2人中较慢一人的速度
//过去后还需一个人把船划回来，问把n个人运到对岸，最少需要多久。
#include<iostream> 
using namespace std;
#define Max 20
//冒泡排序
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
	int n;//n个人
	int i,j;//循环用
	int Arry[Max];//存储每个人速度
	int sum=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>Arry[i];
	}
	//排序
	Sort(Arry,n);
	//选择，每次运送耗时最长的一组乘客,也就是最后两位
	//有两种情况既能把耗时最长的送走，同时确保此次运送整体时间最短。
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