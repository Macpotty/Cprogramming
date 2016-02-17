#include"iostream"
using namespace std;
template<typename T>
class plus{
	public:
		plus(){
			cin>>a>>b>>c;
		}
		void doing(){
			cout<<a+b+c<<endl;
		}
	private:
		T a,b,c;
};
int main(){
	plus<int>obj1;
	obj1.doing();
	plus<double>obj2;
	obj2.doing();
}