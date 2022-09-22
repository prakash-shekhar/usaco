/*
ID: prakash35
LANG: C++14
TASK: subset
*/
#include <bits/stdc++.h>
using namespace std;


/*
TODO:
add memoization and DP(done)
*/

int sum = 0;
int subsetsum;
// max array vals when n = 39(actually just a bit over to be safe :))
int visited[800][40];


int solve(int currnum, int currsum){
	// base cases
	// stop when numbers go negative
	if(currnum < 0 || currsum < 0){
		return 0;
	}
	// if already visited return from array
	if(visited[currsum][currnum]!=-1){
		return visited[currsum][currnum];
	}
	// increment num answers if sum is 0
	if(currsum == 0 && currnum == 0){
		return 1;
	}

	// add both branches of currnum
	return visited[currsum][currnum] = solve(currnum-1, currsum) + solve(currnum-1, currsum-currnum);
}

int main(){
	//read input
	ifstream cin("subset.in");
	ofstream cout("subset.out");
	int n;cin >> n;
	for(int i = 0;i<=n;i++){
		sum+=i;
	}

	// quit if odd sum, cant add up equally
	if((sum % 2)==1){
		cout << 0 << endl;
		exit(0);
	}

		// make everything in visited -1, so the DP will actually work
	for(int i = 0; i < 800; i++)
	{
    	for(int j = 0; j < 40; j++)
    	{
    		visited[i][j] = -1;
    	}
	}

	// each subset should sum up to half of the total sum
	subsetsum = sum /2;

	// run recursive funtion
	// bcos of repeating sets, divide by n! or 2!=2 in this case
	cout << solve(n, subsetsum) /2 << endl;
}
