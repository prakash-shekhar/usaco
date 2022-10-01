/*
ID: prakash35
LANG: C++11
TASK: milk3
*/
#include <bits/stdc++.h>
using namespace std;

int acapacity, bcapacity, ccapacity;
set<int> ans;
int visited[20][20][20];
int times = 0;

vector<int> pour(int a, int b, int c, int action)
{
    if (c != 0)
    {
        if (action == 1)
        { // c -> a
            if (c > (acapacity - a))
            { // fill up receiving
                c = c - (acapacity - a);
                a = acapacity;
            }
            else
            { // empty giving
                a = a + c;
                c = 0;
            }
        }
        if (action == 2)
        { // c -> b
            if (c > (bcapacity - b))
            { // fill up receiving
                c = c - (bcapacity - b);
                b = bcapacity;
            }
            else
            { // empty giving
                b = b + c;
                c = 0;
            }
        }
    }
    if (b != 0)
    {
        if (action == 3)
        { // b -> a
            if (b > (acapacity - a))
            { // fill up receiving
                b = b - (acapacity - a);
                a = acapacity;
            }
            else
            { // empty giving
                a = a + b;
                b = 0;
            }
        }
        if (action == 4)
        { // b -> c
            if (b > (ccapacity - c))
            { // fill up receiving
                b = b - (ccapacity - c);
                c = ccapacity;
            }
            else
            { // empty giving
                c = c + b;
                b = 0;
            }
        }
    }
    if (a != 0)
    {
        if (action == 5)
        { // a -> b
            if (a > (bcapacity - b))
            { // fill up receiving
                a = a - (bcapacity - b);
                b = bcapacity;
            }
            else
            { // empty giving
                b = b + a;
                a = 0;
            }
        }
        if (action == 6)
        { // a -> c
            if (a > (ccapacity - c))
            { // fill up receiving
                a = a - (ccapacity - c);
                c = ccapacity;
            }
            else
            { // empty giving
                c = c + a;
                a = 0;
            }
        }
    }
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    return v;
}

void recur(int a, int b, int c, int action)
{
    if(visited[a][b][c]==1){
        return;
    }
    cout << action << " | " << a << " " << b << " " << c << endl;
    if (a == 0)
    {
        ans.insert(c);
        cout << c << endl;
    }
    visited[a][b][c] = 1;
    for (int i = 1; i <= 6; i++)
    {
        vector<int> por = pour(a, b, c, i);
        int ta = por[0];
        int tb = por[1];
        int tc = por[2];
        cout << i << " . " << ta << " " << tb << " " << tc << endl;
        recur(ta, tb, tc, i);
    }
}

int main()
{
    ifstream cin("milk3.in");
    ofstream cout("milk3.out");
    cin >> acapacity >> bcapacity >> ccapacity;
    recur(0, 0, ccapacity, 0);
    set<int>::iterator itr;
    for (itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr;
        if (itr != --ans.end())
        {
            cout << " ";
        }
    }
    cout << endl;
}