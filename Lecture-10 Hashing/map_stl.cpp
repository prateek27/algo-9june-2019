#include<iostream>
#include<map>
using namespace std;

int main(){
	map<string,int> h;
	//Insert - 1st way
	h.insert(make_pair("Apple",20));
	
	h["mango"] = 200;
	//2nd way
	pair<string,int> p;
	p.first = "guava";
	p.second = 25;
	h.insert(p);
	//3rd way
	h["banana"] = 50;

	//Search - 2 ways
	if(h.count("banana")==0){
		cout<<"Not found!";
	}
	else{
		cout<<h["banana"];
	}
	//Remove
	h.erase("banana");

	// Find
	auto ptr = h.find("banana");
	if(ptr==h.end()){
		cout<<"Banana not found!";
	}
	else{
		cout<<ptr->first<<" and "<<ptr->second<<endl;
	}
	//Print 
	for(auto p:h){
		cout<<p.first<<" and "<<p.second<<endl;
	}

	h.clear();


}