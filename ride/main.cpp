/*
ID: prakash35
PROG: ride
LANG: C++                 
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

int main() {
    //initialize variables
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    int prod1=1;
    int prod2=1;

    //read strings from files
    fin >> a;
    fin >> b;

    for (int i =0; i<a.length(); i++) {
        prod1 = prod1 * (int(a[i]) - 64) % 47;
    }
    for (int i =0; i<b.length(); i++) {
        prod2 = prod2 * (int(b[i]) - 64) % 47;
    }
    if(prod1==prod2){
        fout<<"GO"<<endl;
    }
    else {
        fout<<"STAY"<<endl;
    }
    return 0;
}