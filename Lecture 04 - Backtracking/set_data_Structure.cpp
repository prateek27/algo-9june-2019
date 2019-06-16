#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
	return a>b
}

int main(){

	vector<int> v;
	v.reserve(100);

	for(int i=0;i<5;i++){
		v.push_back(100-i*i);
	} 
	//Print 
	for(int i=0;i<v.size();i++){
		cout<< v[i] <<" ";
	}
	cout<<"Size "<<v.size()<<endl;
	cout<<"Capacity "<<v.capacity()<<endl;
	cout<<"Max size "<<v.max_size()<<endl;

	v.pop_back();
	//Print 

	sort(v.begin(),v.end(),compare);

	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout<< (*it)<<" ";
	}
	cout<<endl;

	for(auto it=v.begin();it!=v.end();it++){
		cout<< (*it)<<" ";
	}
	//for each loop
	for(int x:v){
		cout<<x<<" ";
	}


	return 0;
}