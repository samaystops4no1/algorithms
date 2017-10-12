#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct front{
    int relax=INT_MAX;
    int index;
};

class Edge{
public:
    int dest;
    int weight;
};

class node{
public:
    int index;
    int relax=INT_MAX;
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

struct front findMin(vector<struct front>& frontier){
    struct front min;
    min.relax=INT_MAX;
    for(int i=0;i<frontier.size();i++){
        if(frontier[i].relax<min.relax && frontier[i].relax>=0){
            min.relax=frontier[i].relax;
            min.index=frontier[i].index;
        }
    }
    frontier[min.index].relax=(-1);
    return min;
}


void djikstras(Graph& g,int source,int dest){
    vector<struct front> frontier(g.size);
    g.graph[source].relax=0;
    struct front t;
    t.relax=0;
    t.index=source;
    frontier[source]=t;
    int count=0;

    while(count<g.size){
        struct front min=findMin(frontier);
        int relax=min.relax;
        int index=min.index;
        node temp=g.graph[index];
        for (auto &i : temp.adj) {
            int ci= i.dest;
            int cw= i.weight;
            if(g.graph[ci].relax> relax+cw && frontier[ci].relax>=0){
                g.graph[ci].relax=relax+cw;
                struct front xam;
                xam.index=ci;
                xam.relax=relax+cw;
                frontier[ci]=xam;
            }
        }
        count++;
    }

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
 * 9 11
 * 0 1 3
 * 1 2 6
 * 2 3 7
 * 3 0 4
 * 2 8 13
 * 3 4 11
 * 4 5 1
 * 5 7 2
 * 7 4 4
 * 4 6 3
 * 8 1 5
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

    djikstras(g,0,size-1);
    for(int i=0;i<g.size;i++){
        cout<<"Index "<<i<<"  Shortest path "<<g.graph[i].relax<<endl;
    }
    return 0;
}
