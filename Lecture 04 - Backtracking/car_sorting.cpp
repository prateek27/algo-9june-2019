#include<bits/stdc++.h>
using namespace std;

class triplet;//



class triplet{
public:
	string name;
	int x,y;

	triplet(string n,int x,int y){
		name = n;
		this->x = x; // (*this).x = x;
		this->y = y;
	}
	int dist(){
		return x*x + y*y;
	}
};

bool compare(triplet a,triplet b){
	return a.dist() < b.dist();
}

int main(){
	int n;
	cin>>n;

	vector<triplet> v;

	for(int i=0;i<n;i++){
		string car;
		int x,y;
		cin>>car>>x>>y;
		triplet t(car,x,y);
		v.push_back(t);
	}

	sort(v.begin(),v.end(),compare);

	for(auto t:v){
		cout<<t.name<<" "<<t.dist()<<endl;
	}

	return 0;
}


