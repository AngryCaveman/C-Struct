//我们有3种物品，他们的重量和价格分别是10, 5, 30,20 kg和60, 100, 120,40。
//可以选择一些物体的一部分（比如盐，米）使在总重量不超过背包总重量V的条件下总价值最大。
#include<iostream>
using namespace std;
#define N 4
#define W 44 //背包总重量
int main(){
	int V[N]={10,5,30,20};//重量
	int P[N]={60,100,120,40};//价格
	double Vp[N];//每种物品单位重量的价格
	int i,j,temp;//循环用
    int SumW=0;//记录重量
	int Vlaue=0;//记录价格
	int SumTemp=0;//临时记录总和，用于切换Vp数组
	//求单位重量价格
	for(i=0;i<N;i++){
		Vp[i]=P[i]/V[i];
	}
	//冒泡排序,按由大到小
	for (i = 0;i < N; i++){  
        for (j = i + 1; j <N; j++){  
			if (Vp[i] < Vp[j]){
				temp=Vp[i];
				Vp[i]=Vp[j];
				Vp[j]=temp;
				//把V和P对应好
				temp=V[i];
				V[i]=V[j];
				V[j]=temp;
				temp=P[i];
				P[i]=P[j];
				P[j]=temp;
			}
        }  
    } 
	//进行选择
	i=0;
	while(SumW<W){
		while(SumTemp<V[i]){
			SumTemp++;//可以一个单位一个单位的加
			if(SumW+SumTemp>=W)
				break;
		}
		SumW+=SumTemp;
		Vlaue+=SumTemp*Vp[i];
		SumTemp=0;
		i++;
	}
	cout <<Vlaue;
	return 0;
}
//输出:276=20*5+6*10+4*29;5+10+29=45
//结果：Vp={20,6,4,2},V={5,10,30,20},P={100,60,120,40}
