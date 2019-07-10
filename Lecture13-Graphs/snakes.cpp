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
	void traverseHelper(int s,bool *visited){
		cout<<s<<" ";
		visited[s] = true;

		//visit the neighbours of s and thier neighbours recursilvely
		for(int nbr:l[s]){
			if(!visited[nbr]){
				traverseHelper(nbr,visited);
			}
		}
		return;
	}
	//DFS - Depth First Search O(V+E) Linear
	void traverse(int start){
		bool *visited = new bool[V]{0};
		traverseHelper(start,visited);
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
	//Level Order Traversal - Breadth First Search(BFS) --O(V+E)
	void levelOrderTraversal(int s,int d){
		queue<int> q;
		bool *visited  = new bool[V]{0};
		int *dist = new int[V]{0};
		int *parent = new int[V];

		for(int i=0;i<V;i++){
			parent[i] = -1;
		}

		q.push(s);
		visited[s] = true;
		dist[s] = 0;

		while(!q.empty()){
			int f = q.front();
			q.pop();
			cout<<f<<",";
			//for every nbr_node which is there in adjList of f
			for(int nbr:l[f]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
					dist[nbr] = dist[f] + 1;
					parent[nbr] = f;
				}
			}
		} 

		cout<<"Shortest Path btw src and dest"<<dist[d]<<endl;
		cout<<"Path ";
		int t = d;
		while(t!=-1){
			cout<<t<<"<---";
			t = parent[t];
		}
	}
};



int main(){

	Graph g(37);

	int boardmap[50]={0};

	int l;
	cin>>l;
	int s,e;
	for(int i=0;i<l;i++){
		cin>>s>>e;
		boardmap[s] = e-s;
	}

	int snakes;
	cin>>snakes;

	for(int i=0;i<snakes;i++){
		cin>>s>>e;
		boardmap[e] = s-e;
	}

	//Graph
	for(int u=0;u<36;u++){
		for(int dice=1;dice<=6;dice++){
			int v = u + dice;
			v += boardmap[v];
			if(v<=36){
				g.addEdge(u,v,false);
			}
		}
	}
	g.levelOrderTraversal(0,36);

	return 0;
}

/*
Input
5
2 15
5 7
9 27
18 29
25 35

5
4 17
6 20
12 34
16 24
30 32
*/