/*
ID: prakash35
TASK: gift1
LANG: C++                 
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

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
    cout << i << " " << len << endl;
    return i;
}


int main() {
    //initalize variable
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int numPeople;
    //read in amount of people
    fin >> numPeople;
    //create parrallel arrays
    string people[numPeople];
    long int balance[numPeople];
    for (int i = 0; i<numPeople; i++)
    {
        balance[i] = 0;
    }
    //populate people list
    for(int i=0;i<numPeople;i++){
        fin >> people[i];
    }

    while(fin){
        string giver; 
        int amount, receivers=0;
        fin >> giver;
        fin >> amount >> receivers;
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
        balance[findElem(giver, people, numPeople)]-=amount;
        balance[findElem(giver, people, numPeople)]+=remainder;
        for(int i=0; i< receivers; i++){
            string receiver;
            fin >> receiver;
            balance[findElem(receiver, people, numPeople)]+=perperson;
        }
    }
    int i = 0;
    while(i< numPeople){
        fout<< people[i] << " " <<balance[i]<<endl;
        i++;
    }
    return 0;
}