/*
ID: prakash35
TASK: wormhole
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 22 September 2022
PROBLEM ID      : wormhole
DESCRIPTION     : Program takes in a number of locations of wormholes and outputs the number of pairings that one would get stuck in a cycle of wormholes
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>
using namespace std;

// Number of wormholes that loop
int solution = 0;
// DFS search that goes thru every pair and checks if it works
void recur();
// Stores index of point that is on the same row as the current index
int nextxpos[13];
// Enumerates the wormhole pairs
int pairs[13];
// Number of wormholes
int N;

int main() {
  // Inputs
  ifstream cin("wormhole.in");
  // ofstream cout("wormhole.out");
  cin >> N;
  // Stores all wormholes
  pair<int, int> wormholes[N];
  for(int i = 0;i<N;i++){
    cin >> wormholes[i].first;
    cin >> wormholes[i].second;
  }
  // Set lists as -1, because default is 0 which will also be index
  for(int i = 0;i<N;i++){
    nextxpos[i] = -1;
    pairs[i] = -1;
  }
  // Find out which wormholes are to the right as Bessie travels in +x
  for(int i = 0;i<N;i++){
    for(int j = 0;j<N;j++){
      pair<int, int> curr = wormholes[i];
      pair<int, int> next = wormholes[j];
      // Check if they are on the same X and one Y is greater than other
      if(curr.first<next.first && curr.second == next.second){
        // If no other neighbor OR If current neighbor is shorter than previous neighbor
        if(nextxpos[i] == -1 || (next.first-curr.first)<(wormholes[nextxpos[i]].first-curr.first)){
          nextxpos[i] = j;
        }
      }
    }
  }
  recur();
  // Output final solution
  cout << solution << endl;
}

int numsol = 0;
// DFS Search
void recur()
{
  // Base Case: when every wormhole is matched add to solution and return
  if(numsol == N){
    // for (int start=0; start<N; start++) {
    // // does there exist a cylce starting from start
    //   int pos = start;
    //   for (int count=0; count<N; count++){
    //     pos = nextxpos[pairs[pos]];
    //   }
    //   if (pos != -1)
    //   {
    //     solution+=1;
    //   }
    // }
    solution+=1;
    return;
  }
  // go thru every possible non negative valued wormhole
  for(int i = 0;i<N;i++){
    if(pairs[i]==-1)
    {
      for(int j = 1;j<N;j++)
      {
        if(pairs[j]==-1 && j!=i)
        {
          cout << i << " " << j << endl;
          // pair wormholes, run recursion
          pairs[i] = pairs[j];
          pairs[j] = pairs[i];
          numsol+=2;
          recur();
          // unpair wormholes
          pairs[i] = -1;
          pairs[j] = -1;
          numsol-=2;
        }
      }
    }
  }
}
