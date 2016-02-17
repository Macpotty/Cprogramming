#include"iostream"
using namespace std;
class counter{
public:
	counter(int number);
	void increment();
	void decrement();
	int getvalue();
	int print();
private:
	int value;
};
counter::counter(int number):value(number){}
void counter::increment(){
	value++;
}
void counter::decrement(){
	value--;
}
int counter::getvalue(){
	return value;
}
int counter::print(){
	cout<<"value is"<<value<<endl;
	return 0;
}
int main(){
	counter a(83);
	a.print();
	a.increment();
	a.print();
	a.decrement();
	a.print();
	return 0;
}