#include<iostream>
#include<list>
#include<queue>
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
	int traverseHelper(int s,bool *visited){
		cout<<s<<" ";
		visited[s] = true;
		int size = 1;

		//visit the neighbours of s and thier neighbours recursilvely
		for(int nbr:l[s]){
			if(!visited[nbr]){
				size += traverseHelper(nbr,visited);
			}
		}
		return size;
	}
	//DFS - Depth First Search O(V+E) Linear
	int journeyToMoon(){
		bool *visited = new bool[V]{0};
		int ans = V*(V-1)/2;

		for(int i=0;i<V;i++){
			if(!visited[i]){

				cout<<"Component "<<endl;
				 int csize = traverseHelper(i,visited);
				 ans -= (csize)*(csize-1)/2;
				 cout<<endl;
			}
		}
		return ans;
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

	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(0,4);

	cout<<g.journeyToMoon()<<endl;


	/*
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,2);
	g.addEdge(2,3);

	g.printAdjList();
	cout<<endl;

	g.traverse(0);
	g.levelOrderTraversal(0);
	*/

	

	return 0;
}