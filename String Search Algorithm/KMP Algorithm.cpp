#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> makeLPS(string a){
    int len=0;
    vector<int> lps(a.length());
    lps[0]=0;
    int i=1;
    while(i<a.length()){
        if(a[len]==a[i]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;

}

vector<int> KMP(string txt,string patt,vector<int>& lps){
    int i=0;
    int j=0;
    vector<int> startIndex;
    if(txt.length()>=patt.length()) {
        while (i < txt.length()) {
            if(txt[i]==patt[j]){
                i++;
                j++;
            }
            if(j==patt.length()){
                startIndex.push_back(i-j);
                j=lps[j-1];
                continue;
            }
            else if(txt[i]!=patt[j] && j>0){
                j=lps[j-1];
            }
            else if(txt[i]!=patt[j] && j==0){
                i++;
            }
        }
        return startIndex;
    }
    else{
        return startIndex;
    }
}

int main()
{
    string text="printuuprint";
    string patt="print";
    vector<int> lps=makeLPS(patt);
    vector<int> startIndex=KMP(text,patt,lps);

    for(int i=0;i<startIndex.size();i++){
        cout<<startIndex[i]<<" ";
    }
    return 0;
}
