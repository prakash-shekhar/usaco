/*
ID: prakash35
LANG: C++14
TASK: lamps
*/
#include <bits/stdc++.h>
using namespace std;

int lamps;
vector<int> finalons;
vector<int> finaloffs;


vector<bool> button1(vector<bool> curr){
	for(int i = 0;i<lamps;i++){
		curr[i] = !curr[i];
	}
	return curr;

}
vector<bool> button2(vector<bool> curr){
	for(int i = 0;i<lamps;i+=2){
		curr[i] = !curr[i];
	}
	return curr;

}
vector<bool> button3(vector<bool> curr){
	for(int i = 1;i<lamps;i+=2){
		curr[i] = !curr[i];
	}
	return curr;

}
vector<bool> button4(vector<bool> curr){
	for(int i = 0;i<lamps;i+=3){
		curr[i] = !curr[i];
	}
	return curr;

}

vector<vector<bool>> ans;
void recur(int n, vector<bool> curr, int ops){
	// if(n==ops){
	// for(bool b:curr){
	// 	cout << b;
	// }cout << endl;
	// }
	if(n>=ops){
		ans.push_back(curr);
		return;
	}
	// cout << n << endl;
	recur(n+1, button1(curr), ops);
	recur(n+1, button2(curr), ops);
	recur(n+1, button3(curr), ops);
	recur(n+1, button4(curr), ops);

}


set<vector<bool>> fixedans;
void fixans(){
	for(vector<bool> currlamps:ans){
		bool flagons = false;
		for(int j:finalons){
			if(currlamps[j-1]==false){
				flagons = true;
				break;
			}
		}
		if(flagons==true){
			continue;
		}
		bool flagoffs = false;
		for(int j:finaloffs){
			if(currlamps[j-1]==true){
				flagoffs = true;
				break;
			}
		}
		if(!flagoffs && !flagons){
			fixedans.insert(currlamps);
		}
	}
}

int main(){
	//read input
	ifstream cin("lamps.in");
	ofstream cout("lamps.out");
	cin >> lamps;
	int operations; cin >> operations;
	// read until reach -1
	int curread = 0;
	while(curread != -1){
		cin >> curread;
		finalons.push_back(curread);
	}
	finalons.pop_back();
	curread = 0;
	while(curread != -1){
		cin >> curread;
		finaloffs.push_back(curread);
	}
	finaloffs.pop_back();

	// start program
	vector<bool> init;
	for(int i=0;i<lamps;i++){
		init.push_back(1);
	}
	recur(0, init, min(operations, 4));
	fixans();
	if(fixedans.size()==0){
		cout << "IMPOSSIBLE" << endl;exit(0);
	}
	// sort(fixedans.begin(), fixedans.end(),
 //         [](const vector<bool>& a, const vector<bool>& b) {return a < b;});
	for(vector<bool> vb:fixedans){
		for(bool b:vb){
			cout << b;
		}
		cout << endl;
	}
	// cout << ans.size() << endl;
	/*
	init = vector of bools(all true) with length of n(1111111111)
	run recur(n=0, curr=init)
			base(if n=4):
				add curr to ansvector
				return
			recur(n+1, button1(curr))
			recur(n+1, button2(curr))
			recur(n+1, button3(curr))
			recur(n+1, button4(curr))
	*/

}
