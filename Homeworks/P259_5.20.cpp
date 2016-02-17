#include"iostream"
using namespace std;
const double pi=3.1415926;
class Container{
	public:
		Container(double a,double b){
			x=a;
			y=b;
		}
		virtual void count()=0;
	protected:
		double x,y;
};
class Sphere:protected Container{
	public:
		Sphere(double a):Container(a,a){}
		void count(){
			cout<<"������Ϊ��"<<4.0*pi*x*x<<endl;
			cout<<"�����Ϊ��"<<3.0/4.0*pi*x*x*x<<endl;
		}
};
class Cylinder:protected Container{
	public:
		Cylinder(double a,double b):Container(a,b){}
		void count(){
			cout<<"Բ���������"<<pi*2.0*x*y+2.0*pi*x*x<<endl;
			cout<<"Բ�������"<<pi*x*x*y<<endl;
		}
};
class Cube:protected Container{
	public:
		Cube(double a):Container(a,a){}
		void count(){ 
			cout<<"������������"<<6.0*x*x<<endl;
			cout<<"�����������"<<x*x*x<<endl;
		}
};
int main(){
	Sphere obj1(2.3);
	Cylinder obj2(3.5,5.2);
	Cube obj3(3.5);
	obj1.count();
	obj2.count();
	obj3.count();
}