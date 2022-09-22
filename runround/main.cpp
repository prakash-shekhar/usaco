/*
ID: prakash35
LANG: C++14
TASK: runround
*/
#include <bits/stdc++.h>
using namespace std;

// check if runaround
int runaround(int n){
	string strn = to_string(n);


	vector<char> visited;
	for(char charn:strn){
		// check that all digits are 0
		if(charn == '0'){
			return 0;
		}
		// check for repitition
		for(char v:visited){
			if(charn == v){
				return 0;
			}
		}
		visited.push_back(charn);
	}

	// make biggest string for problem
	string bigstr = "";
	for(int i = 0;i<81;i++){
		bigstr+=strn;
	}

	int jump = 0;
	int idx = 0;
	vector<char> seen;
	for(int i = 0;i<strn.size();i++){
		// check that each digit is encountered at least once
		for(char s:seen){
			if(s == bigstr[idx]){
				return 0;
			}
		}
		seen.push_back(bigstr[idx]);
		jump = ((int) bigstr[idx] - 48);
		idx += jump;
	}
	// check if it actually runs around(goes to first digit)
	if(bigstr[idx]!=strn[0]){
		return 0;
	}
	// cout << bigstr[idx] << endl;


	return 1;
}

int main(){
	//read input
	ifstream cin("runround.in");
	ofstream cout("runround.out");
	int m;cin >> m;
	int ans = m+1;
	// keep incrementing ans until a runaround number is found
	while(runaround(ans) != 1){
		ans++;
		runaround(ans);
	}
	cout << ans << endl;

}
