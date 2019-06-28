#include<iostream>
#include<queue>
using namespace std;

int main(){

	priority_queue<int,vector<int>,greater<int> > h; //max or min?

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		h.push(no);
	}

	//Pop 
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}

	return 0;
}