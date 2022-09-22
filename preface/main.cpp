/*
ID: prakash35
LANG: C++14
TASK: preface
*/
#include <bits/stdc++.h>
using namespace std;

int numeralvals[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string numerals[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
char singlenumerals[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

string gennumeral(int n){
	string retstr = "";
	for(int i = 0;i<13;i++){
		// start at M and go thru list until n = 0
		while(n!=0 && n>=numeralvals[i]){
			n -= numeralvals[i];
			//append current character to string for each iteration
			retstr += numerals[i];
		}
	}
	// cout << retstr << endl;
	return retstr;
}

int main(){
	//read input
	ifstream cin("preface.in");
	ofstream cout("preface.out");
	int n; cin >> n;
	string fullstr = "";
	//add to fullstr for every page up to n
	for(int i = 1;i<=n;i++){
		fullstr += gennumeral(i);
	}
	// count up numerals
	for(int i = 0;i<7;i++){
		int numeralct = count(fullstr.begin(), fullstr.end(), singlenumerals[i]);
		// dont print numerals that dont show up
		if(numeralct>0){
			cout << singlenumerals[i] << " " << numeralct << endl;
		}
	}
}
