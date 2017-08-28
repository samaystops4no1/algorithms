#include <vector>
#include <iostream>
using namespace std;


bool binarySearch(int start,int stop,vector < int > a,int value){

    int mid=start+((stop-start)/2);
    if((stop-start)+1>1){
        if(value>a[mid]){
            //move to the right
            return binarySearch(mid+1,stop,a,value);
        }
        else if(value<a[mid]){
            //move to the left
            return binarySearch(start,mid-1,a,value);
        }
        else{
            //value found
            return true;
        }
    }
    else{
        if(a[mid]==value){
            return true;
        }
        else{
            return false;
        }
    }
}


int main() {
    vector<int> a={5,3,2,1,4};
    sort(a.begin(),a.end());

    if(binarySearch(0,a.size()-1,a,4)){
        cout<<"FOUND"<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }
    
    return 0;
}
