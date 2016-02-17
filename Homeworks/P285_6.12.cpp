#include"iostream"
using namespace std;
template<typename T>
T max(T a[],int l){
	int n;
	T m;
	n=l;
	m=a[n];
	for(n;n>=0;n--){
		if(a[n]>m)m=a[n];
	}
	return m;
}
int main(){
	int a[]={13,57,34,29,45,95,34,12,64,15,48,97,65,96,23,14},m;
	double b[]={12.5,15.4,65.2,98.6,78.1,32.4,54.3,87.3,16.6,18.9,97.1},n;
	m=max(a,sizeof(a)/sizeof(int));
	n=max(b,sizeof(b)/sizeof(double));
	cout<<m<<"\n"<<n<<endl;
}