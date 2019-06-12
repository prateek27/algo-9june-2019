#include<iostream>
using namespace std;

int power(int a,int n){
	//base case
	if(n==0){
		return 1;
	}
	//rec case
	int subProb = power(a,n/2);
	subProb = subProb*subProb;
	if(n&1){
		return a*subProb;
	}
	return subProb;
}

int fastPower(int a,int n){
	int ans = 1;
	while(n>0){
		if(n&1){
			ans *= a;
		}
		a = a*a;
		n = n>>1;
	}
    return ans;
}

int main(){
	int a,n;
	cin>>a>>n;
    cout<<fastPower(a,n)<<endl;


	return 0;
}