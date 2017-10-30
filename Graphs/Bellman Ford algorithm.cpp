#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct graph{
    int index;
    int path=INT_MAX;
    vector<struct edge> adj;
};

struct edge{
    int source;
    int dest;
    int weight;
};

struct edgeList{
    int source;
    int dest;
    int weight;
};

void addEdge(vector<struct edgeList>& list,vector<struct graph>& graph,int source,int dest,int weight){
    struct edge temp;
    temp.source=source;
    temp.dest=dest;
    temp.weight=weight;
    graph[source].adj.push_back(temp);

    struct edgeList e;
    e.source=source;
    e.weight=weight;
    e.dest=dest;
    list.push_back(e);
}

void bellmanFord(vector<struct edgeList>& list,vector<struct graph>& graph,int start){
    graph[start].path=0;
    for(int i=0;i<graph.size();i++){

        for(int j=0;j<list.size();j++){
            int source=list[j].source;
            int dest=list[j].dest;
            int weight=list[j].weight;

            if(graph[source].path != INT_MAX && graph[dest].path>weight+graph[source].path){
                graph[dest].path=weight+graph[source].path;
            }
        }
    }

    for(int j=0;j<list.size();j++){
        int source=list[j].source;
        int dest=list[j].dest;
        int weight=list[j].weight;

        if(graph[source].path != INT_MAX && graph[dest].path>weight+graph[source].path){
            cout<<"Negative edge cycle exists. Aborting."<<endl;
            break;
        }
    }

}

int main(){

    int size=7;
    vector<struct graph> graph(size);
    vector<struct edgeList> list;
    for(int i=0;i<size;i++){
        graph[i].index=i+1;
    }

    addEdge(list,graph,0,1,4);
    addEdge(list,graph,1,3,6);
    addEdge(list,graph,1,2,-4);
    addEdge(list,graph,3,4,12);
    addEdge(list,graph,2,0,3);
    addEdge(list,graph,3,0,-9);
    addEdge(list,graph,3,5,-7);
    addEdge(list,graph,4,6,3);
    addEdge(list,graph,6,5,16);

    bellmanFord(list,graph,0);

    for(int i=0;i<graph.size();i++){
        cout<<"Index -> "<<graph[i].index<<" Distance -> "<<graph[i].path<<endl;
    }
    return 0;
}

