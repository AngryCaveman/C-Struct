
/*
������Ignatius�����ա���������������ѡ������ǳ�����ʱ���ˡ�Ignatius��֪����������Ҫ��������
�����ע�⵽���������е����Ѷ���ʶ�Է����������е����Ѷ������İ���˴���һ��
��������һ����Ҫ�����ǣ�����Ҹ�����1֪��2��2֪��3����˼��1��2��3�����˽⣬�������ǿ��Դ���һ�����С�
���磺����Ҹ�����1֪��2��2֪��3��4֪��5����ô1��2��3���Դ���һ�����4��5����������һ�����С���������������Ҫ2̨��
*/

#include<iostream>
using namespace std;
#define max 25
//����
int Arry[1003];
int size[1003];
//find
int Find(int num){
	int root=num,temp;
	while(Arry[root]!=root)
		root=Arry[root];
	//·��ѹ��
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
	int n,m;//mΪ����������nΪ������
	int i,j,k;//ѭ����
	int x,y;//�������������
	int count;
	cin>>k;
	while(k--){
		cin>>n>>m;
		count=0;
		//��ʼ��size����
		for (i = 0; i <n; i++)  
			 size[i] = 1;
		//��ʼ��Arry����
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