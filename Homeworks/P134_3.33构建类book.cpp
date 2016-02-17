#include"iostream"
using namespace std;
class book{
	public:
		book(int qu);
		void print();
	private:
		int qu;
		int price;
};
book::book(int a):qu(a){
	price=10*a;
}
void book::print(){
	cout<<price*qu<<endl;
}
int main(){
	int i;
	book a[5]={1,2,3,4,5};
	for(i=0;i<5;i++)
		a[i].print();
	return 0;
}