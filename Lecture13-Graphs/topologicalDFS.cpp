#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T> > adjList;

public:
    Graph(){
    }
    void addEdge(T u,T v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void print(){
        for(T i:adjList){
            cout<<i.first<<"-->";
            for(T entry:i.second){
                cout<<entry<<", ";
        }
        cout<<endl;
    }
}

    void dfs(T node,map<T, bool> &visited,list<T> &order){   
        visited[node] = true;
        for (auto i: adjList[node])
        {
            if(!visited[i]){
                dfs(i, visited, order);
            }
        }
        order.push_front(node);        
    }

    void dfsTopological(){
        map<T, bool> visited;
        list<T> order;
        for (auto i: adjList)
        {
            visited[i.first] = false;
        }
        for (auto i: adjList)
        {
            T node = i.first;
            if(!visited[node]){
                dfs(node, visited, order);
            }
        }

        for (auto i:order)
        {
            cout<<i<<endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph<string> g;
    g.addEdge("C++","comp",false);
    g.addEdge("C++","ML",false);
    g.addEdge("ML","android",false);
    g.addEdge("comp","web",false);
    g.addEdge("comp","android",false);
    g.addEdge("web","python",false);
    g.dfsTopological();


    return 0;
}


