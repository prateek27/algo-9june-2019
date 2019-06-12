#include<iostream>
#include<cstring>
using namespace std;

void filterChars(char input[],int i){
	int j=0;

	while(i>0){
		int last_bit = (i&1);
		if(last_bit){
			cout<<input[j];
		}
		j++;
		i = i>>1;
	}
	cout<<endl;

}

void printSubsets(char input[]){
	int n = strlen(input);

	for(int i=0;i< (1<<n);i++){
		filterChars(input,i);
	}
}

int main(){

	//Problem - Generate all subsets of a given array/string!
	char input[10];
	cin>>input;
	printSubsets(input);
	

}