#include<iostream>
using namespace std;

bool isSorted(int *arr,int n){
	//base case
	if(n==1){
		return true;
	}
	if(arr[0]<arr[1] and isSorted(arr+1,n-1)){
		return true;
	}	
	return false;

}

int main(){	
	int arr[] = {1,2,3,0,5,2};
	if(isSorted(arr,n)){
		cout<<"Yes it is sorted!";
	}
	else{
		cout<<"Not Sorted!";
	}

	return 0;
}