#include<iostream>
#include<set>
#include<cstring>
using namespace std;

void permute(char input[],int i,set<string> &s){
	//base case
	if(input[i]=='\0'){
		//cout<<input<<endl;
		string temp = input;
		s.insert(temp);
		return;
	}

	//rec case
	for(int j=i;input[j]!='\0';j++){
		swap(input[i],input[j]);
		permute(input,i+1,s);
		swap(input[i],input[j]);
	}

}

int main(){

	set<string> s;
	char input[10];
	cin>>input;
	permute(input,0,s);

	for(string t:s){
		cout<<t<<" ";
	}
	return 0;
}