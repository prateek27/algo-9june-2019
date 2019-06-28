#include<iostream>
#include<vector>
using namespace std;

class Heap{
	vector<int> v;
	bool minType;

	bool compare(int a,int b){
		if(minType){
			return a<b;
		}
		else{
			return a>b;
		}
	}
	void heapify(int idx){
		int left = idx<<1;
		int right = left+1;
		int min_idx = idx;
		int last_idx = v.size()-1;
		if(left<=last_idx and compare(v[left],v[idx])){
			min_idx = left;
		}
		if(right<=last_idx and compare(v[right],v[min_idx])){
			min_idx = right;
		}

		if(min_idx!=idx){
			swap(v[idx],v[min_idx]);
			heapify(min_idx);
		}

	}

public:
	//Constructor
	Heap(int ds=10,bool type=true){
		v.reserve(ds);
		v.push_back(-1); //Block the 0th Index
		minType = type;
	}
	//Push/Insert data into heap
	void push(int d){
		v.push_back(d);
		int idx = v.size()-1;
		int parent = idx/2;

		while(idx>1 and compare(v[idx],v[parent])){
			swap(v[idx],v[parent]);
			idx = parent;
			parent = parent/2;
		}
	}
	int getTop(){
		return v[1];
	}
	//Delete 
	void pop(){
		int last_idx = v.size()-1;
		swap(v[1],v[last_idx]);
		v.pop_back();
		heapify(1);
	}
	bool empty(){
		return v.size()==1;
	}
};

int main(){

	Heap h;
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		h.push(no);
	}

	//Pop 
	while(!h.empty()){
		cout<<h.getTop()<<" ";
		h.pop();
	}


	return 0;
}