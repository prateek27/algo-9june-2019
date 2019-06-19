#include<iostream>
using namespace std;

bool canPlace(int *stalls,int n,int C,int sep){

	int cows=1;
	int last_cow = stalls[0];
	for(int i=1;i<=n-1;i++){
		int current_stall = stalls[i];
		if(current_stall-last_cow>=sep){
			cows++;
			last_cow = current_stall;
			if(cows==C){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int C = 3;
	int stalls[] = {1,2,4,8,9}; //sort 
	int n = sizeof(stalls)/sizeof(int);

	int s =0;
	int e = stalls[n-1]-stalls[0];

	int ans = 0;
	while(s<=e){
		int mid = (s+e)/2;
		if(canPlace(stalls,n,C,mid)){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid -1;
		}
	}
	cout<<ans<<endl;

	return 0;
}