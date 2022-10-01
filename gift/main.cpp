/*
ID: prakash35
TASK: gift1
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 27 September 2022
PROBLEM ID      : gift1
DESCRIPTION     : Given a list of names and sequential transfers of money, determine the amount transfered by each member in the group
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>

using namespace std;

int findElem(string elem, string arr[], int len){
    int i = 0;
	while (i < len)
	{
		if (arr[i] == elem) {
			break;
		}
		i++;
	}
    // cout << i << " " << len << endl;
    return i;
}


int main() {
    //initalize variable
    ofstream cout ("gift1.out");
    ifstream cin ("gift1.in");
    int numPeople;
    //read in amount of people
    cin >> numPeople;
    //create parrallel arrays
    string people[numPeople];
    long int balance[numPeople];
    // set array of values to 0
    for (int i = 0; i<numPeople; i++)
    {
        balance[i] = 0;
    }
    // populate people list
    for(int i=0;i<numPeople;i++){
        cin >> people[i];
    }
    // read until end of file
    while(cin){
        // read in current operation
        string giver;
        int amount, receivers=0;
        cin >> giver;
        // make sure to break if giver name is empty
        if(giver == ""){
            break;
        }
        cin >> amount >> receivers;
        // calculate amount that each receiver will get
        int perperson;
        int remainder;
        if (receivers==0) {
            remainder = 0;
            perperson = 0;
        }
        else{
            perperson = amount / receivers;
            remainder = amount % receivers;
        }
        // adjust balance of the giver
        int giverbal = distance(people, find(people, people+numPeople, giver));
        balance[giverbal]-=amount;
        balance[giverbal]+=remainder;
        // adjust balance of the receivers
        for(int i=0; i< receivers; i++){
            string receiver;
            cin >> receiver;
            int receiverbal = distance(people, find(people, people+numPeople, receiver));
            balance[receiverbal]+=perperson;
        }
    }
    // output person and balance
    for(int i = 0;i<numPeople;i++){
        cout << people[i] << " " <<balance[i]<<endl;
    }
    return 0;
}