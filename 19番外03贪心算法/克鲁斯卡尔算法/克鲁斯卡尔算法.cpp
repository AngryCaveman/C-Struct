#include<iostream>
using namespace std;
#define INFINITY 65535//最大值
#define Maxvex 10//最大结点个数
int Find(){
}
void Union(){
}
int Kruskal(int M[Maxvex][Maxvex]){
	int i,j;
	//构造Edge边数组
	for(i=0;i<Maxvex;i++){
		
	}
}
int main(){
	//构建图矩阵
	int MyGraph[Maxvex][Maxvex] = {
		{ 0, 10, INFINITY, INFINITY, INFINITY, 11, INFINITY, INFINITY, INFINITY },
		{ 10, 0, 18, INFINITY, INFINITY, INFINITY,16 , INFINITY, 12 },
		{ INFINITY, INFINITY, 0, 22, INFINITY, INFINITY, INFINITY, INFINITY, 8 },
		{ INFINITY, INFINITY, 22, 0, 20, INFINITY, INFINITY, 16, 21 },
		{ INFINITY, INFINITY, INFINITY, 20, 0, 26, INFINITY, 7, INFINITY },
		{ 11, INFINITY, INFINITY, INFINITY, 20, 0, 17, INFINITY, INFINITY },
		{ INFINITY, 16, INFINITY, INFINITY, INFINITY, 17, 0, 19, INFINITY },
		{ INFINITY, INFINITY, INFINITY, 16, 7, INFINITY, 19, 0, INFINITY },
		{ INFINITY, 12, 8, 21, INFINITY, INFINITY, INFINITY, INFINITY, 0 } };
	return 0;
}