#include"FanWai.h"
//���������������ز���
#include<vector>//vectorͷ�ļ�
int main()
{
	int end,i,j;
	//01Vector
	vector<int> vec1(5);//����5���ռ�
	cout << vec1[0] << endl;//Ĭ��ֵΪ0
	vec1[0] = 1;
	cout << vec1[0] << endl;
	vector<int> vec2(5, 4);//����5���ռ�Ϊ4��vector
	for (i = 0; i < vec2.size();i++)//������size���������õ�Ԫ�ظ���
		cout << vec2[i] << " ";
	cout << endl;
	vector<int> vec3(vec2);//vec2��ʼ��vec3
	for (i = 0; i < vec3.size(); i++)//������size���������õ�Ԫ�ظ���
		cout << vec3[i] << " ";
	cout << endl;
	vector<int> vec4(vec2.begin(), vec2.end());//vec2��ʼ��vec3
	for (i = 0; i < vec4.size(); i++)//������size���������õ�Ԫ�ظ���
		cout << vec4[i] << " ";
	cout << endl;
	vec2.push_back(100);//���Ԫ��
	
	//vector<int, string> vec5;
	//����
	cin >> end;
	return 0;
}