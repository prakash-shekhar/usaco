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

int button1(int num){

    // Inverting every bit
    for (int i = 0; i < lamps; i++)
       num = (num ^ (1 << i));

    return num;
}

int button2(int num){

    // Inverting the odd bits(1,3,5,7)
    for (int i = lamps-2; i >= 0; i-=2)
       num = (num ^ (1 << i));

    return num;
}

int button3(int num){

    // Inverting the even bits(2,4,6,8)
    for (int i = lamps-1; i >= 0; i-=2)
       num = (num ^ (1 << i));

    return num;
}

int button4(int num){

    // Inverting the 1*3n bits (1,4,7,10)
    for (int i = lamps-1; i >=0; i-=3){
    	num = (num ^ (1 << i));
    }

    return num;
}

string printout(int i){
		string bitstr = bitset<100>(i).to_string();
		string strbuild = "";
		for(int j = lamps;j>0;j--){
			char currbit = bitstr[100-j];
			// for(int on:finalons){
			// 	if(on-1 == lamps-j && currbit==0){
			// 		return "";
			// 	}
			// }
			// for(int off:finaloffs){
			// 	if(off-1 == lamps-j && currbit=='1'){
			// 		return "";
			// 	}
			// 	// cout << off-1 << " " << lamps-j << " " << currbit;
			// }
			// cout << endl;
			strbuild+=currbit;
		}
		return strbuild;
}


set<int> ans;
int recur(int n, int val){
	if(n<=0){
		return val;
	}
	else{
		int but1 = recur(n-1, button1(val));
		cout << but1 << " " << printout(but1)<< endl;
		ans.insert(but1);
		int but2 = recur(n-1, button2(val));
		cout << but2 << " " << printout(but2) << endl;
		ans.insert(but2);
		int but3 = recur(n-1, button3(val));
		cout << but3 << " " << printout(but3) << endl;
		ans.insert(but3);
		int but4 = recur(n-1, button4(val));
		cout << but4 << " " << printout(but4) << endl;
		ans.insert(but4);
		return 0;
	}
}


int main(){
	//read input
	ifstream cin("lamps.in");
	// ofstream cout("lamps.out");
	cin >> lamps;
	int operations; cin >> operations;
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
	// decimal: ((2^lamps)-1), binary: 111..(lamp amt)
	int init = (1<<lamps)-1;
	// cout << button1(button4(button2(button3(button2(button3(init)))))) << endl;
	// cout << button1(button3(button4(init))) << endl;
	// cout << button4(button3(button1(init))) << endl;

	ans.insert(recur(operations, init));
	bool flag = true;
	// sort(ans.begin(), ans.end());
	for(int i:ans){
		string p = printout(i);
		if(p!=""){
			flag = false;
			cout << p << endl;
		}
	}
	if(flag){
		cout << "IMPOSSIBLE" << endl;
	}
}
