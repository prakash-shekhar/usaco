/*
ID: prakash35
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int** shift90(int n, int **orig){
  int **trans90;
  trans90 = new int *[n];
  for(int i = 0; i <n; i++){
    trans90[i] = new int[n];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      trans90[j][n-1-i]=orig[i][j];
    }
  }
  return trans90;
}

int** flip(int n, int ** orig){
  int **flipped;
  flipped = new int *[n];
  for(int i = 0; i <n; i++){
    flipped[i] = new int[n];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      flipped[i][n-1-j]=orig[i][j];
    }
  }
  return flipped;
}

bool isequal(int n, int** trans, int** tmptrans){
  bool flag = true;
  for(int i =0; i < n; i++){
    for(int j =0; j < n; j++){
      if (trans[i][j] != tmptrans[i][j]){
        flag = false;
        break;
      }
    }
    if(!flag){
      break;
    }
  }
  return flag;
}

int main() {
  //filestream
  freopen("transform.in","r",stdin);
  freopen("transform.out","w",stdout);
  //variables
  int n;cin >> n;
  int **orig;int **trans;
  orig = new int *[n];
  trans = new int *[n];
  for(int i = 0; i <n; i++){
    orig[i] = new int[n];
    trans[i] = new int[n];
  };
  //input
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      char l; cin >> l;
      if(l=='@'){
        orig[i][j]=1;
      }
      else{
        orig[i][j]=0;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      char l; cin >> l;
      if(l=='@'){
        trans[i][j]=1;
      }
      else{
        trans[i][j]=0;
      }
    }
  }
  int ans = 0;
  int **trans90 = shift90(n, orig);
  if(isequal(n, trans, trans90)){
    ans = 1;
    cout << ans << endl;
    exit(0);
  }
  int **trans180 = shift90(n, trans90);
  if(isequal(n, trans, trans180)){
    ans = 2;
    cout << ans << endl;
    exit(0);
  }
  int **trans270 = shift90(n, trans180);
  if(isequal(n, trans, trans270)){
    ans = 3;
    cout << ans << endl;
    exit(0);
  }
  int **flipped = flip(n, orig);
  if(isequal(n, trans, flipped)){
    ans = 4;
    cout << ans << endl;
    exit(0);
  }
  int **fliptrans90 = shift90(n, flipped);
  int **fliptrans180 = shift90(n, fliptrans90);
  int **fliptrans270 = shift90(n, fliptrans180);
  if(isequal(n, trans, fliptrans90)||isequal(n, trans, fliptrans180)||isequal(n, trans, fliptrans270)){
    ans = 5;
    cout << ans << endl;
    exit(0);
  }
  if(isequal(n, orig, trans)){
    ans = 6;
    cout << ans << endl;
    exit(0);
  }
  else{
    ans = 7;
    cout << ans << endl;
  }
}