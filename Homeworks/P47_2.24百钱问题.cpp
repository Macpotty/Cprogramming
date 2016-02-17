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
			cout<<"一分钱"<<i<<"个 "<<"两分钱"<<j<<"个 "<<"五分钱"<<k<<"个"<<endl;
		}
	cout<<"总共"<<n<<"种换钱方法"<<endl;
	return 0;
}