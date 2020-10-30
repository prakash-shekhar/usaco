/*
ID: prakash35
TASK: test
LANG: C++                 
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //initialize
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int num=0;
    fin >> num;
    int maxmilk=0;
    int maxwait=0;

    //create array
    int arr[num][2];
    for(int i = 0; i< num; i++){
        int a, b;
        fin >> a >> b;
        arr[i][0]=a;
        arr[i][1]=b;
    }
    //continuous milking
    for (int i =0; i< num; i++) {
        int diff=arr[i][1]-arr[i][0];
        int wait = 0;
        if ((i+1)<num){
            wait=arr[i+1][0]-arr[i][1];
        }
        for (int j=i+1; j<num; j++) {
            if (arr[j][0]<arr[j-1][1]) {
                diff = arr[j][1]-arr[i][0];
            }
        }
        if(diff>maxmilk){
            maxmilk=diff;
        }
        if (wait>maxwait) {
            maxwait=wait;
        }

    }
    fout << maxmilk << " " << maxwait << endl;
    return 0;
}