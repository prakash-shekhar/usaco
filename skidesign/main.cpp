/*
ID: prakash35
LANG: C++14
TASK: skidesign
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 25 September 2022
PROBLEM ID      : skidesign
DESCRIPTION     : Program takes in a number of altitudes of hills and returns the cheapest way to reduce these hills such that the max difference between altitudes is 17
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	//read input
	ifstream cin("skidesign.in");
	ofstream cout("skidesign.out");
	// number of hills
	int n; cin >> n;
	// hill height vector
	vector<int> hills;
	for(int i = 0;i<n;i++){
		int height;cin >> height;hills.push_back(height);
	}
	// sort list to make it easier
	sort(hills.begin(), hills.end());

	// costs for every possible difference of 17 between hill
	vector<int> costs;
	// go through every possible combination of difference of 17 in a hill
	for(int i = hills[0];i<=hills[n-1]-17;i++){
		// minimum and maximums for this specific hill
		int min = i; int max = i+17;
		// running cost of this hill variation
		int cost = 0;
		// go through every hill in the list
		for(int j = 0;j < n;j++){
			// if current hill is smaller than our minimum
			if(hills[j]<min){
				cost += ((min-hills[j])*(min-hills[j]));
			}
			// if current hill is bigger than out minimum
			else if(hills[j]>max){
				cost += ((hills[j]-max)*(hills[j]-max));
			}
		}
		// push back cost
		costs.push_back(cost);
	}
	// get least cost from vector
	cout << *min_element(costs.begin(), costs.end()) << endl;
}
