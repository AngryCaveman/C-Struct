
/*
今天是Ignatius的生日。他邀请了许多朋友。现在是吃晚饭的时间了。Ignatius想知道他至少需要多少桌。
你必须注意到并不是所有的朋友都认识对方，而且所有的朋友都不想和陌生人呆在一起。
这个问题的一个重要规则是，如果我告诉你1知道2，2知道3，意思是1，2，3互相了解，所以他们可以呆在一个表中。
例如：如果我告诉你1知道2，2知道3，4知道5，那么1，2，3可以呆在一个表里，4，5必须留在另一个表中。所以伊格至少需要2台。
*/

#include<iostream>
using namespace std;
#define max 25
//数组
int Arry[1003];
int size[1003];
//find
int Find(int num){
	int root=num,temp;
	while(Arry[root]!=root)
		root=Arry[root];
	//路径压缩
	while(num!=root){
		temp=Arry[num];
		Arry[num]=root;
		num=temp;
	}
	return num;
}
//connect
bool Connect(int a,int b){
	if(Arry[a]==Arry[b])
		return true ;
	return false;
}
//union
void Union(int a ,int b){
	int aRoot=Find(a);
	int bRoot=Find(b);
	if(aRoot==bRoot)
		return ;
	if(aRoot<bRoot){
		Arry[aRoot]=bRoot;
		size[aRoot]+=size[bRoot];
	}
	else {
		Arry[bRoot]=aRoot;
		size[bRoot]+=size[aRoot];
	}

}
int main (){
	int n,m;//m为数据组数，n为结点个数
	int i,j,k;//循环用
	int x,y;//输入的两个参数
	int count;
	cin>>k;
	while(k--){
		cin>>n>>m;
		count=0;
		//初始化size数组
		for (i = 0; i <n; i++)  
			 size[i] = 1;
		//初始化Arry数组
		for(i=0;i<n;i++)
			Arry[i]=i;
		for(i=0;i<m;i++){
			cin>>x>>y;
			Union(x-1,y-1);
		}
		for(j=0;j<n;j++){
			if(Arry[j]==j)
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}