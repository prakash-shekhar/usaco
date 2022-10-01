/*
ID: prakash35
TASK: beads
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 27 September 2022
PROBLEM ID      : beads
DESCRIPTION     : Given a necklace of red white and blue colors, determine the optimal point to cut the necklace so that the most beads can be collected
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>

using namespace std;



int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    // length of the string
    int len=0;
    fin >> len;
    // the necklace
    string beadstr="";
    fin >> beadstr;
    // double the necklace so we do not have to worry about going out of bounds
    beadstr+=beadstr;
    // current max beads for necklace
    int max = 0;

    int lena=len/2;
    int lenb=len/2;

    // for every bead in the necklace
    for(int i=0; i<len; i++){
        // create a new string from that bead
        string currstring="";
        for(int j=i; j<len+i; j++){
            currstring += beadstr[j];
        }

        // traverse necklace from the left
        // index
        int j = 0;
        // flag for while loop
        bool done = false;
        // if a color is set
        bool set = false;
        // color of bead that is being counted
        char element;
        while (!done) {
            // if the index exceeds halfway break out
            if(j > lena){
                break;
            }
            // if white bead then just increment
            else if(currstring[j] == 'w'){
                j++;
            }
            // set color if not already
            else if (set==false) {
                set=true;
                element=currstring[j];
                j++;
            }
            // if current bead matches the color of bead we are counting
            else if (set==true && currstring[j]==element) {
                j++;
            }
            // streak of color is over: quit while loop
            else {
                done=true;
            }
        }


        // traverse necklace from the right

        // index from the right
        int ja = len-1;
        // the total amount()
        int tot = len-1;
        // flag for while loop
        bool donea = false;
        // if a color has been set yet
        bool seta = false;
        // current bead color that we are tracking
        char elementa;
        while (!donea) {
            // break out of while if it surpasses the halfway mark
            if(ja <= lenb){
                break;
            }
            // move iterator if bead is white
            else if(currstring[ja] == 'w'){
                ja--;
                tot--;
            }
            // if it has not been set and the current bead is the same color as the left to right then move both iterators
            else if(seta==false && currstring[ja] == element){
                ja--;
                j++;
            }
            //
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

        // if current value is bigger than the max, replace max
        if((len-1-ja)+j>max){
            max=(len-1-ja)+j;
        }
    }
    // output maximum amount
    fout << max << endl;
    return 0;
}