#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> a,pair<string,int> b){
	if(a.second==b.second){
		return a.first < b.first;
	}
	return a.second<b.second;
} 

int main(){

	vector<pair<string,int> > v;
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		string fruit;
		int price;
		cin>>fruit>>price;
		v.push_back(make_pair(fruit,price));
	}
	sort(v.begin(),v.end(),compare);

	for(auto p:v){
		cout<<p.first<<" "<<p.second;
	}

	return 0;	
}