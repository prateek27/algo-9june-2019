#include<iostream>
using namespace std;

int lower_bound(int arr[],int n,int key){
	int s = 0;
	int e = n-1;

	int ans = -1;

	while(s<=e){
		int mid = (s+e)/2;
		if(arr[mid]==key){
			ans = mid;
			e = mid-1; //s=mid+1
		}
		else if(arr[mid]>key){
			e = mid - 1;
		}
		else{ //arr[mid]<key]
			s = mid + 1;
		}
	}
	return ans;
}

int main(){




	return 0;
}