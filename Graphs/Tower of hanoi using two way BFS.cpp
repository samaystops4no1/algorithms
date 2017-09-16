#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<map>

using namespace std;

/*
 * This is the solution for the game of tower of hanoi. This program calculates the minimum number of moves required to solve the game from any input configuration. 
 * To solve the puzzle we are using the two way BFS algorithms which is also known a the optimized BFS algo.
 */

struct config{
    vector<stack<int>> state;
    vector<int> total;
    struct config* parent;
};

struct node{
    int diameter;
    int rod;
};

void printList(struct config start){
    for(int i=0;i<start.state.size();i++){
        cout<<" Rod "<<i+1<<" --> ";
        int size=start.state[i].size();
        for(int j=0;j<size;j++){
            cout<<" "<<start.state[i].top();
            start.state[i].pop();
        }
    }
    cout<<""<<endl;
}

/*
 * The function insertItem inserts values into the stack inn such a way that the stack remains sorted
 */
void insertItem(stack<int>& start,int temp){
    if(start.size()==0){
        start.push(temp);
        return;
    }
    if(temp<start.top()){
        start.push(temp);
        return;
    }
    else{
        int top=start.top();
        start.pop();
        insertItem(start,temp);
        start.push(top);
    }
}

/*
 * The function compare is used to compare two structures of type node
 */
bool compare(struct node a,struct node b){
    return a.diameter<b.diameter;
}

/*
 * Used to compare structures of type config
 */
bool newCompare(struct config a,struct config b){
    return a.state[0]==b.state[0] && a.state[1]==b.state[1]&& a.state[2]==b.state[2]&& a.state[3]==b.state[3];
}

/*
 * Used to find any commong onde between any two vectors
 */

bool CheckCommon(vector<struct config> a, vector<struct config> b)
{
    return find_first_of (a.begin(), a.end(), b.begin(), b.end(),newCompare) != a.end();
}

/*
 * Return the list of element on the top of each rod.
 */
vector<struct node> onTopList(struct config start){
    vector<struct node> list;
    for(int i=0;i<start.state.size();i++){
        if(start.state[i].size()>0){
            struct node temp;
            temp.rod=i;
            temp.diameter=start.state[i].top();
            list.push_back(temp);
        }
    }
    sort(list.begin(),list.end(),compare);

    /*
    for(int i=0;i<list.size();i++){
        cout<<list[i].diameter<<" "<<list[i].rod<<endl;
    }
     */

    return list;
}

bool compareStruct(struct config a,struct config b){
    if(a.state[0]==b.state[0] && a.state[1]==b.state[1]&& a.state[2]==b.state[2]&& a.state[3]==b.state[3]){
        return true;
    }
    return false;
}

/*
 * Find and returns the value of the sum of elements in every rod multiplied by the rod no and the element on top of the rod
 */
int findSum(struct config temp){
    int sum=0;
    for(int i=0;i<temp.state.size();i++){
        if(temp.state[i].size()>0) {
            sum = sum + (temp.total[i] * (i + 1) * temp.state[i].top());
        }
        else{
            sum = sum + (temp.total[i] * (i + 1) );
        }
    }
    return sum;
}

/*
 * Perform an initial lookup to check if any element is common between two vectors
 */
bool check(vector<struct config> list,vector<int> visited){
    for(int i=0;i<list.size();i++){
        if(visited[findSum(list[i])]==1){
            return true;
        }
    }
    return false;

}

/*
 * Creates a vector containing all adjacent node to the current node and checks if our destination has been reached or not
 */

bool adjacent(struct config start,vector<struct node> rodList,vector<struct config>& next,vector<struct config>& parent,vector<struct config> others,vector<int>& changeVisit,vector<int>& bvisit){
    vector<struct config> station;
    int  j=rodList.size()-1;
    while(j>=0) {
        int rod = rodList[j].rod;
        int rno = 0;
        while (rno < 4) {
            if (start.state[rno].size()>0) {
                if (start.state[rno].top() > start.state[rod].top()) {
                    struct config temp = start;
                    int val = temp.state[rod].top();
                    temp.parent=&start;
                    temp.state[rod].pop();
                    temp.total[rod]=temp.total[rod]-val;
                    temp.state[rno].push(val);
                    temp.total[rno]=temp.total[rno]+val;
                    if(findSum(*temp.parent) != findSum(temp)) {
                        if (!compareStruct(temp, *temp.parent)) {
                            next.push_back(temp);
                            parent.push_back(temp);
                            station.push_back(temp);
                            changeVisit[findSum(temp)] = 1;
                        }
                    }

                }
            }
            else{
                struct config temp = start;
                int val = temp.state[rod].top();
                temp.parent=&start;
                temp.state[rod].pop();
                temp.total[rod]=temp.total[rod]-val;
                temp.state[rno].push(val);
                temp.total[rno]=temp.total[rno]+val;
                if(findSum(*temp.parent) != findSum(temp)) {
                    if (!compareStruct(temp, *temp.parent)) {
                        parent.push_back(temp);
                        next.push_back(temp);
                        station.push_back(temp);
                        changeVisit[findSum(temp)] = 1;
                    }
                }


            }
            rno++;
        }
        j--;
    }
    if (check(station, bvisit)) {
        if(CheckCommon(station,others)) {
            return true;
        }
        else{
            return false;
        }
    }
    else {
        return false;
    }



}


int optimizedBFS(struct config start,struct config dest){
    vector<int> fvisit(5500);
    vector<int> bvisit(5500);
    vector<struct config> frontier;
    vector<struct config> back_frontier;
    int fcount=0;
    int bcount=0;
    vector<struct config> front_list;
    vector<struct config> back_list;
    front_list.push_back(start);
    frontier.push_back(start);
    back_list.push_back(dest);
    back_frontier.push_back(dest);
    fvisit[findSum(start)]=1;
    bvisit[findSum(dest)]=1;

    int j=0;
    while(true){
        vector<struct config> next;
        if(j==0){
            j=1;
            fcount++;
            //for a forward looking move
            for(int i=0;i<frontier.size();i++) {
                struct config temp=frontier[i];
                vector<struct node> rodList=onTopList(temp);
                if(adjacent(temp,rodList,next,front_list,back_list,fvisit,bvisit)){
                    return fcount+bcount;
                }
            }
            frontier=next;

        }
        else if(j==1){
            j=0;
            bcount++;
            for(int i=0;i<back_frontier.size();i++){
                struct config temp = back_frontier[i];
                vector<struct node> rodList=onTopList(temp);
                if(adjacent(temp,rodList,next,back_list,front_list,bvisit,fvisit)){
                    return fcount+bcount;
                }
            }
            back_frontier=next;

        }


    }
    return fcount+bcount;


}

/*
 * Input Style
 * Line 1- Number of element n
 * Line 2- n space separated integer whose value signify its rod number and its position signify its diameter
 * 
 * Output Style
 * Line 1- Minimum number of steps in which the game can be solved
 * 
 * Sample Input
 * 3
 * 1 4 1
 * 
 * Sample Output
 * 3
 */

int main() {
    int rings=0;
    cin>>rings;
    struct config start;
    struct config dest;

    for(int i=0;i<4;i++){
        stack<int> entry;
        start.state.push_back(entry);
        start.total.push_back(0);
        dest.state.push_back(entry);
        dest.total.push_back(0);
    }

    for(int i=0;i<rings;i++) {
        int temp;
        cin>>temp;
        start.total[temp-1]=start.total[temp-1]+(i+1);
        insertItem(start.state[temp-1],i+1);
        dest.total[0]=dest.total[0]+(i+1);
        insertItem(dest.state[0],i+1);
    }
    if(!compareStruct(start,dest)){
        int answer=optimizedBFS(start,dest);
        cout<<answer<<endl;
    }
    else{
        cout<<0;
    }

    return 0;

}

