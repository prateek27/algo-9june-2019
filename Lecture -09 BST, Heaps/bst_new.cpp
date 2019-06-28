#include<iostream>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

class Node{
public:
	int data;
	Node*left;
	Node*right;

	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};	

void levelOrderBFS(Node*root){
	queue<Node*> q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node* f = q.front();
		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<f->data<<" ";
			q.pop();

			if(f->left!=NULL){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}
	} 
}

Node* insertInBST(Node*root,int d){
	//Base Case
	if(root==NULL){
		return new Node(d);
	}
	//Rec Case
	if(d>root->data){
		root->right = insertInBST(root->right,d);
	}
	else{
		root->left = insertInBST(root->left,d);
	}
	return root;
}

istream& operator>>(istream& is, Node*&root){

	int d;
	cin>>d;
	while(d!=-1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return is;
}
ostream& operator<<(ostream&os,Node*root){
	levelOrderBFS(root);
	return os;
}

bool search(Node*root,int key){
	//base case
	if(root==NULL){
		return false;
	}
	//rec case
	
	if(root->data==key){
		return true;
	}
	if(root->data>key){
		return search(root->left,key);
	}
	return search(root->right,key);
}

Node* arrayToBST(int arr[],int s,int e){
	//Base Case
	if(s>e){
		return NULL;
	}
	//rec case
	int mid = (s+e)/2;
	Node* root = new Node(arr[mid]);
	root->left = arrayToBST(arr,s,mid-1);
	root->right = arrayToBST(arr,mid+1,e);
	return root;
}

class LLPair{
public:
	Node* head;
	Node* tail;
};

LLPair tree2LinkedList(Node*root){
	//Base Case
	LLPair l;
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}
	//Single Node
	if(root->left==NULL and root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	//Rec Case
	if(root->left!=NULL and root->right==NULL){
		LLPair LeftLL = tree2LinkedList(root->left);
		LeftLL.tail->right = root;
		l.head = LeftLL.head;
		l.tail = root;
		return l;
	}
	else if(root->right!=NULL and root->left==NULL){
		LLPair RightLL = tree2LinkedList(root->right);
		root->right = RightLL.head;
		l.head = root;
		l.tail = RightLL.tail;
		return l;
	}
	else{
		LLPair LeftLL = tree2LinkedList(root->left);
		LLPair RightLL = tree2LinkedList(root->right);
		LeftLL.tail->right = root;
		root->right = RightLL.head;
		l.head = LeftLL.head;
		l.tail = RightLL.tail;
		return l;
	}
}


Node* deleteInTree(Node*root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		//yehi vo node hai jise htana hai!
		//1. No ka koi child nahi hai - leaf node
		if(root->left==NULL and root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left!=NULL and root->right==NULL){
			Node*temp = root->left;
			delete root;
			return temp;
		}
		else if(root->right!=NULL and root->left==NULL){
			Node*temp = root->right;
			delete root;
			return temp;
		}
		else{
			// dono children hain
			// right subtree mei sabse chota element dhudo
			Node*temp = root->right;
			while(temp->left!=NULL){
				temp = temp->left;
			}
			// root pe usko daldo
			root->data = temp->data;
			root->right = deleteInTree(root->right,temp->data);
			return root;
		}

	}
	else if(root->data>key){
		root->left = deleteInTree(root->left,key);
		return root;
	}
	else{
		root->right = deleteInTree(root->right,key);
		return root;
	}

}
Node*preToBT(int *pre,int *in,int s,int e){
	static int i = 0;
	if(s>e){
		return NULL;
	}
	Node*root = new Node(pre[i]);
	//find the index of pre[i] in inorder array
	int j;
	for(j=s;j<=e;j++){
		if(pre[i]==in[j]){
			break;
		}
	}
	i++;
	root->left = preToBT(pre,in,s,j-1);
	root->right = preToBT(pre,in,j+1,e);
	return root;
}


int main(){
	Node* root=NULL;
	int pre[] = {4,2,1,3,6,5,7,8};
 	int in[] = {1,2,3,4,5,6,7,8};
 	int n = sizeof(pre)/sizeof(int);

 	root = preToBT(pre,in,0,n-1);
 	cout<<root<<endl;
	
	return 0;
}

