#include <bits/stdc++.h>

using namespace std;

struct DrnkTestStrct{
    int person;
    int milk;
    int tim;
    //override default comparator method
    bool operator < (const DrnkTestStrct& stru) const
    {
        return (tim < stru.tim);
    }
};

int main() {
    //file setup
    ofstream fout("badmilk.out");
    ifstream fin("badmilk.in");

    //read in normal milk stuff from file
    int peeps, milks, rounds, sick; fin >> peeps >> milks >> rounds >> sick;
    vector<DrnkTestStrct> DrnkTest(rounds);

    for (DrnkTestStrct& a: DrnkTest) fin >> a.person >> a.milk >> a.tim;

    //sort list by time
    //sort(DrnkTest.begin(), DrnkTest.end());

    //Read in sick testers info
    //Determine which Milk Types could have made the testers sick
    vector<pair<int, int>> sicklist;//List of <person, milk>
    set<int> badMilk; //Set of bad milk types
    vector<int> peepsicks;
    for (int i=0; i< sick; i++){
        //read in sick testers info
        int people, sicktim; fin >> people >> sicktim;
        peepsicks.push_back(people);

        //If TESTER got sick after drinking, Add the milk type to set of possibly bad milks
        //Also, Add <tester, milk> pair to sicklist
        for (DrnkTestStrct a:DrnkTest){
            if((people==a.person) && (sicktim>=a.tim)){
                badMilk.insert(a.milk);
                sicklist.push_back(make_pair(a.person, a.milk));
            }
        }
    }

    //
    vector<int> drankMilkButNotSick;
    for(int a:badMilk){
        for(int b:peepsicks){
            if(find(sicklist.begin(), sicklist.end(), make_pair(b, a)) == sicklist.end()){
                drankMilkButNotSick.push_back(a);
            }
        }
    }
    //remove milk type, if tester did not get sick
    for(int a: drankMilkButNotSick){
        badMilk.erase(a);
    }

    // for(int a:badMilk){
    //     cout << a << endl;
    // }
    // cout << endl;
    // for(auto a:DrnkTest){
    //     cout << " " << a.person << " " << a.milk << " " << a.tim << endl;
    // }

    //count up the people that drank each possible sickmilk and find the maximum amoun
    vector<bool> isSick(peeps);
    for(int a:badMilk){
        for(DrnkTestStrct b: DrnkTest){
            if(b.milk==a){
                isSick[b.person-1]= true;
            }
        }
    }
    int numSick = 0;
	for(int i=0; i<peeps; i++){
		if(isSick[i]){
		    numSick++;
		}
	}
    fout << numSick << endl;
}