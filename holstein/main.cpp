/*
ID: prakash35
LANG: C++14
TASK: holstein
*/
#include <bits/stdc++.h>
using namespace std;


int V; // num vitamins, max: 25, test: 4
int G; // num feeds, max: 15, test: 3
int required[25]; // array of required vitamins, max:25 vitamins
int feeds[15][25]; // array of feeds, max:15 feeds

int tempfeeds[15];//current feeds

vector<pair<int, vector<int>>> possol; // vector of possible solutions

void check(int sizmix, vector<int> mixture){
    int tempreq[25];
    // copy required to temp array
    for(int i = 0;i<V;i++){
        tempreq[i] = required[i];
    }
    // go through each feed in mixture
    for(int i = 0;i<sizmix;i++){
        // go through each vitamin in feed and remove from temp list
        for(int j = 0;j<V;j++){
            tempreq[j] -= feeds[mixture[i]][j];
        }
    }
    //add to possol if negative values(possible solution)
    bool flag = 0;
    for(int j = 0;j<V;j++){
        if(tempreq[j]>0){
            flag = 1;
            break;
        }
    }
    if(!flag){
        possol.push_back(make_pair(sizmix, mixture));
        return;
    }
}


int main(){
    //read feeds in
    ifstream cin("holstein.in");
    ofstream cout("holstein.out");
    cin >> V;
    for(int i=0;i<V;i++){
        cin >> required[i];
    }
    cin >> G;
    for(int i=0;i<G;i++){
        for(int j=0;j<V;j++){
            cin >> feeds[i][j];
        }
    }


    //generate all possible permutations for a mixture
    int nummix = pow(2, G);
    //iterate through permutations
    for(int i = 1;i<nummix;i++){
        string bitstring = bitset<16>(i).to_string();
        int idx = 0;
        int sizmix = 0;
        vector<int> mixture;
        // if bitstring has 1, "turn on" the feed
        for(int j = 15;j>15-G;j--){
            // cout << idx << " " << bitstring[j]<< endl;
            if(bitstring[j]=='1'){
                sizmix++;
                mixture.push_back(idx);
            }
            idx++;
        }
        //check permutation
        check(sizmix, mixture);
    }


    // for(pair<int, vector<int>> p:possol){
    //     cout << p.first << endl;
    //     for(int s:p.second){
    //         cout << s << " ";
    //     }
    //     cout << endl;
    //     cout << endl;
    // }

    // find best solution
    sort(possol.begin(), possol.end());
    // print num of feeds in mixture
    cout << possol[0].first << " ";
    //funky printing stuff cos usaco grader
    cout << possol[0].second[0]+1;
    for(int i=1;i<possol[0].second.size();i++){
        cout << " " << possol[0].second[i]+1;
    }
    cout << endl;

}