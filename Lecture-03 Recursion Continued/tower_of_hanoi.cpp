#include<iostream>
using namespace std;

int cntTOH(int n){
	if(n==0){
		return 0;
	}
	return 2*cntTOH(n-1)+1;
}

// Print Steps
void TOH(int n,char src,char dest,char helper){
	if(n==0){
		return;
	}
	//Steps Breakdown
	TOH(n-1,src,helper,dest);
	cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
	TOH(n-1,helper,dest,src);
}


int main(){
	int n;
	cin>>n;
	cout<<cntTOH(n)<<endl;


	return 0;
}