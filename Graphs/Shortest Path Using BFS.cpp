#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<list>
#include <queue>

using namespace std;

struct node{
    long long int dest=(-1);
};

struct vertice{
    long long int relax=0;
    long long int parent=(-1);
    long long int value=(-1);
    list<struct node> edge;
};

class Graph{
    long long int v;
    struct vertice* adj;
    public: Graph(long long int v);
    public: void addEdge(long long int source,long long int dest);
    public: void print(long long int source);
    public: void bfs(long long int source);
};

Graph::Graph(long long int v){
    this->v=v;
    adj=new struct vertice[v];
}


void Graph::addEdge(long long int v,long long int w)
{
    struct node temp;
    temp.dest=w;
    adj[v].edge.push_back(temp);
}

void Graph::print(long long int source){
    
    for(long long int i=0;i<v;i++){
        if(i!=source){
            if(adj[i].relax==0){
                cout<<-1<<" ";
            }
            else{
                cout<<adj[i].relax<<" ";
            }
        }
    }
}

void Graph::bfs(long long int source){
    long long int visited[v]={0};
    queue<long long int> q;
    q.push(source);
    adj[source].parent=(-2);
    while(q.empty()==0){
        long long int top=q.front();
        q.pop();
        if(visited[top]!=1){
            visited[top]=1;
            
            for(auto i=adj[top].edge.begin();i!=adj[top].edge.end();++i){
                if(source != i->dest && visited[i->dest]!=1 && adj[top].parent != adj[i->dest].parent){
                    if(adj[i->dest].relax>6+adj[top].relax || adj[i->dest].relax==0){
                        adj[i->dest].parent=top;
                        adj[i->dest].relax=6+adj[top].relax;
                        q.push(i->dest);
                    }
                    
                }
            }
        }
        
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        long long int road=0,city=0,start=0;
        cin>>city>>road;
        Graph g(city);
        for(int j=0;j<road;j++){
            long long int source=0,dest=0;
            cin>>source>>dest;
            g.addEdge(source-1,dest-1);
            g.addEdge(dest-1,source-1);
        }
        cin>>start;
        g.bfs(start-1);
        g.print(start-1);
        return 0;
}
