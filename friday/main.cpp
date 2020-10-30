/*
ID: prakash35
TASK: friday
LANG: C++                 
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getMonthLen(int month, int year){
    switch (month) {
        case 1 : case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10 :
        case 12 :
        return 31;
        case 2 :
        if (( year%400 == 0)|| (( year%4 == 0 ) &&( year%100 != 0)))
            return 29;
        else
            return 28;
        case 4 :
        case 6 :
        case 9 :
        case 11 :
        return 30;
    }
    return 0;
}

int main(){
    //initalize variable
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int numyears;
    fin >> numyears;
    int count[7] = {0,0,0,0,0,0,0};
 
    int dotw = 1;
    for (int curryear=0; curryear<numyears; curryear++) {
        for(int currmonth = 1; currmonth <= 12; currmonth++) {
            for (int currday = 1; currday <=  getMonthLen(currmonth, curryear+1900); currday++) {
                
                if (currday==13){
                    count[dotw-1]++;
                }
                if (dotw<7){
                    dotw++;
                }
                else{
                    dotw=1;
                }
                // cout << "year: " << curryear+1900 << " month: "<<currmonth << " day: " << currday << " dotw: " << dotw <<endl;
            }
        }
    }
    fout << count[5] << " ";
    fout << count[6];
    for(int i=0; i < 5; i++){
        fout << " ";
        fout << count[i];
    }
    fout << endl;
}