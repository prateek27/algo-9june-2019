#include<iostream>
using namespace std;

void replacePi(char *input,int i){
	//base case
	if(input[i]=='\0'){
		return;
	}
	//otherwise case 
	if(input[i]=='p' and input[i+1]=='i'){
		//Shifting
		int j = i;
		while(input[j]!='\0'){
			j++;
		}
		//shifting
		while(j>=i+2){
			input[j+2] = input[j];
			j--;
		}
		//Replacement with 3.14
		input[i] = '3';
		input[i+1] = '.';
		input[i+2] = '1';
		input[i+3] = '4';
		replacePi(input,i+4);
	}
	else{
		replacePi(input,i+1);
	}
}

int main(){
	char input[100];
	cin>>input;
	replacePi(input,0);
	cout<<input<<endl;

	return 0;
}