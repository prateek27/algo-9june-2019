#include<iostream>
using namespace std;

void printSubsequences(char *input,char *output,int i,int j){
	//base case
	if(input[i]=='\0'){
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}
	//rec case
	output[j] = input[i];
	printSubsequences(input,output,i+1,j+1);
	printSubsequences(input,output,i+1,j);
}

int main(){

	char input[10],output[10];
	cin>>input;
	printSubsequences(input,output,0,0);

	return 0;
}