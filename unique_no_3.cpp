#include<iostream>
using namespace std;


int main(){

	int arr[] = {1,2,3,1,2,3,7,1,2,3};
	int n = sizeof(arr)/sizeof(int);

	int freq[64] ={0};
	for(int i=0;i<n;i++){
		int j = 0;
		int temp = arr[i];
		while(temp>0){
			if(temp&1){
				freq[j]++;
			}
			temp = temp>>1;
			j++;
		}
	}
	int ans = 0;
	int two_p = 1;
	for(int i=0;i<64;i++){
		ans += (freq[i]%3)*two_p;
		two_p <<=1; 
	}

	cout<<ans<<endl;

	return 0;
}