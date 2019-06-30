#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
	string key;
	T value;
	Node<T>*next;

	Node(string k,T v){
		key = k;
		value =v;
		next = NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class Hashtable{
	Node<T> **table;
	int table_size;
	int current_size;

	int hashFn(string key){
		int ans = 0;
		int p = 1;
		for(int i=0;i<key.length();i++){
			ans += (key[i]*p)%table_size;
			ans = ans%table_size;
			p = (p*29)%table_size; 
		}
		return ans;
	}
	void rehash(){
		Node<T>**oldTable = table;
		int oldTableSize = table_size;
		//New Table
		table_size  =2*table_size; //Next Prime
		table = new Node<T>*[table_size];
		//Init the new table with NULL values
		for(int i=0;i<table_size;i++){
			table[i] = NULL;
		}
		current_size = 0;

		//Copy the elements from old table to new table
		for(int i=0;i<oldTableSize;i++){
			Node<T>*temp = oldTable[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			if(oldTable[i]!=NULL){
				delete oldTable[i];
			}
		}
		delete [] oldTable;
	}

public:
	Hashtable(int ds=7){
		table_size = ds;
		current_size = 0;
		table = new Node<T>*[table_size];
		//Init the table with NULL Pointers
		for(int i=0;i<table_size;i++){
			table[i] = NULL;
		}
	}
	void insert(string key,T value){
		int idx = hashFn(key);
		Node<T> *n = new Node<T>(key,value);
		n->next = table[idx];
		table[idx] = n;
		current_size++;

		float load_factor = (current_size)/float(table_size);
		if(load_factor>0.7){
			rehash();
		}
	}
	T* search(string key){
		//Pointer to the value if found else NULL
		int idx = hashFn(key);
		Node<T>* temp = table[idx];
		while(temp!=NULL){
			if(temp->key==key){
				return &(temp->value);
			}
			temp = temp->next;
		}
		return NULL;
	}

	void print(){

		//Iterate over all the buckets
		for(int i=0;i<table_size;i++){
			cout<<"Bucket "<<i<<"-->";
			Node<T>*temp = table[i];
			while(temp!=NULL){
				cout<<temp->key<<"-->";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	T& operator[](string key){
		T* f = search(key);
		if(f==NULL){
			T garbage;
			insert(key,garbage);
			f = search(key);
		}
		return *f;
	}
	void erase(string key){
		//To Do - Given the key delte that node!



	}

};

int main(){

	Hashtable<int> h;
	h.insert("Apple",60);
	h.insert("Grape",50);
	h.insert("Mango",40);
	h.insert("Guava",30);
	h.insert("Melon",22);
	h.insert("Kiwi",21);

	h.print();
	
	string fruit;
	cin>>fruit;

	int *price = h.search(fruit);
	if(price==NULL){
		cout<<fruit<<" not found!";
	}
	else{
		cout<<"Price is "<<(*price)<<endl;
	}
	//Operator Overloading
	h["banana"] = 40; //insertion
	h["banana"] = 60; //overwrite
	h["banana"] += 11; //update
	cout<<h["banana"]<<endl; //search


	return 0;
}