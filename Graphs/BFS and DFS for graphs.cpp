#include <map>
#include <queue>
#include <string>
#include <bitset>
#include <fstream>
#include <iostream>

using namespace std;

void addEdge(vector<int> list[],int source,int dest){
    list[source].push_back(dest);
    list[dest].push_back(source);
}

void BFS(vector<int> list[],int start,int vertices){
    vector<int> frontier;
    frontier.push_back(start);
    int visited[vertices];
    visited[start]=1;
    //initialize the visited array here

    while(frontier.size()!=0){
        vector<int> next;
        for(int j=0;j<frontier.size();j++) {
            int temp = frontier[j];
            for (int i = 0; i < list[temp].size(); i++) {
                int t = list[temp][i];
                if (visited[t] != 1) {
                    cout << t << endl;
                    visited[t] = 1;
                    next.push_back(t);
                }
            }
        }
        frontier=next;
    }
}

void dfsVisit(vector<int> list[],vector<int> adj,int *visited){
    for(int i=0;i<adj.size();i++){
        if(visited[adj[i]]!=1){
            visited[adj[i]]=1;
            cout<<adj[i]<<endl;
            dfsVisit(list,list[adj[i]],visited);
        }
    }
}

void DFS(vector<int> list[],int start,int vertices){
    int visited[vertices];
    for(int j=0;j<vertices;j++){
        visited[j]=0;
    }

    for(int i=0;i<vertices;i++){
        if(visited[i]!=1){
            cout<<i<<endl;
            visited[i]=1;
            dfsVisit(list,list[i],visited);
        }
    }
}

int main(){
    int vertices=8;
    vector<int> list[vertices];
    addEdge(list,0,1);
    addEdge(list,0,2);
    addEdge(list,1,3);
    addEdge(list,2,5);
    addEdge(list,2,3);
    addEdge(list,3,4);
    addEdge(list,6,7);
    cout<<"BFS implementation"<<endl;
    BFS(list,0,vertices);
    cout<<"DFS implementation"<<endl;
    DFS(list,0,vertices);
    return 0;

}
