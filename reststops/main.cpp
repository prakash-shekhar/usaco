// //URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=810
// //Test: 3/10
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define FRO(a) for (int i = 0; i < a; i++)
#define len(x) (int)(x).length()
void setIO(string fileName = ""){
	FastIO;
	if(len(fileName)){
		freopen((fileName+".in").c_str(), "r", stdin);
		fopen("reststops.out", "w");
	}
}

bool tastefirst(pair<int, int> p1, pair<int, int> p2) {
    bool retVal = p1.second<p2.second;
    if(p1.second==p2.second){
        retVal = p1.first<p2.first;
    }
    return retVal;
}

int main(){
	setIO("4");
    int L, N, jrate, brate; cin >> L >> N >> jrate >> brate;

    //Create a vector of pairs <DistOfRS, Tastiness>
    vector<pair<int, int>> stops(N);
    for(pair<int, int>& a:stops){
        cin >> a.first >> a.second;
    }
    int laststop = stops.back().first;
    int maxtaste = 0;
    long long tottaste = 0;
    long long oldjtime = 0;
    long long extra=0;
    while(stops.size()!=0){
        maxtaste = max_element(stops.begin(), stops.end(), tastefirst)-stops.begin();
        pair<int, int> a=stops[maxtaste];
        long long jtime=jrate*a.first;
        long long btime=(brate*a.first)+extra;
        tottaste += (jtime-btime)*a.second;
        extra+=(jtime-btime);
        // cout << a.first <<" " << a.second << " " << jtime << " " << btime << " " << tottaste << endl;
        stops.erase(next(stops.begin(), 0), next(stops.begin(), maxtaste+1));
    }
    cout << tottaste << endl;
}