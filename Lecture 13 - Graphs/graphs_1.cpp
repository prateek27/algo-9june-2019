#include<iostream>
#include<list>
using namespace std;

class Graph{
	list<int> *l;
	int V;
public:
	Graph(int v){
		V = v;
		//Array of Linked List
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool bidir=true){
		l[i].push_back(j);
		if(bidir){
			l[j].push_back(i);
		}
	}	
	void traverse(int start){
		
		
	}
	void printAdjList(){
		//Print the adj list
		for(int i=0;i<V;i++){
			cout<<i<<"->";
			for(int node:l[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}
};



int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,2);
	g.addEdge(2,3);

	g.printAdjList();

	

	return 0;
}