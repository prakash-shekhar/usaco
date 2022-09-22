#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define FRO(a) for (int i = 0; i < a; i++)
#define len(x) (int)(x).length()

using namespace std;

void setIO(string fileName = ""){
	FastIO;
	if(len(fileName)){
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

const int N=6;
bool visited[N][N] = {0};
int visit(int ii, int jj, int numNodes)
{
	int count = 0;
	if(ii == N-1 && jj == N-1)
	{
		if (numNodes == 2*(N-1))
			return 1;
		else
			return 0;
	}
	else if(ii < 0 || ii > N-1 || jj < 0 || jj > N-1 || visited[ii][jj]  )
		return 0;
	else{
		visited[ii][jj]=true;
		count += visit(ii-1, jj, numNodes+1);
		count += visit(ii+1, jj, numNodes+1);
		count += visit(ii, jj-1, numNodes+1);
		count += visit(ii, jj+1, numNodes+1);
		visited[ii][jj]=false;
	}
	return count;
}

int main(){
//    setIO("");

	int size;
	cout << "GRID SIZE :" << N << endl;
	cout << "Number of Paths : ";
	cout << visit(0,0,0) << endl;
	


}