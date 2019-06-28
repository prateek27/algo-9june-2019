#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Fruit{
public:	
	string name;
	int price;

	Fruit(){

	}
	
	Fruit(string n,int p){
		name = n;
		price = p;
	}
	bool operator()(Fruit a,Fruit b){
		return a.price>b.price;
	}
};


int main(){
	int n;
	cin>>n;

	priority_queue<Fruit,vector<Fruit>,Fruit> h;

	for(int i=0;i<n;i++){
		string n;
		int p;
		cin>>n>>p;
		Fruit f(n,p);
		h.push(f);
	}

	while(!h.empty()){
		Fruit f = h.top();
		h.pop();
		cout<<f.price<<" and "<<f.name<<endl;
	}

	return 0;
}