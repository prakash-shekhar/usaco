/*
ID: prakash35
LANG: C++14
TASK: subset
*/
#include <bits/stdc++.h>

using namespace std;

//Full array init
int arr[791][40];

//Adds all the ways in which numbers up until num can make total
int solve(int total, int num)
{
  //cout << "231" << endl;
  //cout << num << " init " << total << " " << arr[total][num]<< endl;

  //Return 0 if it exits the bounds of possible
  if (num < 0 || total < 0)
  {
    //cout << num << " less than zero " << total << " " << arr[total][num]<< endl;
    return 0;
  }

  //Don't recalculate
  if (arr[total][num] != -1)
  {
    //cout << total << " done " << num << " " << arr[total][num] << endl;
    return arr[total][num];
  }

  //Perfect Fits
  if (total == 0 && num == 0)
  {
    //cout << num << "  edge " << total << " " << arr[total][num]<< endl;
    //cout << "234" << endl;
    return 1;
  }

  //Calculate ways
  arr[total][num]=solve(total, num - 1) + solve(total - num, num - 1);
  //cout << num << " fin " << total << " " << arr[total][num]<< endl;
  return arr[total][num];
}

int main()
{
  //Opens input and output files
  ofstream fout("subset.out");
  ifstream fin("subset.in");
  //cout << "first" << endl;

  //Declares
  int num, ways = 0;

  //Inputs
  fin >> num;
  int tot  = (num*(num+1))/2;
  int sums = 0;

  //Initialize
  for(int x = 0; x <= tot; x++)
  {
    for(int y = 0; y <= num; y++)
    {
      arr[x][y] = -1;
    }
  }




  //Impossible cases
  if(tot % 2 != 0)
  {
    fout << 0 << endl;
    return 0;
  }





  //Generates Subsets
  //fout << tot/2 << " " << num << endl;

  //fout << solve(751,38) << endl;
  long long fint = solve(tot/2 - num, num-1);
  cout << fint << endl;
  long long fint2 = solve(tot/2, num-1);
  //cout << fint2 << endl;
  fout <<    (fint+fint2) /2 << endl;

  for(int x = 1; x <= tot/2; x++)
  {
    for(int y = 1; y < num; y++)
    {
      cout << arr[x][y] << " ";
    }
    cout << endl;
  }


  return 0;
}