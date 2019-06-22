#include<iostream>
using namespace std;

class Vector{
	int *arr;
	int capacity;
	int i; //current size
public:
	Vector(int n=10){
		arr = new int[n];
		capacity = n;
		i = 0;
	}
	Vector(Vector &v){
		arr = new int[v.capacity];


		for(int j=0;j<v.size();j++){
			arr[j] = v[j];
		}

		i = v.i;
		capacity = v.capacity;
	}
	void operator=(Vector &v){
		arr = new int[v.capacity];


		for(int j=0;j<v.size();j++){
			arr[j] = v[j];
		}

		i = v.i;
		capacity = v.capacity;
	}

	void push_back(int d){
		if(i==capacity){
			//double the size
			int *oldArr = arr;
			capacity = 2*capacity;
			arr = new int[capacity];

			//copy elements
			for(int j=0;j<i;j++){
				arr[j] = oldArr[j];
			}
			delete [] oldArr;
		}
		arr[i] = d;
		i++;
	}
	void pop_back(){
		if(i>0){
			i--;
		}
	}
	int size(){
		return i;
	}
	void print(){
		for(int j=0;j<size();j++){
			cout<<arr[j]<<",";
		}
	}
	int& operator[](int j){
		return arr[j];
	}
	~Vector(){ //Destructor!
		if(arr!=NULL){
			delete [] arr;
		}
	}
};

ostream& operator<<(ostream &os,Vector &v){
	v.print();
	return os;
}
istream& operator>>(istream &is,Vector &v){
	int n;
	cin>>n;
	int no;
	for(int k=0;k<n;k++){
		is>>no;
		v.push_back(no);
	}
	return is;
}

int main(){

	Vector v(5);
	cin>>v;

	//Another Vector~
	Vector v2(v) ; // or Vector v2=v; --> Copy Constructor
	Vector v3 = v2; // Copy Constructor!
	Vector v4;
	v4 = v3; //Copy Assignment Operator --> Shallow Copy

	v2.push_back(5);

	for(int i=0;i<v.size()+1;i++){
		cout<<v[i]<<"::";
	}
	cout<<endl;
	v2[0] = 100;
	cout<<v[0]<<endl;
	cout<<v2[0]<<endl;

	cout<<endl;
	v2.print();

	cout<< &v <<endl;
	cout<< &v2 <<endl;

	cout<<"Line 112"<<endl;
	cout<<v<<" "<<v2<<endl;

	
	return 0;
}