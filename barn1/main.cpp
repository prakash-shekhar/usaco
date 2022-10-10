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
DESCRIPTION     : find minimum amount of stalls that must be blocked in order to block all occupied stalls
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  // input streams
  ofstream fout("barn1.out");
  ifstream fin("barn1.in");
  // read in max boards bought, number of stalls,
  int M, S, C; fin >> M >> S >> C;
  // the actual max boards that can be purshased is the amount of stalls
  if(M>C){
    M=C;
  }

  // vector storing all of the stall numbers
  vector<int> stalls;
  for(int i =0; i<C; i++){
    int snum; fin >> snum; stalls.push_back(snum);
  }
  sort(stalls.begin(), stalls.end());

  // vector of difference in length between the stalls: pretty much the board length
  vector<pair<int, int>> diff;
  diff.push_back({0,  0});
  for(int i =0; i<C-1; i++){
    // difference in stall, index of stall
    diff.push_back({stalls[i+1]-stalls[i], i+1});
  }
  // sort by greatest length of board
  sort(diff.begin(), diff.end(), greater<pair<int, int>>());

  //  find the length of places in between where we do NOT need boards
  vector<int> breaks;
  breaks.push_back(0);
  for(int i=0; i<M-1; i++){
    breaks.push_back(diff[i].second);
  }
  breaks.push_back(C);
  sort(breaks.begin(), breaks.end());

  // minimum amount of stalls
  int sum = 0;
  // iterate through amount boards
  for(int i=0;i<M; i++){
    // add the length between the breaks of the necessary boards(in other words find least amount of boards necessary to cover everything)
    sum+=stalls[breaks[i+1]-1]-stalls[breaks[i]]+1;
  }
  fout << sum << endl;
}