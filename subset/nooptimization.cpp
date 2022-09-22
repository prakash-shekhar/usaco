/*
ID: prakash35
LANG: C++14
TASK: subset
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int sum = 0;
int subsetsum;
int numans = 0;


void solve(int currnum, int currsum, vector<int> curr){
	if(currsum == 0){
		numans++;
		return;
	}
	if(currnum < 1 || currsum < 0){
		return;
	}
	// cout << currnum << " " << currsum << " ";
	// for(int i:curr){
	// 	cout << i << " ";
	// }
	// cout << endl;
	solve(currnum-1, currsum, curr);
	curr.push_back(currnum);
	solve(currnum-1, currsum-currnum, curr);
}

int main(){
	//read input
	ifstream cin("subset.in");
	ofstream cout("subset.out");
	cin >> n;
	for(int i = 0;i<=n;i++){
		sum+=i;
	}
	// quit if odd sum, cant add up equally
	if((sum % 2)==1){
		cout << 0 << endl;
		exit(0);
	}
	// each subset should sum up to half of the total sum
	subsetsum = sum /2;

	solve(n, subsetsum, {});
	cout << numans / 2 << endl;
}
