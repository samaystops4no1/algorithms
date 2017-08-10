#include <iostream>
#include<cmath>
using namespace std;

const int mr=7;
const int mc=7;

class location{
    public: int row=0;
    public: int column=0;
    bool operator==(location l){
        return this->row==l.row && this->column==l.column;
    }
};

class peakFinder{
    int numRows;
    int numCols;
    int startRow;
    int startCol;

    public:
    peakFinder(int r,int c,int sr,int sc){
        numRows=r;
        numCols=c;
        startRow=sr;
        startCol=sc;
    }
    void startProcess(int arr[mr][mc]);
    location getMaximum(int arr[mr][mc],int column);
    location verifyLocation(int arr[mr][mc],location l);
    void getSubproblem(int arr[mr][mc],int sub[2][2],location l);
};

void peakFinder::startProcess(int arr[mr][mc]){
    int mid=floor(this->numCols/2)+this->startCol;
    int subProblems[2][2]={{this->startCol,mid-this->startCol},
                           {mid+1,(this->numCols-mid)-1}
                           };
    location loc=getMaximum(arr,mid);
    //cout<<"Max is at "<<loc.row<<" "<<loc.column<<endl;
    location newLoc=verifyLocation(arr,loc);

    if(loc==newLoc){
        cout<<"Peak found at "<<loc.row<<" "<<loc.column<<endl;
    }
    else{
        getSubproblem(arr,subProblems,newLoc);
    }

}

location peakFinder::getMaximum(int arr[mr][mc],int column){
    int sum=0,index=0;
    for(int i=0;i<this->numRows;i++){
        if(arr[i][column]>=sum){
            sum = arr[i][column];
            index=i;
        }

    }
    location l;
    l.row=index;
    l.column=column;

    return l;
}

location peakFinder::verifyLocation(int arr[mr][mc],location l){

    if(l.column-1>=this->startCol && arr[l.row][l.column-1]>arr[l.row][l.column]){

            location newLoc;
            newLoc.row=l.row;
            newLoc.column=l.column-1;
            return newLoc;

    }
    else if(l.column+1<=(this->startCol+this->numCols)-1 && arr[l.row][l.column+1]>arr[l.row][l.column]){

            location newLoc;
            newLoc.row=l.row;
            newLoc.column=l.column+1;
            return newLoc;

    }
    else{
        return l;
    }
}

void peakFinder::getSubproblem(int arr[mr][mc],int sub[2][2],location l){
    for(int i=0;i<2;i++){
        if(l.column>=sub[i][0] && l.column<(sub[i][0]+sub[i][1])){
            peakFinder p(this->numRows,sub[i][1],this->startRow,sub[i][0]);
            p.startProcess(arr);
        }

    }
}

int main() {

    int x[mr][mc]= {
            {0, 0, 9, 8, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0},
            {0, 2, 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0, 0, 0}
    };
    peakFinder p(mr,mc,0,0);
    p.startProcess(x);

    return 0;
}