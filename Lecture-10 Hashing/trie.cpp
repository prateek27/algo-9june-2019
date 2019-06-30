#include<iostream>
#include<unordered_map>
using namespace std;

# define node Node

class Node{

public:
	char data;
	unordered_map<char,node*> m;
	bool isTerminal;

	Node(char d){
		data = d;
		isTerminal = false;
	}
};

class Trie{
	Node* root;
public:
	Trie(){
		root = new node('\0');
	}
	void addWord(char word[]){

		Node* temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->m.count(ch)==0){
				Node* n = new Node(ch);
				temp->m[ch] = n;
				temp = n;
			}
			else{
				temp = temp->m[ch];
			}
		}
		temp->isTerminal = true;
		return;
	}
	bool search(char word[]){
		Node*temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->m.count(ch)==0){
				return false;
			}
			else{
				temp = temp->m[ch];
			}
		}
		return temp->isTerminal;
	}
};

int main(){
	Trie t;
	char  words[][10] = {"no","not","news","apple","ape"};
	for(int i=0;i<5;i++){
		t.addWord(words[i]);
	}
	char input[10];
	cin>>input;

	if(t.search(input)==false){
		cout<<input<<" not found!";
	}
	else{
		cout<<input<<" found! :D";
	}

	return 0;
}