#include<iostream>
using namespace std;


void generate_brackets(int n,char *output,int i,int open,int close){
	if(i==2*n){
		output[i] ='\0';
		cout<<output<<endl;
		return;
	}
	//rec case 
	if(open<n){
		output[i] = '(';
		generate_brackets(n,output,i+1,open+1,close);
	}

	if(close<open){
		output[i] = ')';
		generate_brackets(n,output,i+1,open,close+1);
	}
}

int main(){
	int n;
	cin>>n;
	char output[100];
	generate_brackets(n,output,0,0,0);

	return 0;
}

