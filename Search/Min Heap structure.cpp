#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/*
* Functions available
* 1. insert( value )
* 2. extract_min()
*/

class MinHeap{
private:
    vector<int> values;

    void build_min_heap(){
        int size=this->values.size();
        for(int i=(size/2)-1;i>=0;i--){
            this->min_heapify(i);
        }
    }

    void min_heapify(int index){
        if(this->values.size()<=0){
            return;
        }
        if(index>=this->values.size()){
            cout<<"The indices you requested do not exist. MIN_HEAP error"<<endl;
            return;
        }
        int size=this->values.size();
        int current_index=index;
        while(current_index<(size/2)){
            int left_index=((current_index+1)*2)-1;
            int right_index=2*(current_index+1);
            int min_index_value=left_index;
            if(right_index<size) {
                min_index_value = (this->values[left_index] < this->values[right_index]) ? (left_index) : (right_index);
            }
            if(this->values[current_index]>this->values[min_index_value]){
                //we need to swap
                this->swap(current_index,min_index_value);
                current_index=min_index_value;
            }
            else{
                break;
            }
        }
    }

    void swap(int indexa,int indexb){
        if(indexa>=this->values.size() || indexb>=this->values.size()){
            cout<<"The indices you requested do not exist. Swap error"<<endl;
            return;
        }
        int temp=this->values[indexa];
        this->values[indexa]=this->values[indexb];
        this->values[indexb]=temp;
    }

public:
    void insert(int value){
        this->values.push_back(value);
        this->build_min_heap();
    }

    int extract_min(){
        if(this->values.size()<=0){
            return (-1);
        }
        int min_value=this->values[0];
        this->swap(0,this->values.size()-1);
        this->values.pop_back();
        this->min_heapify(0);
        return min_value;

    }

};

int main(){
    MinHeap a;
    a.insert(0);
    a.insert(24);
    a.insert(3);
    a.insert(78);
    a.insert(1);
    a.insert(13);
    cout<<a.extract_min()<<endl;
    cout<<a.extract_min()<<endl;
    return 0;
}



