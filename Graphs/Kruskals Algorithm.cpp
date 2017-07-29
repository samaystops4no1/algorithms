#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    long long int start;
    long long int end;
    long long int weight;
};

void swap(long long int* a,long long int* b){
    long long int t=*a;
    *a=*b;
    *b=t;
}
void sortWeight(long long int length,struct edge* arr){

    for(int i=0;i<length;i++){
        for(int j=i+1;j<length;j++){
            if(arr[i].weight>arr[j].weight){
                //swap here
                swap(&arr[i].weight,&arr[j].weight);
                swap(&arr[i].start,&arr[j].start);
                swap(&arr[i].end,&arr[j].end);
            }
            else if(arr[i].weight==arr[j].weight){
                if(arr[i].start+arr[i].end+arr[i].weight>arr[j].start+arr[j].end+arr[j].weight){
                    swap(&arr[i].weight,&arr[j].weight);
                    swap(&arr[i].start,&arr[j].start);
                    swap(&arr[i].end,&arr[j].end);
                }
                else{
                    continue;
                }
            }
            else{
                continue;
            }
        }

    }

}

long long int fillValues(long long int* parent,long long int vertice){
    if(parent[vertice]!=vertice){
        parent[vertice]=fillValues(parent,parent[vertice]);
    }
    return parent[vertice];

}

void findUnion(long long int* parent,long long int x, long long int y){
    long long int xset=fillValues(parent,x);
    long long int yset=fillValues(parent,y);
    parent[xset]=yset;
}

void createMST(long long int city,long long int road,struct edge* arr){
    struct edge mst[city-1];
    long long int total=0;
    long long int parent[city];
    for(int i=0;i<city;i++){
        parent[i]=i;
    }

    for(int i=0;i<road;i++){
        if(total<city-1){
            long long int x=fillValues(parent,arr[i].start);
            long long int y=fillValues(parent,arr[i].end);
            if(x!=y){
                mst[total++]=arr[i];
                findUnion(parent,x,y);
            }
        }
        else{
            break;
        }
    }

    cout<<"The mst of the given graph is as follows"<<endl;
    for(int j=0;j<city-1;j++){
        cout<<"Start vertice - "<<mst[j].start<<" End Vertice - "<<mst[j].end<<" Weight - "<<mst[j].weight<<endl;
    }


}

int main() {
    
    /*INPUT TYPE
     * First Line- Two space separated integers n and m where n denotes the number of vertices and m denotes the number of edges
     * Second Line- The m lines that follow contain three space separated integers a b and c where a denotes the starting vertice, b denotes the end vertice and c denotes the weight of the edge
     */
    long long int city=0,road=0;
    cin>>city>>road;
    struct edge arr[road];
    for(int i=0;i<road;i++){
        long long int source=0,dest=0,weight=0;
        cin>>source>>dest>>weight;
        arr[i].start=source-1;
        arr[i].end=dest-1;
        arr[i].weight=weight;
    }
    sortWeight(road,arr);
    createMST(city,road,arr);
    return 0;
}
