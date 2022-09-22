/*
ID: prakash35
LANG: C++14
TASK: castle
*/
#include <bits/stdc++.h>

using namespace std;

int castle[50][50];
bool visited[50][50];
int roomnum[50][50];
int roomvisited[50][50];
//number of rows and columnns
int rows, cols;
//number of rooms in a castle
int numrooms = 0;
//current room
int currval = 0;
//value of each room
map<int, int> maxroom;
//wall that will be broken
struct wall{
  int r, c;
  string direction; //either N or E
  int val; //value of two rooms conjoined
};
// vector of every wall to break
vector<wall> breaklist;


void floodfill(int r, int c){
  if(visited[r][c]==true){
    return;
  }
  visited[r][c] = true;
  roomnum[r][c] = numrooms;
  currval++;

  //get walls and doors
  int tmp = castle[r][c];
  if((tmp-8)<0){
    //move south
    floodfill(r+1, c);
  }
  else{tmp-=8;}
  if((tmp-4)<0){
    //move east(right)
    floodfill(r, c+1);
  }
  else{tmp-=4;}
  if((tmp-2)<0){
    //move north
    floodfill(r-1, c);
  }
  else{tmp-=2;}
  if((tmp-1)<0){
    //move west(left)
    floodfill(r, c-1);
  }
  else{tmp-=1;}
  return;
}

void floodbreak(int r, int c){
  if(roomvisited[r][c]==true){
    return;
  }
  roomvisited[r][c] = true;
  if(c<rows-1){
    if(roomnum[r][c]!=roomnum[r][c+1]){
      int val = maxroom[roomnum[r][c]] + maxroom[roomnum[r][c+1]];
      wall w = {r+1, c+1, "E", val};
      breaklist.push_back(w);
    }
    floodbreak(r, c+1);
  }
  if(r<cols-1){
    if(roomnum[r][c]!=roomnum[r+1][c]){
      int val = maxroom[roomnum[r+1][c]] + maxroom[roomnum[r][c]];
      wall w = {r+2, c+1, "N", val};
      breaklist.push_back(w);
    }
    floodbreak(r+1, c);
  }

}

bool cmp(const wall& x, const wall& y) {
  // return x.w < y.w;
  if(x.val==y.val){
    if(x.c == y.c){
      return x.r > y.r;
    }
    else{
      return x.c < y.c;
    }
  }
  else{
    return x.val > y.val;
  }

}


int main() {

  //read inputs in
  ifstream cin("castle.in");
  ofstream cout("castle.out");
  cin >> rows >> cols;
  for(int i = 0;i<cols;i++){
    for(int j = 0;j<rows;j++){
      cin >> castle[i][j];
    }
  }
  //start floodfill
  for(int i = 0;i<cols;i++){
    for(int j = 0;j<rows;j++){
      if(visited[i][j]==false){
        // cout << i << " " << j << endl;
        numrooms++;
        currval = 0;
        floodfill(i, j);
        maxroom.insert({numrooms, currval});
      }
    }
  }
  cout << numrooms << endl;
  cout << max_element(maxroom.begin(), maxroom.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
                })->second << endl;
//end of first two outputs
    // print room nums
  //   for(int i = 0;i<cols;i++){
  //   for(int j = 0;j<rows;j++){
  //     cout << roomnum[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  floodbreak(0, 0);
  sort(begin(breaklist), end(breaklist), cmp);
  wall s = breaklist[0];
  cout << s.val << endl;
  cout << s.r << " " << s.c << " " << s.direction << endl;



}