//URL: http://usaco.org/index.php?page=viewproblem2&cpid=941

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

struct Node{
    vector<Node> children;
    string property;
    void add(string s){
        Node n; n.property=s;
        search = find(children.begin(), children.end(), n);
        if(search==v.end()){
            children.push_back(n);
        }
        else{
            cout << search;
        }
    }
};

int main(){
    setIO("evolution");
    int N; cin >> N;
    Node original;
    FRO(N){
        int M; cin >> M;
        vector<string> properties;
        FRO(M){
            string s; cin >> s; properties.push_back(s);
        }
        original.add(properties);
    }
}