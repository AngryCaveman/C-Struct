//������3����Ʒ�����ǵ������ͼ۸�ֱ���10, 5, 30,20 kg��60, 100, 120,40��
//����ѡ��һЩ�����һ���֣������Σ��ף�ʹ������������������������V���������ܼ�ֵ���
#include<iostream>
using namespace std;
#define N 4
#define W 44 //����������
int main(){
	int V[N]={10,5,30,20};//����
	int P[N]={60,100,120,40};//�۸�
	double Vp[N];//ÿ����Ʒ��λ�����ļ۸�
	int i,j,temp;//ѭ����
    int SumW=0;//��¼����
	int Vlaue=0;//��¼�۸�
	int SumTemp=0;//��ʱ��¼�ܺͣ������л�Vp����
	//��λ�����۸�
	for(i=0;i<N;i++){
		Vp[i]=P[i]/V[i];
	}
	//ð������,���ɴ�С
	for (i = 0;i < N; i++){  
        for (j = i + 1; j <N; j++){  
			if (Vp[i] < Vp[j]){
				temp=Vp[i];
				Vp[i]=Vp[j];
				Vp[j]=temp;
				//��V��P��Ӧ��
				temp=V[i];
				V[i]=V[j];
				V[j]=temp;
				temp=P[i];
				P[i]=P[j];
				P[j]=temp;
			}
        }  
    } 
	//����ѡ��
	i=0;
	while(SumW<W){
		while(SumTemp<V[i]){
			SumTemp++;//����һ����λһ����λ�ļ�
			if(SumW+SumTemp>=W)
				break;
		}
		SumW+=SumTemp;
		Vlaue+=SumTemp*Vp[i];
		SumTemp=0;
		i++;
	}
	cout <<Vlaue;
	return 0;
}
//���:276=20*5+6*10+4*29;5+10+29=45
//�����Vp={20,6,4,2},V={5,10,30,20},P={100,60,120,40}
