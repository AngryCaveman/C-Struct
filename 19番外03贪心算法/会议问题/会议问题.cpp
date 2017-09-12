/*
有n个需要在同一天使用同一个教室的活动a1,a2,…,an，教室同一时刻只能由一个活动使用。
每个活动ai都有一个开始时间si和结束时间fi 。一旦被选择后，活动ai就占据半开时间区间[si,fi)。
如果[si,fi]和[sj,fj]互不重叠，ai和aj两个活动就可以被安排在这一天。
该问题就是要安排这些活动使得尽量多的活动能不冲突的举行。
*/
#include<iostream>
using namespace std;
#define Max 10//最多活动个数  
int main(){
	int i,j,temp;//循环用
	int n;//活动个数
	int arry[Max][2];
	int sum;//活动个数
	int s=0,e=24;//一天24个小时【0，24】
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arry[i][0]>>arry[i][1];
	}
	//冒泡排序:升序
	//按结束时间排序
	for (i = 0; i < n; i++){  
        for (j = i + 1; j < n; j++){  
            if (arry[i][1]> arry[j][1]){  
                temp=arry[i][1];
				arry[i][1]=arry[j][1];
				arry[j][1]=temp;

				//整组交换
				temp=arry[i][0];
				arry[i][0]=arry[j][0];
				arry[j][0]=temp;
            }  
        }  
    }  
	//计算
	temp=arry[0][1];
	cout<<"["<<arry[0][0]<<","<<arry[0][1]<<")"<<endl;
	sum=1;
	for(i=1;i<n;i++){
		if(temp<=arry[i][0]){
			sum++;
			temp=arry[i][1];
			cout<<"["<<arry[i][0]<<","<<arry[i][1]<<")"<<endl;
		}
		//应该判断一下合法性，但是怕影响思路，还是不要了
		//if(arry[i][1]>24 || arry[i][0]>24)
			//break;
	}
	cout<<sum;
	return 0;
}
//测试用例：5  ；【2，10）【5，6）【11，13）【13，20）【19，24）
//结果:3