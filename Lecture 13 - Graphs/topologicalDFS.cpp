#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> adjList;

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


int main(int argc, char const *argv[])
{
    Graph<string> g;
    g.addEdge("")
    return 0;
}
}

