#include <iostream>
#include<vector>

using namespace std;

/*
Range 0< n <75
Sample Input-> n=2
Sample Output-> x^2 + 2x +1
 */


/*
 * Dynamic programming recursive approach
 * Top Down approach or memoization
 */
long long int coefficients(long long int n,long long int k,vector<vector<long long int>>& m){
    if(m[n][k]!=0){
        return m[n][k];
    }
    if(n==k || k==0){
        return 1;
    }

    long long int coeffcient=coefficients(n-1,k-1,m)+coefficients(n-1,k,m);
    m[n][k]=coeffcient;
    return coeffcient;
}

/*
 * Dynamic programming iterative approach
 * Bottom- Up approach
 */
long long int binomial(long long int n,long long int k){
    vector<vector<long long int>> m(n+1);
    for(long long int i=0;i<n+1;i++){
        vector<long long int> temp(n+1);
        m[i]=temp;
    }
    for(long long int i=0;i<=k;i++){
        for(long long int j=i;j<=n;j++){
            if(i==j || i==0){
                m[j][i]=1;
            }
            else{
                m[j][i]=m[j-1][i-1]+m[j-1][i];
            }
        }
    }
    return m[n][k];

}

/*
 * Prints the complete binomial expansion for given value of n
 */
void printEquation(long long int n){
    vector<vector<long long int>> m(n+1);
    for(int i=0;i<n+1;i++){
        vector<long long int> temp(n+1);
        m[i]=temp;
    }
    for(int i=n;i>=0;i--){
        if(i==0){
            cout<<1;
            continue;
        }
        if(i==1){
            cout<<coefficients(n,i,m)<<"x"<<" + ";
            continue;
        }
        if(i==n){
            cout<<"x^"<<i<<" + ";
            continue;
        }
        cout<<coefficients(n,i,m)<<"x^"<<i<<" + ";
    }
}

int main() {
    int n=50;
    printEquation(n);
    return 0;

}
