#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

/*
Credits- @InterviewBit
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/

vector<string> textJustify(vector<string> arr,int l){
    vector<string> result;
    int words=0;
    for(int i=0;i<arr.size();i+=words){
        words=0;
        int spaces=0,charCount=0;

        while(i+words<arr.size() && charCount+spaces+arr[i+words].length()+1<=l){
            charCount+=arr[i+words].length();
            words++;
            spaces=words-1;
        }
        //cout<<charCount<<" "<<words<<" "<<spaces<<endl;
        string temp=arr[i];
        int added=0;
        for(int j=0;j<spaces;j++){
            if(i+words>=arr.size()){
                temp+=" ";
            }
            else{
                if(((l-charCount) % spaces) ==0){
                    int spaceCount=(l-charCount)/spaces;
                    for(int k=0;k<spaceCount;k++){
                        temp+=" ";
                    }
                }
                else{
                    int spaceCount=(l-charCount)/spaces;
                    int spacerem=(l-charCount)%spaces;
                    if(added<spacerem){
                        spaceCount++;
                        added++;
                    }
                    for(int k=0;k<spaceCount;k++){
                        temp+=" ";
                    }
                }
            }
            temp+=arr[i+j+1];
        }
        temp += string(l - temp.size(), ' ');
        result.emplace_back(temp);

    }

    return result;
}

int main() {
    vector<string> start={"glu", "muskzjyen", "ahxkp", "t", "djmgzzyh", "jzudvh", "raji", "vmipiz", "sg", "rv", "mekoexzfmq", "fsrihvdnt", "yvnppem", "gidia", "fxjlzekp", "uvdaj", "ua", "pzagn", "bjffryz", "nkdd", "osrownxj", "fvluvpdj", "kkrpr", "khp", "eef", "aogrl", "gqfwfnaen", "qhujt", "vabjsmj", "ji", "f", "opihimudj", "awi", "jyjlyfavbg", "tqxupaaknt", "dvqxay", "ny", "ezxsvmqk", "ncsckq", "nzlce", "cxzdirg", "dnmaxql", "bhrgyuyc", "qtqt", "yka", "wkjriv", "xyfoxfcqzb", "fttsfs", "m"};
    int l=144;
    vector<string> ans=textJustify(start,l);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
