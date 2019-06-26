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

void mirror(Node*root){
	if(root==NULL){
		return;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}
void printRoot2Leaf(Node*root,vector<int> &v){
	if(root==NULL){
		return;
	}
	if(root->left==NULL and root->right==NULL){
		v.push_back(root->data);
		for(int x:v){
			cout<<x<<"->";
		}
		cout<<endl;
		v.pop_back();
		return;
	}
	v.push_back(root->data);
	printRoot2Leaf(root->left,v);
	printRoot2Leaf(root->right,v);
	v.pop_back();
	return;
}

class IEPair{
public:
	int inc;
	int exc;
};

IEPair maxSumIE(Node*root){
	IEPair p;
	if(root==NULL){
		p.inc = p.exc = 0;
		return p;
	}
	IEPair L,R;
	L = maxSumIE(root->left);
	R = maxSumIE(root->right);

	p.inc = root->data + L.exc + R.exc;
	p.exc = max(L.inc,L.exc) + max(R.inc,R.exc);
	return p;
}

void printAllLevels(Node*root){
	int ht = height(root);

	for(int level=0;level<=ht;level++){
		printAtLevelK(root,level);
		cout<<endl;
	}
	return;
}

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

Node* levelOrderBuild(){

	int d;
	cin>>d;
	Node* root = new Node(d);
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node*f = q.front();
		q.pop();

		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1){
			f->left = new Node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new Node(c2);
			q.push(f->right);
		}
	}

	return root;
}




int main(){
	Node*root= levelOrderBuild();
	printTree(root);
	cout<<endl;
	//printAllLevels(root);
	levelOrderBFS(root);
	/*
	cout<<endl;
	vector<int> v;
	printRoot2Leaf(root,v);
	mirror(root);
	printTree(root);
	IEPair p = maxSumIE(root);
	cout<<max(p.inc,p.exc)<<endl;
	*/
	
	return 0;
}