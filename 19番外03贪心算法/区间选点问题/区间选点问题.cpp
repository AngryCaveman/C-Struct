/*���躣������һ�����������ֱ�ߡ�½���ں����ߵ�һ�࣬����������һ�ࡣ
ÿһ��С�ĵ����Ǻ����ϵ�һ���㡣�״������ں������ϣ�ֻ�ܸ���d���롣
��ĿҪ�������ܹ����Ǹ��������е���������״���Ŀ��
*/
#include<iostream>
using namespace std;
#define Max 10
int main(){
	int i, j, temp;//ѭ����
	int n,sum;
	int arry[Max][2];
	int start, end;//���俪ʼ�ĵ����������ĵ�
	cout<<"���������";cin >> n;
	for (i = 0; i < n; i++){
		cin >> arry[i][0] >> arry[i][1];
	}
	//ð������:����
	//������С��������
	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			if (arry[i][0]> arry[j][0]){
				temp = arry[i][0];
				arry[i][0] = arry[j][0];
				arry[j][0] = temp;
				//���齻��
				temp = arry[i][1];
				arry[i][1] = arry[j][1];
				arry[j][1] = temp;
			}
		}
	}
	//����
	start = arry[0][0];
	end = arry[0][1];
	sum = 1;//sum���״����������һ��
	for (i = 1; i < n;i++){
		if (start<=arry[i][0] &&end>=arry[i][1]){//�������
			start = arry[i][0]; end=arry[i][1];
		}
		else if (end>arry[i][0] && end<=arry[i][1]){//�����ཻ
			start = arry[i][0];
		}
		else if (end<=arry[i][0]){//���佻��Ϊ��
			cout << "(" << start << "," << end << ")" << endl;//��������Բ���
			sum++;
			start = arry[i][0];
			end = arry[i][1];
		}
	}
	cout << "(" << start << "," << end << ")" << endl;//��������Բ���
	cout << "�����״�=" << sum;
	return 0;
}
//��������:����������5  ��
//(2��5��(6��9��(8��11��(10��11��(9��15)
//��������:����������3  ��
//(1��5��(2��7��(3,5)(6��10��