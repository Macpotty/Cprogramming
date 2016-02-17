#include"iostream"
using namespace std;
#include"iomanip"
class table{
	public:
		table(char p1,char p2){
			i=p1;
			j=p2;
		}
		void ascii(void);
	protected:
		char i;
		char j;
};
void table::ascii(void){
	int k=1;
	for(;i<='z'&&i!=j+1;i++){
		cout<<setw(2)<<i<<setw(4)<<(int)i;
		if ((k)%12==0)
			cout<<"\n";
		k++;
	}
	cout<<"\n";
}
class der_table:public table{
	public:
		der_table(char p1,char p2,char *m):table(p1,p2){c=m;}
		void print(void);
	protected:
		char *c;
};
void der_table::print(void){
	cout<<c<<"\n";
	table::ascii();
}
/*int main(){
	der_table ob1(32,"ASCII value---char");
	ob1.print();
	return 0;
}*/
int main(){
	der_table ob('a','z',"ASCII value--- char");
	ob.print();
	return 0;
}