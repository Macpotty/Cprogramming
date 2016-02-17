#include"iostream"
#include"string"
using namespace std;
class person{
	public:
		person(){
			string num,n;
			cout<<"请输入编号：";
			cin>>num;
			cout<<"请输入姓名：";
			cin>>n;
			number=num;
			name=n;
		}
		void display(){
			cout<<"编号："<<number<<"\n姓名："<<name<<endl;
		}
	protected:
		string number,name;
};
class student:protected person{
	public:
		student():person(){
			int c,g;
			cout<<"请输入班号：";
			cin>>c;
			cout<<"请输入成绩：";
			cin>>g;
			classnum=c;
			grade=g;
		}
		void display(){
			cout<<"学生\n";
			person::display();
			cout<<"班号："<<classnum<<"\n成绩："<<grade<<endl;
		}
	private:
		int classnum,grade;
};
class teacher:protected person{
	public:
		teacher():person(){
			string t,d;
			cout<<"请输入部门：";
			cin>>t;
			cout<<"请输入职称：";
			cin>>d;
			title=t;
			department=d;
		}
		void display(){
			cout<<"教师\n";
			person::display();
			cout<<"职称："<<title<<"\n部门："<<department<<endl;
		}
	private:
		string title,department;
};
int main(){
	student s1;
	s1.display();
	teacher t1;
	t1.display();
	return 0;
}