#include<bits/stdc++.h>
using namespace std;

class compare{
public:
	bool operator()(pair<string,int> a,pair<string,int> b){
		return a.second < b.second;
	}
};

int main(){

	set<pair<string,int>, compare > v;
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		string fruit;
		int price;
		cin>>fruit>>price;
		v.insert(make_pair(fruit,price));
	}
	
	for(auto p:v){
		cout<<p.first<<" "<<p.second;
	}

	return 0;	
}