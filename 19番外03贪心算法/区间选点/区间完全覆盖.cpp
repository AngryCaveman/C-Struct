/*给定一个长度为m的区间，再给出n条线段的起点和终点（注意这里是闭区间），
求最少使用多少条线段可以将整个区间完全覆盖
*/
#include<iostream>
using namespace std;
#define Max 10
int main(){
	int i,j,temp,k;//循环用
	int n;
	int m;
	int arry[Max][2];
	int sum;//总数
	int start,end;
	cout<<"总区间长度：";cin>>m;
	cout<<"线段条数：";cin>>n;
	for(i=0;i<n;i++){
		cin>>arry[i][0]>>arry[i][1];
	}
	//冒泡排序：升序
	//左端点从小到大排
	for (i = 0; i < n; i++){  
        for (j = i + 1; j < n; j++){  
            if (arry[i][0]> arry[j][0]){ 
				temp=arry[i][0];
				arry[i][0]=arry[j][0];
				arry[j][0]=temp;
				//整组交换
				 temp=arry[i][1];
				arry[i][1]=arry[j][1];
				arry[j][1]=temp;
            }  
        }  
    }  
	//主要的逻辑计算
	//第一个必选
	sum=1;//至少有一个
	i=0;
	start=arry[0][0];
	end=arry[0][1];
	cout<<"("<<start<<","<<end<<")"<<endl;
	//
	int endM=end;//处理多区间相交时，取最大区间的问题
	while(endM<8){
		for(j=i+1;j<n;j++){
			if(arry[j][1]>end && arry[j][0]<=end && arry[j][1]>=endM){//相交
				endM=arry[j][1];
				i=j;
			}
			else{
				break;
			}
		}
		sum++;
		end=arry[i][1];//更新end的数值
		cout<<"("<<arry[i][0]<<","<<arry[i][1]<<")"<<endl;
	}
	cout<<"组数："<<sum;
	return 0;
}