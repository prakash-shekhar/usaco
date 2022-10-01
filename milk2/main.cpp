/*
ID: prakash35
TASK: milk2
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 27 September 2022
PROBLEM ID      : milk2
DESCRIPTION     : finds the longest continous milking time for cows and the longest idle time in between
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>

using namespace std;

// struct for time interval
struct timemilk{
    int a, b;
};

// sort by start times
bool cmp(const timemilk& x, const timemilk& y) { return x.a < y.a; }


int main()
{
    // initialize
    ofstream cout ("milk2.out");
    ifstream cin ("milk2.in");
    // number of farmers
    int num=0;
    cin >> num;

    // array of times for milking
    vector<timemilk> arr;
    for(int i = 0; i< num; i++)
    {
        // starting(a) and ending(b) times
        int a, b;
        cin >> a >> b;
        timemilk t = {a, b};
        arr.push_back(t);

    }
    // sort by start times
    sort(arr.begin(), arr.end(), cmp);
    // set current start and current end
    int currstart = arr[0].a;
    int currend = arr[0].b;
    // the maximum consecutive time milking
    int maxmilk = 0;
    // maximum time in between milking
    int maxwait = 0;
    for(int i = 0;i<num;i++){
        // cout << arr[i].a << " " << arr[i].b << endl;

        // if the start time for current overlaps with currend
        if(arr[i].a <= currend && arr[i].b >= currend)
        {
            // update currend
            currend = arr[i].b;
        }
        else if(arr[i].a > currend)
        {
            // update maxwait
            maxwait = max(maxwait, arr[i].a-currend);
            // set new starts and ends
            currstart = arr[i].a;
            currend = arr[i].b;
        }
        // update maxmilk
        maxmilk = max(maxmilk, currend-currstart);
        // cout << "start: " << currstart << " end: " << currend << endl;
    }
    // output answer
    cout << maxmilk << " " << maxwait << endl;
    return 0;
}