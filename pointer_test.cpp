#include<iostream>
using namespace std;


int main(){

	int x = 10;
	int *y = &x;
	int **z = &y;

	cout<<x <<endl;
	cout<< &x <<endl;
	cout<< y <<endl;
	cout<< &y <<endl;
	cout<< *(&y) <<endl;
	cout<<&(*y) <<endl;
	cout<<&z <<endl;
	cout<<*(*(&z))<<endl;
	cout<< *z <<endl;
	cout<<*x <<endl;
	cout<< &(*z)<<endl;
	


	return 0;
}