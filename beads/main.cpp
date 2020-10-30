/*
ID: prakash35
TASK: beads
LANG: C++                 
*/
#include <cstdio>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 



int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int len=0;
    fin >> len;
    string beadstr="";
    fin >> beadstr;
    beadstr+=beadstr;
    int max = 0;

    int lena=(len/2);
    int lenb=len/2;

    cout << lena << endl;
    cout << lenb << endl;

    for(int i=0; i<len; i++){
        string currstring="";
        for(int j=i; j<len+i; j++){
            currstring += beadstr[j];
        }

        int j = 0;
        bool done = false;
        bool set = false;
        char element;
        while (!done) {
            if(j > lena){
                cout << "over" << endl;
                break;
            }
            else if(currstring[j] == 'w'){
                j++;
            }
            else if (set==false) {
                set=true;
                element=currstring[j];
                j++;
            }
            else if (set==true && currstring[j]==element) {
                j++;
            }
            else {
                done=true;
            }
        }


        int ja = len-1;
        int tot = len-1;
        bool donea = false;
        bool seta = false;
        char elementa;
        while (!donea) {
            if(ja <= lenb){
                cout << "over" << endl;
                break;
            }
            else if(currstring[ja] == 'w'){
                ja--;
                tot--;
            }
            else if(seta==false && currstring[ja] == element){
                ja--;
                j++;
            }
            else if (seta==false) {
                seta=true;
                elementa=currstring[ja];
                tot--;
                ja--;
            }
            else if (seta==true && currstring[ja]==elementa) {
                tot--;
                ja--;
            }
            else {
                donea=true;
            }
        }

        if((len-1-tot)+j>max){
            max=(len-1-tot)+j;
        }
        cout << "string: " << currstring << endl;
        cout << "forward: " << j << endl;
        cout << "backward: " << len-1-tot << endl;
        cout << "total: " <<(len-1-tot)+j << endl;
    }
    fout << max << endl;
    return 0;
}