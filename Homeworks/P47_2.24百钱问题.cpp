#include"iostream"
using namespace std;
int main(){
	int i,j,n=0;
	float k;
	for(i=0;i<=100;i++)
		for(j=0;j<=50;j++){
			k=(100-i-2*j)/5;
			if(k!=int(k)||i+2*j+5*k!=100||k<0)continue;
			n++;
			cout<<"һ��Ǯ"<<i<<"�� "<<"����Ǯ"<<j<<"�� "<<"���Ǯ"<<k<<"��"<<endl;
		}
	cout<<"�ܹ�"<<n<<"�ֻ�Ǯ����"<<endl;
	return 0;
}