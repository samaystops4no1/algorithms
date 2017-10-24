#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
 * This algorithm can be used to find the longest common subsequence between any two given strings.
 * Example- terminator and tear have a lcs of 4
 */

long long int LCS(string a,string b,long long int m,long long int n){
    vector<vector<long long int>> map(m+1);
    for(long long int i=0;i<=m;i++){
        vector<long long int> temp(n+1);
        map[i]=temp;
    }
    long long int result=0;
    for(long long int i=0;i<=m;i++){
        for(long long int j=0;j<=n;j++){
            if(i==0 || j==0){
                map[i][j]=0;
            }
            else{
                if(a[i-1]==b[j-1]){
                    result=map[i-1][j-1]+1;
                }
                else{
                    result =max(map[i][j-1],map[i-1][j]);
                }
                map[i][j]=result;
            }

        }
    }
    return result;
}

int main() {
    string a="terminator";
    string b="tear";

    long long int answer=LCS(a,b,a.length(),b.length());
    cout<<answer<<endl;

    return 0;
}
