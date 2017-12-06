#include <map>
#include <queue>
#include <string>
#include <bitset>
#include <cstdio>
#include <iostream>

using namespace std;

int minimum(int a,int b,int c){
    return min(a,min(b,c));
}


//recursive approach of top-down approach
int editDistance(string a,string b,int m,int n,vector<vector<int>>& map){
    if(map[m][n]!=0){
        return map[m][n];
    }
    if(m==0){
        map[m][n]=n;
        return n;
    }
    if(n==0){
        map[m][n]=m;
        return m;
    }
    if(a[m-1]==b[n-1]){
        int ans= editDistance(a,b,m-1,n-1,map);
        map[m][n]=ans;
        return ans;
    }
    int ans=1+minimum(editDistance(a,b,m,n-1,map),editDistance(a,b,m-1,n,map),editDistance(a,b,m-1,n-1,map));
    map[m][n]=ans;
    return ans;

}

//iterative approach or bottom-up approach
int editDistanceIterative(string a,string b){
    int m=a.length();
    int n=b.length();
    vector<vector<int>> map(a.length()+1);
    for(int i=0;i<map.size();i++){
        vector<int> temp(b.length()+1);
        map[i]=temp;
    }

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                map[i][j]=j;
            }
            else if(j==0){
                map[i][j]=i;
            }
            else if(a[i-1]==b[j-1]){
                map[i][j]=map[i-1][j-1];
            }
            else{
                map[i][j]=1+minimum(map[i-1][j-1],map[i][j-1],map[i-1][j]);
            }
        }
    }
    return map[m][n];

}

int main(){
    string a="mumbai";
    string b="banglore";
    vector<vector<int>> map(a.length()+1);
    for(int i=0;i<map.size();i++){
        vector<int> temp(b.length()+1);
        map[i]=temp;
    }
    cout<<editDistance(a,b,a.length(),b.length(),map)<<endl;
    cout<<editDistanceIterative(a,b)<<endl;

    return 0;
}