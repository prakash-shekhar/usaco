// //URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=810
// //Test: 1/10
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define FRO(a) for (int i = 0; i < a; i++)
#define len(x) (int)(x).length()
void setIO(string fileName = ""){
	FastIO;
	if(len(fileName)){
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen("reststops.out", "w", stdout);
	}
}

int main(){
	setIO("2");
    int L, N, jrate, brate; cin >> L >> N >> jrate >> brate;

    //Create a vector of pairs <DistOfRS, Tastiness>
    vector<pair<int, int>> stops(N);
    for(pair<int, int>& a:stops){
        cin >> a.first >> a.second;
    }

    //sort(stops.begin(), stops.end());
    long jtime=0;
    long btime=0;
    long tottaste = 0;
    long extra=0;
    int index = 0;
    for(pair<int, int> a:stops){
        jtime=jrate*a.first;
        btime=(brate*a.first)+extra;
        tottaste += (jtime-btime)*a.second;
        extra+=(jtime-btime);
        index++;
    }
    cout << tottaste << endl;
}


// ********************
// SAMPLE SOLUTION
// ********************
// void setIO(string s) {

//     freopen((s + ".in").c_str(), "r", stdin);

//     freopen("reststops.out", "w", stdout);

// }

// int main() {

//     setIO("2");

//     long length, stops, john, bessie; cin >> length >> stops >> john >> bessie;

//     long spare_time = (john-bessie)*length;

//     map<long, long> reward_to_stop;

//     vector<long> rewards;

//     for(long i = 0; i < stops; i++) {

//         long pt, reward; cin >> pt >> reward;

//         if(reward_to_stop.find(reward) != reward_to_stop.end()) {
//
//             //For the same reward value record the later stop
//             reward_to_stop[reward] = max(pt, reward_to_stop[reward]);

//         }

//         else {

//             reward_to_stop[reward] = pt;

//         }



//         rewards.push_back(reward);

//     }

//     //Sort rewards from greatest to least
//     sort(rewards.begin(), rewards.end(), greater<long>());

//     long prev_stop = 0; long total_reward = 0; long i = 0;

//     while(i < rewards.size()) {

//         long target_reward = rewards[i];

//         long cur_stop = reward_to_stop[target_reward];

//         if(cur_stop > prev_stop) {

//             long time_taken = (john-bessie)*(cur_stop-prev_stop);

//             spare_time -= time_taken;

//             long reward_obtained = time_taken*target_reward;

//             total_reward += reward_obtained;

//             prev_stop = cur_stop;

//         }

//         i++;

//     }

//     cout << total_reward;

// }
