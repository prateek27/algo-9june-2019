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
	cin>>data;
	while(data!=-1){
		insertAtHead(head,data);
		cin>>data;
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

//Linear Time Complexity
Node* merge(Node*a,Node*b){
	//base 
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	Node*c; //just a pointer
	if(a->data<b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c= b;
		c->next = merge(a,b->next);
	}
	return c;
}

Node* midpoint(Node *l){
	Node* slow = l;
	Node* fast = l->next;

	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


Node* mergeSort(Node* l){
	//base case
	if(l==NULL or l->next==NULL){
		return l;
	}
	//Recursive Case
	Node* m = midpoint(l);
	Node *a = l;
	Node *b = m->next;
	m->next = NULL; //break into two parts

	a = mergeSort(a);
	b = mergeSort(b);
	return merge(a,b);
}

pair<Node*,int> addLL(Node *a,Node *b){
	pair<Node*,int> p;
	if(a==NULL and b==NULL){
		p.first = NULL;
		p.second = 0;
		return p; 
	}
	//Rec case
	p = addLL(a->next,b->next);
	int carry = p.second;
	Node* aageKiList = p.first;

	int sum = a->data + b->data + carry;
	Node*n = new Node(sum%10);
	n->next = aageKiList;

	p.second = sum/10;
	p.first = n;
	return p;
}


int main(){
	Node*head1 = NULL;
	Node*head2 = NULL;
	cin>>head1>>head2;
	cout<<head1<<head2;
	//head = mergeSort(head);
	
	pair<Node*,int> p = addLL(head1,head2);
	Node*head3 = p.first;
	cout<<head3<<endl;
	//handle if carry


	
	return 0;
}