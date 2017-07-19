#include"FanWai.h"
//容器与迭代器的相关测试
#include<vector>//vector头文件
int main()
{
	int end,i,j;
	//01Vector
	vector<int> vec1(5);//声明5个空间
	cout << vec1[0] << endl;//默认值为0
	vec1[0] = 1;
	cout << vec1[0] << endl;
	vector<int> vec2(5, 4);//声明5个空间为4的vector
	for (i = 0; i < vec2.size();i++)//遍历，size（）函数得到元素个数
		cout << vec2[i] << " ";
	cout << endl;
	vector<int> vec3(vec2);//vec2初始化vec3
	for (i = 0; i < vec3.size(); i++)//遍历，size（）函数得到元素个数
		cout << vec3[i] << " ";
	cout << endl;
	vector<int> vec4(vec2.begin(), vec2.end());//vec2初始化vec3
	for (i = 0; i < vec4.size(); i++)//遍历，size（）函数得到元素个数
		cout << vec4[i] << " ";
	cout << endl;
	vec2.push_back(100);//添加元素
	
	//vector<int, string> vec5;
	//结束
	cin >> end;
	return 0;
}