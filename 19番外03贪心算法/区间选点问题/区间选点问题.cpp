/*假设海岸线是一条无限延伸的直线。陆地在海岸线的一侧，而海洋在另一侧。
每一个小的岛屿是海洋上的一个点。雷达坐落于海岸线上，只能覆盖d距离。
题目要求计算出能够覆盖给出的所有岛屿的最少雷达数目。
*/
#include<iostream>
using namespace std;
#define Max 10
int main(){
	int i, j, temp;//循环用
	int n,sum;
	int arry[Max][2];
	int start, end;//区间开始的点和区间结束的点
	cout<<"岛屿个数：";cin >> n;
	for (i = 0; i < n; i++){
		cin >> arry[i][0] >> arry[i][1];
	}
	//冒泡排序:升序
	//按左点从小到大排序
	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			if (arry[i][0]> arry[j][0]){
				temp = arry[i][0];
				arry[i][0] = arry[j][0];
				arry[j][0] = temp;
				//整组交换
				temp = arry[i][1];
				arry[i][1] = arry[j][1];
				arry[j][1] = temp;
			}
		}
	}
	//计算
	start = arry[0][0];
	end = arry[0][1];
	sum = 1;//sum是雷达个数，最少一个
	for (i = 1; i < n;i++){
		if (start<=arry[i][0] &&end>=arry[i][1]){//区间包含
			start = arry[i][0]; end=arry[i][1];
		}
		else if (end>arry[i][0] && end<=arry[i][1]){//区间相交
			start = arry[i][0];
		}
		else if (end<=arry[i][0]){//区间交集为空
			cout << "(" << start << "," << end << ")" << endl;//输出，可以不看
			sum++;
			start = arry[i][0];
			end = arry[i][1];
		}
	}
	cout << "(" << start << "," << end << ")" << endl;//输出，可以不看
	cout << "最少雷达=" << sum;
	return 0;
}
//测试用例:测试用例：5  ；
//(2，5）(6，9）(8，11）(10，11）(9，15)
//测试用例:测试用例：3  ；
//(1，5）(2，7）(3,5)(6，10）