/*
��n����Ҫ��ͬһ��ʹ��ͬһ�����ҵĻa1,a2,��,an������ͬһʱ��ֻ����һ���ʹ�á�
ÿ���ai����һ����ʼʱ��si�ͽ���ʱ��fi ��һ����ѡ��󣬻ai��ռ�ݰ뿪ʱ������[si,fi)��
���[si,fi]��[sj,fj]�����ص���ai��aj������Ϳ��Ա���������һ�졣
���������Ҫ������Щ�ʹ�þ�����Ļ�ܲ���ͻ�ľ��С�
*/
#include<iostream>
using namespace std;
#define Max 10//�������  
int main(){
	int i,j,temp;//ѭ����
	int n;//�����
	int arry[Max][2];
	int sum;//�����
	int s=0,e=24;//һ��24��Сʱ��0��24��
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arry[i][0]>>arry[i][1];
	}
	//ð������:����
	//������ʱ������
	for (i = 0; i < n; i++){  
        for (j = i + 1; j < n; j++){  
            if (arry[i][1]> arry[j][1]){  
                temp=arry[i][1];
				arry[i][1]=arry[j][1];
				arry[j][1]=temp;

				//���齻��
				temp=arry[i][0];
				arry[i][0]=arry[j][0];
				arry[j][0]=temp;
            }  
        }  
    }  
	//����
	temp=arry[0][1];
	cout<<"["<<arry[0][0]<<","<<arry[0][1]<<")"<<endl;
	sum=1;
	for(i=1;i<n;i++){
		if(temp<=arry[i][0]){
			sum++;
			temp=arry[i][1];
			cout<<"["<<arry[i][0]<<","<<arry[i][1]<<")"<<endl;
		}
		//Ӧ���ж�һ�ºϷ��ԣ�������Ӱ��˼·�����ǲ�Ҫ��
		//if(arry[i][1]>24 || arry[i][0]>24)
			//break;
	}
	cout<<sum;
	return 0;
}
//����������5  ����2��10����5��6����11��13����13��20����19��24��
//���:3