#include<iostream>
using namespace std;
//Function overloading
void fun(int *y){
	*y = *y + 1;
}

void fun(int &z){
	z = z + 2;
}

int main(){

	int x = 10;
	fun(&x); //using pointer
	fun(x); //using ref variable
	cout<<x <<endl;
	return 0;
}