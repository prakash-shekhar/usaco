/*
ID: prakash35
LANG: C++14
TASK: hamming
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 25 September 2022
PROBLEM ID      : hamming
DESCRIPTION     : Program outputs a specified number of codewords that are D hamming distance away from each other
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>
using namespace std;

int setbits(int n)
{
    int count = 0;
    while(n){
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

int main(){
	//read input
	ifstream cin("hamming.in");
	// ofstream cout("hamming.out");
	int N, B, D; cin >> N >> B >> D;
	// array of codewords
	int codewords[N+1];
	// counter used in while loop
	int counter = 2;
	// 0 can always be a codeword
	codewords[0] = 0;
	// the number we are working on

}
