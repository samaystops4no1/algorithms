#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

struct point{
    int location;
    int parentLoc;
    int value;
    vector<struct point*> next;

};

void addEdge(vector<struct point> &list,long long int source,long long int dest){
    list[source].next.push_back(&list[dest]);
    list[dest].next.push_back(&list[source]);
}

void printStack(stack<struct point> result){
    while(result.size()>0){
        point temp=result.top();
        cout<<temp.location<<endl;
        result.pop();
    }
}


void DFSiterative(vector<point>& list,int vertices){
    int visited[vertices];
    for(int i=0;i<vertices;i++){
        visited[i]=0;
    }
    stack<struct point> frontier;
    stack<struct point> result;
    visited[0]=1;
    frontier.push(list[0]);
    while(frontier.size()>0){
        point temp=frontier.top();
        frontier.pop();
        result.push(temp);

        vector<struct point*> adj=temp.next;
        for (int i=0;i<adj.size();i++){
            if(visited[adj[i]->location]!=1){
                adj[i]->parentLoc=temp.location;
                visited[adj[i]->location]=1;
                frontier.push(*adj[i]);
            }
        }
    }
    printStack(result);
}

int main() {

    int vertices = 8;
    vector<point> list;

    //Creating some random vertices
    for (int i = 0; i < vertices; i++) {
        point temp;
        temp.location = i;
        temp.value = 100;   //some random value
        temp.parentLoc=(-1);
        list.push_back(temp);
    }

    //adding some random edges
    addEdge(list, 0, 1);
    addEdge(list, 0,2);
    addEdge(list, 1,3);
    addEdge(list, 1, 4);
    addEdge(list, 1, 5);
    addEdge(list, 6,2);
    addEdge(list, 3,7);

    //we assume the 0th node as the default starting point
    DFSiterative(list, vertices);

    return 0;

}

