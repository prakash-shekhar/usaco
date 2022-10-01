/*
ID: prakash35
TASK: friday
LANG: C++
*/


/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 27 September 2022
PROBLEM ID      : friday
DESCRIPTION     : Given a number of years after 1900, compute the amount of times a 13th date occured on each day of the week
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// function to get amount of days in month
int getMonthLen(int month, int year){
    switch (month) {
        // Months w/ 31 days
        case 1 : case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10 :
        case 12 :
        return 31;
        // February
        case 2 :
        // leap year
        if (( year%400 == 0)|| (( year%4 == 0 ) &&( year%100 != 0)))
            return 29;
        else
            return 28;
        // Months w/ 30 days
        case 4 :
        case 6 :
        case 9 :
        case 11 :
        return 30;
    }
    return 0;
}

int main(){
    //initalize variables for input and output
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    // read in number of years
    int numyears;
    fin >> numyears;
    // output of fridays
    int count[7] = {0,0,0,0,0,0,0};

    // Day of the week we are counting right now
    int dotw = 1;
    // iterate thru years
    for (int curryear=0; curryear<numyears; curryear++) {
        // thru months
        for(int currmonth = 1; currmonth <= 12; currmonth++) {
            // iterate thru days
            for (int currday = 1; currday <=  getMonthLen(currmonth, curryear+1900); currday++) {
                // increment if the day is a 13th
                if (currday==13){
                    count[dotw-1]++;
                }
                // if its less than 7, move to the next day, otherwise reset to Monday
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
    // start with Saturday, Sunday
    fout << count[5] << " ";
    fout << count[6];
    // print rest of week out
    for(int i=0; i < 5; i++){
        fout << " ";
        fout << count[i];
    }
    fout << endl;
}