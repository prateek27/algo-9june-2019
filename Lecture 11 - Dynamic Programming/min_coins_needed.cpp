#include<iostream>
#include<climits>
using namespace std;

int minCoinsTD(int n,int coins[],int m,int *dp){
	//Base Case
	if(n==0){
		return 0;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	//Rec Case
	int ans = INT_MAX;
	for(int i=0;i<m;i++){
		if(n-coins[i]>=0){
			ans = min(ans,minCoinsTD(n-coins[i],coins,m,dp)+1);
		}
	}
	return dp[n] = ans;
}
int minCoinsBU(int n,int coins[],int m){
//Rec Case
	int dp[100] = {0};
	dp[0] = 0;

	for(int i=1;i<=n;i++){
		dp[i] = INT_MAX;
		for(int t=0;t<m;t++){
			if(i-coins[t]>=0){
				dp[i] = min(dp[i],dp[i-coins[t]]+1);
			}
		}
	}
	return dp[n];
}
int main(){

	int coins[] = {1,7,10};
	int m = sizeof(coins)/sizeof(int);
	int n;
	cin>>n;

	int dp[100] = {0};
	cout<<minCoinsTD(n,coins,m,dp)<<endl;
	cout<<minCoinsBU(n,coins,m)<<endl;


	return 0;
}