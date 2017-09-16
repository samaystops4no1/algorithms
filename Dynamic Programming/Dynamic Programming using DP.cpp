#include <iostream>
#include<vector>
#include<stack>
#include<map>

using namespace std;
/*
 * NOTE: This program can only calculate fibonacci number for n<= 92
 */


/*
 * Normal recursive approach. Slow
 */
long long int fibonacci(int n){
    if(n<=2){
        return 1;
    }
    long long int answer=fibonacci(n-1)+fibonacci(n-2);
    return answer;
}

/*
 * Dynamic programming approach to solve fibonacci recursively
 */
long long int DPfibonacci(long long int n,map <long long int,long long int>& x){
      if(x.find(n)!=x.end()){
          return x.find(n)->second;
      }
      if(n<=2) {
          x.insert(pair <int, int> (n, 1));
          return 1;
      }
      long long int answer=DPfibonacci(n-1,x)+DPfibonacci(n-2,x);
      x.insert(pair <long long int,long long int> (n, answer));
      return answer;
}

/*
 * Dynamic programming approach to solve fibonacci using a loop
 */
long long int DPfibonacci1(long long int n,map <long long int,long long int>& x){

    for(long long int i=0;i<n+1;i++){
        long long int answer;
        if(i<=2){
            answer=1;
        }
        else{
           answer=x.find(i-1)->second+x.find(i-2)->second;
        }
        x.insert(pair <long long int,long long int> (i, answer));

    }
    return x.find(n)->second;
}

int main() {
    map <long long int,long long int> x;
    map <long long int,long long int> y;
    cout<<DPfibonacci(92,x)<<endl;
    cout<<DPfibonacci1(92,y);
    return 0;

}

