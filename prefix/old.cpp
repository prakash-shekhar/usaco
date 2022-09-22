/*
ID: prakash35
LANG: C++14
TASK: prefix
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	//read input
	ifstream cin("prefix.in");
	ofstream cout("prefix.out");
	// read in inputs
	vector<string> primitives;
	bool reading = true;
	while(reading){
		string p;cin >> p;
		if(p=="."){
			// reading = false;
			break;
		}
		primitives.push_back(p);
	}
	string s; cin >> s;

	//start program
	int curridx = 0;
	while(true){
		if(curridx == s.length()){
			cout << s.length() << endl;
			break;
		}
		for(int i = primitives.size()-1;i>=0;i--){
			string currprim = primitives[i];
			string currsubstr = s.substr(curridx, currprim.length());
			cout << curridx << " " << currprim << " " << currsubstr << endl;
			if(currprim ==  currsubstr){
				curridx+=currprim.length();
				break;
			}

		}
	}


}
