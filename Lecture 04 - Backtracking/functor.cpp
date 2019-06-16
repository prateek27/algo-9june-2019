#include<iostream>
using namespace std;

class fun{
	public:
		// +, -, *, /, <<, >>, [], (), ^,! 
		void operator!(){
			cout<<"Not good1";
		}
		void operator()(){
			cout<<"In round brackets!";
		}
		bool operator()(int a,int b){
			cout<<"Comparing a and b"<<a<<" and "<<b;
		}

		void some_fn(){
			cout<<"Not good2";
		}

};

int main(){

	fun myfun;
	!myfun;
	myfun();
	myfun(1,2); //functional Object [Functor ins short] 
	myfun.some_fn();

};