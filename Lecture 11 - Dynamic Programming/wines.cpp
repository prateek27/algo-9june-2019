#include<iostream>
using namespace std;

int mxProfit(int *arr,int i,int j,int y){
	if(i>j){
		return 0;
	}
	int op1 = arr[i]*y + mxProfit(arr,i+1,j,y+1);
	int op2 = arr[j]*y + mxProfit(arr,i,j-1,y+1);
	return max(op1,op2);
}

int main(){
	int wines[] = {2,3,5,1,4};
	int n = 5;

	cout<<mxProfit(wines,0,n-1,1);

	return 0;
}