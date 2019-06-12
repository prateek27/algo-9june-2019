#include<iostream>
using namespace std;



int main(){

	int primes[] = {2,3,5,7,11,13,17,19};
	int p = sizeof(primes)/sizeof(int);

	int ans = 0;
	int denom = 1;
	int n;
	cin>>n;

	for(int i=1;i<(1<<p);i++){

		int cnt_bits = __builtin_popcount(i);
		int temp = i;
		int denom = 1;
		int j = 0;

		while(temp>0){
			int last_bit = (temp&1);
			if(last_bit){
				denom = denom*primes[j];
			}
			j++;
			temp = temp>>1;
		}

		//Inclusion Exclusion
		if(cnt_bits&1){
			ans += n/denom;	
		} 
		else{
			ans -= n/denom;
		}

	}
	cout<<ans<<endl;


	return 0;
}