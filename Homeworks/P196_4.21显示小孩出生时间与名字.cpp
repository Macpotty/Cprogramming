#include"iostream"
using namespace std;
class Time{
	public:
		Time(int h,int m,int s){
			hours=h;
			minutes=m;
			seconds=s;
		}
		void display(){
			cout<<"����ʱ�䣺"<<hours<<"ʱ"<<minutes<<"��"<<seconds<<"��"<<endl;
		}
	protected:
		int hours,minutes,seconds;
};
class Date{
	public:
		Date(int m,int d, int y){
			month=m;
			day=d;
			year=y;
		}
		void display(){
			cout<<"�������£�"<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
		}
	protected:
		int month,day,year;
};
class Brithtime:public Time,public Date{
	public:
		Brithtime(int hours,int minutes,int seconds,int month,int day, int year,char *c):Time(hours,minutes,seconds),Date(month,day,year){
			Childname=c;
		}
		void display(){
			cout<<"С�������֣�"<<Childname<<endl;
			Date::display();
			Time::display();
		}
	private:
		char *Childname;
};
int main(){
	Brithtime c1(10,28,56,6,27,654,"Jon Snow");
	c1.display();
	return 0;
}