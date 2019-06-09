#include<iostream>
using namespace std;

int cnt_bits(int n){
	int ans = 0;
	while(n>0){
		ans += (n&1);
		n = n>>1;
	}
	return ans;
}

//what does this code do?
int fun(int n){

	int cnt = 0;
	while(n>0){
		cnt++;
		n = (n&(n-1));
	}
	return cnt;
}


int main(){
	int n;
	cin>>n;
	cout<<cnt_bits(n)<<endl;
	cout<<fun(n)<<endl;
	cout<<__builtin_popcount(n)<<endl; // O(1) 

	return 0;
}