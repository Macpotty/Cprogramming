#include"iostream"
using namespace std;
const int M=20;
inline int Fibonacci(int &a,int &b);
int main(){
	int *p1=new int(1),*p2=new int(1),Fnum;
	Fnum=Fibonacci(*p1,*p2);
	cout<<"第二十个斐波那契数为"<<Fnum<<endl;
	delete p1;
	delete p2;
	return 0;
}
inline int Fibonacci(int &a,int &b){
	int i=0;
	for(;;){
		if(++i==M)return a;
		a+=b;
		if(++i==M)return b;
		b+=a;
	}
}	