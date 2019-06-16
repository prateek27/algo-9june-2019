#include<iostream>
using namespace std;


int main(){

	pair<string,int> p;
	p.first = "Apple";
	p.second  = 100;

	cout<<p.first<<endl;
	cout<<p.second<<endl;

	pair<string,int> p2 = make_pair("Grapes",20);
	cout<<p2.first<<" "<<p2.second<<endl;


	return 0;	
}