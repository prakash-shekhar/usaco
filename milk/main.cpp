/*
ID: prakash35
TASK: milk
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 29 September 2022
PROBLEM ID      : milk
DESCRIPTION     : Given a requirement for milk and information on pricing and capacity for each farmer find out the minimum price for meeting the requirement
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // input streams
  ofstream fout("milk.out");
  ifstream fin("milk.in");
  // amount of milk
  int milk; fin >> milk;
  // amount of farmers
  int n; fin >> n;
  // vector for each farmers pricing
  vector<pair<int,int>> v;
  int price = 0;
  for(int i = 0; i < n; i++)
  {
      // f = price per unit in cents
      // s = amount of units
      int f, s; fin >> f >> s;
      v.push_back({f,s});
  }
  // sort the list because greedy(grrrr) algorithm
  sort(v.begin(), v.end());
  // iterate through every unit of milk
  while(milk>0)
  {
    // if current unit is at 0 remove it
    if(v[0].second==0)
    {
      v.erase(v.begin());
    }
    else
    {
      // decrement each unit
      milk--;
      v[0].second--;
      // add price of the milk to the general price
      price+=v[0].first;
    }
  }
  // output price
  fout << price << endl;
}