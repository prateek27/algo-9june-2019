#include<iostream>
#include<cmath>
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

Node* buildTree(){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}
	Node* root = new Node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}
void printTree(Node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printTree(root->left);
	printTree(root->right);
}
void printTreeIn(Node*root){
	if(root==NULL){
		return;
	}
	printTreeIn(root->left);
	cout<<root->data<<" ";
	printTreeIn(root->right);
}

void printTreePost(Node*root){
	if(root==NULL){
		return;
	}
	printTreePost(root->left);
	printTreePost(root->right);
	cout<<root->data<<" ";
}
void printAtLevelK(Node*root,int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
}
int height(Node*root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return 1 + max(h1,h2);
}

int replaceSum(Node*root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL and root->right==NULL){
		return root->data;
	}
	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);
	int temp = root->data;
	root->data = leftSum + rightSum;
	return root->data + temp;
}

int diameter(Node *root){
	//Base Case
	if(root==NULL){
		return 0;
	}

	//Rec Case
	int op1 = height(root->left) + height(root->right);
	int op2 = max(diameter(root->left),diameter(root->right));

	return max(op1,op2);
}

class Pair{
public:
	int diameter;
	int height;
};

Pair diameter_opt(Node*root){
	Pair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}
	//rec case 
	Pair L = diameter_opt(root->left);
	Pair R = diameter_opt(root->right);

	p.height = max(L.height,R.height)+1;
	int op1 = L.height + R.height;
	int op2 = max(L.diameter,R.diameter);
	p.diameter = max(op1,op2);
	return p;
}

class HBPair{
public:
	int height;
	bool balance;
};

HBPair isHeightBalanced(Node*root){
	HBPair p;
	if(root==NULL){
		p.height = 0; 
		p.balance = true;
		return p;
	}
	//rec case
	HBPair L,R;
	L = isHeightBalanced(root->left);
	R = isHeightBalanced(root->right);

	p.height = max(L.height,R.height)+1;
	p.balance = false;
	if(L.balance and R.balance and abs(L.height-R.height)<=1){
		p.balance = true;
	}
	return p;

}


int main(){
	Node*root=buildTree();
	replaceSum(root);
	printTree(root);
	if(isHeightBalanced(root).balance){
		cout<<"yes it is height balanced!";
	}
	return 0;
}