/*
ID: prakash35
LANG: C++14
TASK: prefix
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // read input
  ifstream cin("prefix.in");
   ofstream cout("prefix.out");
  // read in primitives
  vector<string> primitives;
  bool reading = true;
  while (reading) {
    string p;
    cin >> p;
    if (p == ".") {
      // reading = false;
      break;
    }
    primitives.push_back(p);
  }
  sort(primitives.begin(), primitives.end(),
       [](const string &first, const string &second) {
         return first.size() > second.size();
       });
   int longestlen = primitives.back().size();
   //cout << longestlen << endl;
  // read in S
  string s = "";
  while (true) {
    string concat;
    cin >> concat;
    if (concat != "") {
      s += concat;
    } else {
      break;
    }
  }

  // generate new primitives
  // for(int i = 0;i<primitives.size();i++){
  // 	for(int j = 0;j<primitives.size();j++){
  // 		if(i!=j){
  // 			string before = primitives[i]+primitives[j];
  // 			primitives.push_back(before);
  // 		}
  // 	}
  // }

  // start program
  int curridx = 0;
  int reached = false;
  int flag = 0;
  set<int> flags;
  while (true) {
    if (curridx == s.length()) {
      reached = true;
      break;
    }
    int found = false;
    for (int i = primitives.size() - 1; i >= 0; i--) {
      string currprim = primitives[i];
      string currsubstr = s.substr(curridx, currprim.length());
      //cout << flag << " " << curridx << " " << currprim << " " << currsubstr << endl;
      flags.insert(curridx);
      if (currprim == currsubstr) {
        curridx += currprim.length();
        found = true;
        break;
      }
    }
    if (flag > 1) {
      break;
    }
    // return if no primitives possible
    if (found == false && curridx>0) {
      curridx--;
      sort(primitives.begin(), primitives.end(),
           [](const string &first, const string &second) {
             return first.size() < second.size();
           });
      flag++;
      // break;
    } else if(found ==false && curridx==0) {
    	break;
    }
    else {
      sort(primitives.begin(), primitives.end(),
           [](const string &first, const string &second) {
             return first.size() > second.size();
           });
          flag=0;
    }
    found = false;
  }
  // if reached end of list return
  if (reached == true) {
    cout << s.length() << endl;
  } else {
    cout << *flags.rbegin() << endl;
  }
}
