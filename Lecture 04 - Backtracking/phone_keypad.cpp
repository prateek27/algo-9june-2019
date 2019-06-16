#include<iostream>
#include<cstring>
using namespace std;

char mapping[][10] = {"","","ABC","DEF","GHI","JKL"};

void phone_keypad(char *input,char *output,int i,int j){
	if(input[i]=='\0'){
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}
	//rec cas e
	int digit = input[i] - '0';
	for(int k=0;k<strlen(mapping[digit]);k++){
		char ch = mapping[digit][k];
		output[j] = ch;
		phone_keypad(input,output,i+1,j+1);
	}
}

int main(){



	char input[10];
	cin>>input;
	char output[10];
	phone_keypad(input,output,0,0);



	return 0;
}