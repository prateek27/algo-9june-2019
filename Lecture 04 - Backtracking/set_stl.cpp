#include<iostream>
#include<set>
using namespace std;


int main(){

	int n;
	
	int arr[] = {1,1,2,3,3,3,3,4,0,1,0};
	n = sizeof(arr)/sizeof(int);


	set<int> s;
	for(int i=0;i<n;i++){
		s.insert(arr[i]);
	}
	s.erase(3);

	//iterate
	for(auto no:s){
		cout<<no<<endl;
	}



	return 0;
}
