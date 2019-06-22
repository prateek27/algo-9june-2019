#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;
	//Constructor with Init List
	Node(int d):data(d),next(NULL){}
	~Node(){

		cout<<"Deleting "<<data<<" ";
		if(next!=NULL){
			delete next;
		}
	}
};

void insertAtHead(Node*&head,int d){
	if(head==NULL){
		head = new Node(d);
		return;
	}
	Node *n = new Node(d);
	n->next = head;
	head = n;
}
void insertInMiddle(Node*&head,int d,int p){
	if(p==0){
		insertAtHead(head,d);
		return;
	}
	Node*temp = head;
	for(int jump=1;jump<=p-1;jump++){
		temp = temp->next;
	}
	Node*n = new Node(d);
	n->next = temp->next;
	temp->next = n;
	return;
}
void print(Node*head){

	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
}

istream& operator>>(istream &is,Node*&head){
	int data;
	while(scanf("%d",&data)!=EOF){
		insertAtHead(head,data);
	}
	return is;
}
ostream& operator<<(ostream &os,Node*head){
	print(head);
	cout<<endl;
	return os;
}
void deleteInMiddle(Node*&head,int p){
	if(p==0){
		Node*temp = head->next;
		head->next = NULL;
		delete head;
		head = temp;
	}
	Node*temp = head;
	Node*prev = NULL;
	for(int jump=1;jump<=p;jump++){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	temp->next = NULL;
	delete temp;
}

int search_rec(Node*head,int key){
	//Rec Search
	if(head==NULL){
		return -1;
	}
	//rec case
	if(head->data==key){
		return 0;
	}

	int aageKaAns =  search_rec(head->next,key);
	if(aageKaAns==-1){
		return -1;
	}
	return aageKaAns +1;
}

Node* reverse_rec(Node*head){
	//Rec Reverse
	if(head->next==NULL){
		return head;
	}
	//rec case
	Node*chotaHead = reverse_rec(head->next);
	/*
	Node*temp = chotaHead;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	*/
	head->next->next = head;
	head->next =NULL;
	return chotaHead;
}
void reverse(Node*&head){
	//Iterative Reverse
	Node* prev = NULL;
	Node* current = head;
	Node* N = current->next;

	while(current!=NULL){
		N = current->next;
		current->next = prev;
		prev = current;
		current = N;
	}
	head = prev;
}




int main(){
	Node*head = NULL;
	cin>>head;
	insertInMiddle(head,3,2);
	cout<<head;
	head = reverse_rec(head);
	cout<<head<<endl;
	reverse(head);
	cout<<head<<endl;

	//delete head;

	return 0;
}