/*
ID: prakash35
TASK: crypt1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
ofstream fout("crypt1.out");
ifstream fin("crypt1.in");


struct trip{
  int asum;
  int bsum;
  int tsum;
  bool valid = true;
};

vector<int> available;


bool isCalcGood(trip t){
  bool flag = true;
  int num = t.asum;
  while(num > 0) {
    int n = num%10;
    num/=10;
    if(find(available.begin(), available.end(), n) == available.end()){
      flag = false;
    }
  }
  num = t.bsum;
  while(num > 0) {
    int n = num%10;
    num/=10;
    if(find(available.begin(), available.end(), n) == available.end()){
      flag = false;
    }
  }
  num = t.tsum;
  while(num > 0) {
    int n = num%10;
    num/=10;
    if(find(available.begin(), available.end(), n) == available.end()){
      flag = false;
    }
  }
  return flag;
}


int perms(int n, vector<int> arr, int len, int L)
{
  int num = 0;
  for (int i = 0; i < L; i++) {
        num += pow(10, i) * arr[n % len];
        n /= len;
  }
    return num;
}

trip calcSums(pair<int, int> pii){
  trip t;
  t.asum = pii.first * (pii.second / ((int) pow(10, 0)) % 10);
  t.bsum = pii.first * (pii.second / ((int) pow(10, 1)) % 10);
  t.tsum = (t.bsum*10)+(t.asum);
  if(to_string(t.asum).length()!=3||to_string(t.bsum).length()!=3||to_string(t.tsum).length()!=4){
    t.valid = false;
  }
  return t;
}

vector<pair<int, int>> findperms(vector<int> arr, int len)
{
  vector<pair<int, int>> pi;
  //len^l permutations
  for (int i = 0; i < (int)pow(len, 3); i++) {
    for (int j = 0; j < (int)pow(len, 2); j++) {
        pi.push_back({perms(i, arr, len, 3), perms(j, arr, len, 2)});
    }
  }
  return pi;
}

int main() {
  int N;fin >> N;
  for(int i = 0; i < N; i++){
    int a;fin >> a; available.push_back(a);
  }
  int sol = 0;
  map<pair<int, int>, tuple<int, int, int>> used;
  for(pair<int, int> p:findperms(available, N)){
    trip sum = calcSums(p);
    if(isCalcGood(sum)&&sum.valid){
      // cout << sum.asum << ' ' << sum.bsum << ' ' << sum.tsum << " & " << p.first << ' ' << p.second << endl;
      sol++;
    }
  }
  fout << sol << endl;

}