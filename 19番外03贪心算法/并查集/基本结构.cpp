
/*
������Ignatius�����ա���������������ѡ������ǳ�����ʱ���ˡ�Ignatius��֪����������Ҫ��������
�����ע�⵽���������е����Ѷ���ʶ�Է����������е����Ѷ������İ���˴���һ��
��������һ����Ҫ�����ǣ�����Ҹ�����1֪��2��2֪��3����˼��1��2��3�����˽⣬�������ǿ��Դ���һ�����С�
���磺����Ҹ�����1֪��2��2֪��3��4֪��5����ô1��2��3���Դ���һ�����4��5����������һ�����С���������������Ҫ2̨��
*/
#include<iostream>
using namespace std;
#define max 11
//����
int Arry[max];
int size[max];
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
	int n,m;//nΪ����������mΪ������
	int i,j;//ѭ����
	int x,y;//�������������
	cin>>n>>m;
	//��ʼ��size����
	for (int i = 1; i <=m; i++)  
		 size[i] = 1;   
	for(i=1;i<=n;i++){
		cin>>x>>y;

	}
	return 0;
}