/*
ID: prakash35
LANG: C++
TASK: ariprog
*/

#include <bits/stdc++.h>>
using namespace std;

int a, b;
int bisq[2*251*251];

bool check(int first, int incr){
  for(int n = 0;n<a;n++){
    if(bisq[first+(n*incr)]!=1){
      return false;
    }
  }
  return true;
}


int main() {
  ifstream cin("ariprog.in");
  ofstream cout("ariprog.out");
  vector<pair<int, int>> ans;
  cin >> a >> b;
  // enumerate array
  for(int i = 0;i<=b;i++){
    for(int j = 0;j<=b;j++){
      bisq[(i*i)+(j*j)] = 1;
    }
  }
  for(int i = 0;i<=2*b*b;i++){
    for(int j = 1;j<=((2*b*b)-i)/(a-1);j++){
      if(check(i, j)){
        ans.push_back({j, i});
      }
    }
  }
  if(ans.empty()){
    cout << "NONE" << endl;
  }
  sort(ans.begin(), ans.end());
  for(auto a:ans){
    cout << a.second << " " << a.first << endl;
  }
}