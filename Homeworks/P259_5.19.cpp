#include"iostream"
using namespace std;
class complex{
	public:
		complex(double x=0.0,double y=0.0){
			a=x;
			b=y;
		}
		friend complex operator+(complex &obj1,complex obj2){
			complex temp;
			temp.a=obj1.a+obj2.a;
			temp.b=obj1.b+obj2.b;
			return temp;
		}
		void print(){
			cout<<"("<<a<<","<<b<<")"<<endl;	
		}
	private:
		double a,b;
};		
int main(){
	complex c1(2.5,3.7),c2(4.2,6.5),c3;
	c3=c1+c2;
	c3.print();
	return 0;
}