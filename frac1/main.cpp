/*
ID: prakash35
LANG: C++14
TASK: frac1
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}


struct frac{
    string strfrac;
    float val;
};

bool cmp(const frac &a, const frac &b)
{
    return a.val < b.val;
}
bool same(const frac &a, const frac &b){
    return a.val == b.val;
}

vector<frac> setfrac;

int main(){
    //input variables
    ifstream cin("frac1.in");
    ofstream cout("frac1.out");
    int N; cin >> N;
    setfrac.push_back({"0/1", 0});
    setfrac.push_back({"1/1", 1});
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<i;j++){
            float val = float(j)/float(i);
            int denom = gcd(j, i);
            string strfrac = to_string(j/denom)+ "/" + to_string(i/denom);
            setfrac.push_back({strfrac, val});
        }
    }
    sort(setfrac.begin(), setfrac.end(), cmp);
    setfrac.erase(unique(setfrac.begin(), setfrac.end(), same), setfrac.end());
    for(frac f:setfrac){
        cout << f.strfrac << endl;
    }
}