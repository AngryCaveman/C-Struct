/*����һ������Ϊm�����䣬�ٸ���n���߶ε������յ㣨ע�������Ǳ����䣩��
������ʹ�ö������߶ο��Խ�����������ȫ����
*/
#include<iostream>
using namespace std;
#define Max 10
int main(){
	int i,j,temp,k;//ѭ����
	int n;
	int m;
	int arry[Max][2];
	int sum;//����
	int start,end;
	cout<<"�����䳤�ȣ�";cin>>m;
	cout<<"�߶�������";cin>>n;
	for(i=0;i<n;i++){
		cin>>arry[i][0]>>arry[i][1];
	}
	//ð����������
	//��˵��С������
	for (i = 0; i < n; i++){  
        for (j = i + 1; j < n; j++){  
            if (arry[i][0]> arry[j][0]){ 
				temp=arry[i][0];
				arry[i][0]=arry[j][0];
				arry[j][0]=temp;
				//���齻��
				 temp=arry[i][1];
				arry[i][1]=arry[j][1];
				arry[j][1]=temp;
            }  
        }  
    }  
	//��Ҫ���߼�����
	//��һ����ѡ
	sum=1;//������һ��
	i=0;
	start=arry[0][0];
	end=arry[0][1];
	cout<<"("<<start<<","<<end<<")"<<endl;
	//
	int endM=end;//����������ཻʱ��ȡ������������
	while(endM<8){
		for(j=i+1;j<n;j++){
			if(arry[j][1]>end && arry[j][0]<=end && arry[j][1]>=endM){//�ཻ
				endM=arry[j][1];
				i=j;
			}
			else{
				break;
			}
		}
		sum++;
		end=arry[i][1];//����end����ֵ
		cout<<"("<<arry[i][0]<<","<<arry[i][1]<<")"<<endl;
	}
	cout<<"������"<<sum;
	return 0;
}