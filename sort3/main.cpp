/*
ID: prakash35
LANG: C++14
TASK: sort3
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    //initialize vars
    ifstream cin("sort3.in");
    ofstream cout("sort3.out");
    int N;cin >> N;
    vector<int> inplist;
    //read in/count up
    int ct1 =0, ct2 =0, ct3 = 0;
    for(int i=0;i<N;i++){
        // Count up 1s 2s 3s
        int inp; cin >> inp;
        inplist.push_back(inp);
        if(inp==1){ct1++;}
        if(inp==2){ct2++;}
        if(inp==3){ct3++;}
    }
    // Create the right list
    vector<int> sortlist;
    for(int i=0;i<ct1;i++){sortlist.push_back(1);}
    for(int i=0;i<ct2;i++){sortlist.push_back(2);}
    for(int i=0;i<ct3;i++){sortlist.push_back(3);}
    // Count up discrepancies between inplist and sortlist
    int when12 = 0, when13 = 0, when21 = 0, when23 = 0, when31=0, when32=0;
    for(int i=0;i<N;i++){
        if(inplist[i]==1 && sortlist[i]==2){when12++;}
        else if(inplist[i]==1 && sortlist[i]==3){when13++;}
        else if(inplist[i]==2 && sortlist[i]==1){when21++;}
        else if(inplist[i]==2 && sortlist[i]==3){when23++;}
        else if(inplist[i]==3 && sortlist[i]==1){when31++;}
        else if(inplist[i]==3 && sortlist[i]==2){when32++;}
    }
    // find number of operations to solve dsicrepancies
    int operations = 0;
    //basic switches
    if(when12!=0 && when21!=0){
        if(when12>when21){
            when12 = when12-when21;
            operations += when21;
            when21 = 0;
        }
        else{ // if 21 > 12 or 21 = 12
            when21 = when21-when12;
            operations += when12;
            when12 = 0;
        }
    }
    if(when13!=0 && when31!=0){
        if(when13>when31){
            when13 = when13-when31;
            operations += when31;
            when31 = 0;
        }
        else{ // if 31 > 13 or 31 = 13
            when31 = when31-when13;
            operations += when13;
            when13 = 0;
        }
    }
    if(when23!=0 && when32!=0){
        if(when23>when32){
            when23 = when23-when32;
            operations += when32;
            when32 = 0;
        }
        else{ // if 32 > 23 or 32 = 23
            when32 = when32-when23;
            operations += when23;
            when23 = 0;
        }
    }
    //double switches
    if(when13!=0 && when21!=0 && when32!=0){
        int op = min({when13, when21, when32});
        operations += (2*op);
    }
    if(when31!=0 && when12!=0 && when23!=0){
        int op = min({when31, when12, when23});
        operations += (2*op);
    }
    cout << operations << endl;

}