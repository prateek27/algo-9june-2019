#include<iostream>
using namespace std;

int convertToBinary(int n){
	int ten_power = 1;
	int ans = 0;
	while(n>0){
		int last_bit = (n&1);
		ans += ten_power*last_bit;
		ten_power *= 10;
		n >>= 1;
	}
	return ans;
}

int convertToDecimal(int n){
	int ans = 0;
	int two_power=1;

	while(n>0){
		int last_digit = n%10;
		ans += two_power*last_digit;
		n = n/10;
		two_power = two_power<<1;
	}
}

int main(){	
	int n1 = 25;
	int n2 = 1010101;

	cout<<convertToBinary(n1);
	cout<<convertToDecimal(n2);

	return 0;
}