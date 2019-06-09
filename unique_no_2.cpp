	#include<iostream>
	using namespace std;

	int main(){

		int arr[] = {1,2,3,4,5,6,6,4,3,2,1,7,8,8};
		int n = sizeof(arr)/sizeof(int);

		int sabka_xor = 0;
		for(int i=0;i<n;i++){
			sabka_xor  = sabka_xor^arr[i];
		}

		int temp = sabka_xor;
		//find any one set bit (right)
		int p = 0;
		while((temp&1)==0){
			p++;
			temp = temp>>1;
		}
		int setA = 0;
		int mask = (1<<p);
		for(int i=0;i<n;i++){
			//filter out no's having set bit a position p
			if((arr[i]&mask) >0){
				setA ^= arr[i];
			}
		}
		cout<<setA <<endl;
		int setB = sabka_xor^setA;
		cout<<setB<<endl;


		return 0;
	}