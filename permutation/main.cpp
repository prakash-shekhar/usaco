#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define FRO(a) for (int i = 0; i < a; i++)
#define len(x) (int)(x).length()

using namespace std;

void search(vector<int> permutation, vector<bool> chosen, int n) {
    if (permutation.size() == n) {
        // process permutation
        for (int i = 0; i < n; i++)
            cout << permutation[i] << " ";
        cout << endl;

    }
    else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search(permutation, chosen, n);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

void combination(vector<int> combinationVector, int k, int n){
    if(k==n){
        for(int a:combinationVector){
            cout << a << " ";
        }
        cout << endl;
    }
    else{
        //dont add anything to the vector and increase level(k+1) in graph
        //left
        combination(combinationVector, k+1, n);
        //add 'k' to the vector, and increase level(k+1) in graph
        //right
        combinationVector.push_back(k);
        combination(combinationVector, k+1, n);
        //remove last element at the end of the loop for the next itercd..
        
        combinationVector.pop_back();
    }
}

int main(){

    // int sz=3;

    // int st[3]={1,2,3};
    // cout << st << endl;
    // cout << st[0] << endl;
    // cout << *(st) << endl;
    // int * dy_arr= new int [sz];

    // combination({}, 0, 3);
    int n = 3;
    for(int size = 1; size<=n; size++){
        for(int i = 0; i<n-size+1;i++){
            cout << size << " " << i << endl;
        }
    }

    // int n = 3;
    // vector<int> permutation;
    // vector<bool> chosen(n);
    // search(permutation, chosen, n);

}