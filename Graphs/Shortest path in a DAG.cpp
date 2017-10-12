#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

class Edge{
public:
    int dest;
    int weight;
};

class node{
public:
    int index;
    int relax=0;
    vector<Edge> adj;
};

class Graph{
public:
    vector<node> graph;
    int size;
    Graph(int size){
        this->size=size;
        for(int i=0;i<size;i++){
            node temp;
            temp.index=i;
            this->graph.push_back(temp);
        }
    }
    void addEdge(int source,int dest,int weight){
        Edge e;
        e.dest=dest;
        e.weight=weight;
        this->graph[source].adj.push_back(e);
    }
};

int findShortest(Graph& g,int source,int dest){
    if(source==dest){
        return 0;
    }
    vector<int> frontier;
    frontier.push_back(source);
    while(!frontier.empty()){
        vector<int> next;
        for (int temp : frontier) {
            node n = g.graph[temp];
            for (int i = 0; i < n.adj.size(); i++) {
                auto index = n.adj[i].dest;
                auto weight = n.adj[i].weight;
                next.push_back(index);
                //relax the index here maybe
                if (g.graph[index].relax == (0)) {
                    g.graph[index].relax = n.relax + weight;
                } else if (g.graph[index].relax > (n.relax + weight)) {
                    g.graph[index].relax = n.relax + weight;
                }
            }
        }
        frontier=next;
    }
    return g.graph[dest].relax;

}

/*
 * Input Format
 * Line 1: Number of vertices(V)  Number of edges(E)
 * Next E lines: Source vertice    destination vertice    edge weight
 * Line 2+E: starting vertice    final vertice
 *
 * Output Format-
 * Single line containing the shortest path between the starting vertice and the final vertice
 *
 * Sample Input-
 * 7 8
 * 0 1 2
 * 0 2 5
 * 0 3 1
 * 3 2 1
 * 2 4 1
 * 3 6 16
 * 3 5 7
 * 1 5 4
 * 0 5
 *
 * Sample output-
 * 6
 *
 */


int main(){
    int size=0,edges=0;
    cin>>size>>edges;
    Graph g(size);
    for(int i=0;i<edges;i++){
        int source=0,dest=0,weight=0;
        cin>>source>>dest>>weight;
        g.addEdge(source,dest,weight);
    }
    int start=0,end=0;
    cin>>start>>end;
    int shortest=findShortest(g,start,end);
    cout<<shortest<<endl;
    return 0;
}

