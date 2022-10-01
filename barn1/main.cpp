/*
ID: prakash35
TASK: barn1
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 27 September 2022
PROBLEM ID      : barn1
DESCRIPTION     : find minimum amount of stalls being blocked in order to block all occupied stalls
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  //
  ofstream fout("barn1.out");
  ifstream fin("barn1.in");
  int M, S, C; fin >> M >> S >> C;
  if(M>C){
    M=C;
  }
  vector<int> stalls;
  vector<pair<int, int>> diff;
  for(int i =0; i<C; i++){
    int snum; fin >> snum; stalls.push_back(snum);
  }
  sort(stalls.begin(), stalls.end());
  diff.push_back({0,  0});
  for(int i =0; i<C-1; i++){
    diff.push_back({stalls[i+1]-stalls[i], i+1});
  }
  sort(diff.begin(), diff.end(), greater<pair<int, int>>());
  vector<int> breaks;
  breaks.push_back(0);
  for(int i=0; i<M-1; i++){
    breaks.push_back(diff[i].second);
  }
  breaks.push_back(C);
  sort(breaks.begin(), breaks.end());
  int sum = 0;
  for(int i=0;i<M; i++){
    sum+=stalls[breaks[i+1]-1]-stalls[breaks[i]]+1;
  }
  fout << sum << endl;
}