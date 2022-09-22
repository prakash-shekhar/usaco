//URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=592

#include <bits/stdc++.h>
#define FRO(a) for (int i = 0; i < a; i++)
using namespace std;

int findExploded(int i, vector<int> v){
    int balesExploded = 1;
    if(i!=0){
        int j = i;
        int radius=1;
        while(j!=0){

        }
    }
    if(i!=v.size()){

    }
    return balesExploded;
}

//Checks for idx at either end of list
bool atBound (int idx, int size, int direction)
{
    bool retVal = false;
    if(direction > 0)
        if( idx >= size-1)
            retVal = true;
    else
        if( idx <= 0)
            retVal = true;

    return retVal;
}

//Recursive Function to find how far the explosion will propagate
int propagateExplosion(int startIdx, int dir, int prevExpRad, vector<int> Bales){
    int furthestIdx = startIdx;

    //Base case
    if( atBound(startIdx+dir, Bales.size()+dir, dir) || abs(Bales[startIdx + dir] - Bales[startIdx]) > prevExpRad + 1)
            return furthestIdx;

    //Propogate explosion to next Bale
    furthestIdx = propagateExplosion(startIdx+dir, dir, prevExpRad+1, vector<int> Bales)

    return furthestIdx;
}

int main() {
    ofstream fout("angry.out");
    ifstream fin("angry.in");
    int N; fin >> N;
    vector<int> vec;
    FRO(N){
        int A;fin >> A;vec.push_back(A);
    }
    sort(vec.begin(), vec.end());
    vector<int> diff;
    for(int i=0; i<N-1;i++){
        diff.push_back(vec[i+1]-vec[i]);
    }
    int maxCnt=0;
    int cnt=1;
    for(int i=1; i<N-1;i++){
        cnt++;
        if(diff[i]>diff[i-1]+1){
            maxCnt = max(maxCnt, cnt);
            cnt = 0;
        }
    }
    fout << maxCnt << endl;
    findExploded(1, vec);
}