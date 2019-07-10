#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class Graph{
	list<pair<int,int> > *l;
	int V;
public:
	Graph(int V){
		this->V = V;
		l = new list<pair<int,int> >[V];
	}
	void addEdge(int u,int v,int wt,bool bidir=true){
		l[u].push_back(make_pair(v,wt));
		if(bidir){
			l[v].push_back(make_pair(u,wt));
		}
	}
	int dfsHelper(int node,bool *visited,int &ans){

		int csize=1;
		visited[node] = true;

		for(auto p:l[node]){
			int nbr = p.first;
			int wt = p.second;

			if(!visited[nbr]){
				int childSize= dfsHelper(nbr,visited,ans);
				ans += min(childSize,V-childSize)*2*wt;
				csize += childSize;
			}
		}
		return csize;
	}

	int dfs(){
		int ans = 0;
		bool *visited = new bool[V]{0};
		dfsHelper(0,visited,ans);
		return ans;
	}


};



int main(){
	
	Graph g(4);
	g.addEdge(0,1,3);
	g.addEdge(1,2,2);
	g.addEdge(2,3,2);

	cout<<g.dfs()<<endl;

	return 0;
}