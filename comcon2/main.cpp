// NAMES			: Owen Su, Prakash Shekhar
// GROUP			: DM
// DATE				: OCT 4th
// PROBLEM NAME		: COMCON OCT 2007 P2

#include <bits/stdc++.h>
using namespace std;

int main(){
	string docbox = "Owen Su, Prakash Shekhar\nDM\nCOMCON OCT 2007 P2";
	cout << docbox << endl << endl;
	//read input
	ifstream cin("PROGRAM2.DAT");
	// ofstream cout("comcon2.out");

	vector<string> output;

	string alphabet = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	// create the vignere table
	char vignere[26][26];
	for(int i = 0;i<26;i++){
		for(int j = i; j<26+i;j++){
			vignere[i][j-i] = alphabet[j];
		}
	}

	for(int i = 0;i<5;i++){
		string currout = "";
		string code;
		getline(cin, code);
 		string str;
 		getline(cin, str);
 		transform(str.begin(), str.end(), str.begin(), ::tolower);
		code = code+code+code+code+code+code+code+code+code+code;
		for(int j = 0;j<str.length();j++){
			char currchar = str[j];
			if(isalpha(currchar)){
				currout += vignere[currchar-'a'][code[j] - 'a'];
			}
			else{
				currout+=currchar;
			}
		}
		cout << currout << endl;
	}


}
