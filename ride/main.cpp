/*
ID: prakash35
LANG: C++14
TASK: ride
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 27 September 2022
PROBLEM ID      : ride
DESCRIPTION     : Check if the product of the ascii values in two strings mod 47 is the same
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
	//read input
	ifstream cin("ride.in");
	ofstream cout("ride.out");
	string s1, s2;
	cin >> s1 >> s2;
	// keep track of products
	int prod1 = 1;
	int prod2 = 1;
	//iterate through strings
	for(int i = 0;i<s1.size();i++){
		// fiddle with ascii and then multiply to running product
		prod1 *= (int) s1[i] -'A'+1;
	}
	for(int i = 0;i<s2.size();i++){
		// fiddle with ascii and then multiply to running product
		prod2 *= (int) s2[i] -'A'+1;
	}
	// print go if modulus is same
	if((prod1 % 47) == (prod2 %47)){
		cout << "GO" << endl;
	}
	else{
		cout <<"STAY" << endl;
	}
}
