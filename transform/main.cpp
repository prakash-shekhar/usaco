/*
ID: prakash35
TASK: transform
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 28 September 2022
PROBLEM ID      : transform
DESCRIPTION     : given two squares of patterns, find out 1 of 8 patterns that could be utilized to transform one square to another
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>
using namespace std;

// rotate the square 90 degrees
int** shift90(int n, int **orig)
{
  int **trans90 = new int *[n];
  // initialize new square
  for(int i = 0; i <n; i++)
  {
    trans90[i] = new int[n];
  }
  // go through and rotate array
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      trans90[j][n-1-i]=orig[i][j];
    }
  }
  return trans90;
}

// flip the square
int** flip(int n, int ** orig)
{
  int **flipped = new int *[n];
  // initialize the new square
  for(int i = 0; i <n; i++)
  {
    flipped[i] = new int[n];
  }
  // go through and flip horizontally
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      flipped[i][n-1-j]=orig[i][j];
    }
  }
  return flipped;
}

// check if the the original and transformed squares are equal
bool isequal(int n, int** trans, int** tmptrans)
{
  // assume equal
  bool flag = true;
  for(int i =0; i < n; i++)
  {
    for(int j =0; j < n; j++)
    {
      // if any element is inequal break
      if (trans[i][j] != tmptrans[i][j])
      {
        flag = false;
        break;
      }
    }
    if(!flag)
    {
      break;
    }
  }
  return flag;
}

int main() {
  // initialize sources
  ofstream cout ("transform.out");
  ifstream cin ("transform.in");
  // NxN square; read in N
  int n;cin >> n;
  int **orig;int **trans;
  // initialize original and transformed square
  orig = new int *[n];
  trans = new int *[n];
  for(int i = 0; i <n; i++)
  {
    orig[i] = new int[n];
    trans[i] = new int[n];
  }
  // input the original square in
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      char l; cin >> l;
      // treat @s as 1s
      if(l=='@')
      {
        orig[i][j]=1;
      }
      // treats -s as 0s
      else{
        orig[i][j]=0;
      }
    }
  }
  // read in transformed array
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      char l; cin >> l;
      // treat @s as 1s
      if(l=='@')
      {
        trans[i][j]=1;
      }
      // treats -s as 0s
      else
      {
        trans[i][j]=0;
      }
    }
  }
  int ans = 0;
  // rotate 90 degrees
  int **trans90 = shift90(n, orig);
  // 1 if only rotated 90
  if(isequal(n, trans, trans90))
  {
    ans = 1;
    cout << ans << endl;
    exit(0);
  }
  // 2 if rotated 180(90+90)
  int **trans180 = shift90(n, trans90);
  if(isequal(n, trans, trans180))
  {
    ans = 2;
    cout << ans << endl;
    exit(0);
  }
  // 3 if rotated 270(90+180)
  int **trans270 = shift90(n, trans180);
  if(isequal(n, trans, trans270))
  {
    ans = 3;
    cout << ans << endl;
    exit(0);
  }
  // 4 if just flipped horizontally
  int **flipped = flip(n, orig);
  if(isequal(n, trans, flipped))
  {
    ans = 4;
    cout << ans << endl;
    exit(0);
  }
  // 5 if flipped and then rotated in any way
  int **fliptrans90 = shift90(n, flipped);
  int **fliptrans180 = shift90(n, fliptrans90);
  int **fliptrans270 = shift90(n, fliptrans180);
  if(isequal(n, trans, fliptrans90)||isequal(n, trans, fliptrans180)||isequal(n, trans, fliptrans270))
  {
    ans = 5;
    cout << ans << endl;
    exit(0);
  }
  // 6 if arrays are equal to each other already
  if(isequal(n, orig, trans))
  {
    ans = 6;
    cout << ans << endl;
    exit(0);
  }
  // 7 if none of the above
  else
  {
    ans = 7;
    cout << ans << endl;
  }
}