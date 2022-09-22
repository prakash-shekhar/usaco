#include <bits/stdc++.h>
using namespace std;


#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define len(x) (int)(x).length()

void setIO(string fileName = ""){
	FastIO;
	if(len(fileName)){
//		freopen("10.in", "r", stdin);
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

struct Drinks {
	int t, p, m;
};

struct Sick {
	int p, t;
};

int main(){
    // Set up File IO
	setIO("6");

    // Read from File: Num Persons, Num Milk Types, Num Drinks, Num Sickness Reported
	int n, m, d, s; cin >> n >> m >> d >> s;

    // Read from File: Drinking data into vec of Drinks
	vector<Drinks> drinks(d);
	for(int i=0; i<d; i++){
		cin >> drinks[i].p >> drinks[i].m >> drinks[i].t;
		drinks[i].p--; drinks[i].m--; drinks[i].t--;
	}
    // Read from File: Sickness data into vec of Sick
    vector<Sick> sick(s);
	for(int i=0; i<s; i++){
		cin >> sick[i].p >> sick[i].t;
		sick[i].p--; sick[i].t--;
	}

    //Store index on milk drunk by person who got sick in vec of int
	vector< vector<int> > drank(n);
	for(int i=0; i<d; i++){
		for(int j=0; j<s; j++){
            //If person who got sick, drank this milk before getting sick
			if(drinks[i].p == sick[j].p && drinks[i].t < sick[j].t){
				drank[drinks[i].p].push_back(drinks[i].m);
			}
		}
	}

    //Initialize all Milk types to possibly causing sickness
	vector<bool> sickMilk(m);
	for(int milk = 0; milk < m; milk++){
		sickMilk[milk] = true;
	}

    //Check if Milk was possibly bad
	for(int milk = 0; milk < m; milk++){
		for(int person = 0; person < n; person++){
            //If Person drank any milk before getting sick
			if( drank[person].size() ){
				bool possible = false;

                // Checking if person drank this milk
				for(int a: drank[person]){
					if(a == milk){
						possible = true;
						break;
					}
				}

				//If person did not drink milk before getting sick
				//Then milk is not bad
				if(!possible){
					sickMilk[milk] = false;
				}
			}
		}
	}
    //Checking if any of the persons drank bad milk
	vector<bool> isSick(n);
	for(int milk = 0; milk < m; milk++){
		for(int i=0; i<d; i++){
			if(sickMilk[milk] && drinks[i].m == milk){
				isSick[drinks[i].p] = true;
			}
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		ans += isSick[i];
	}
	cout << ans << endl;
}

