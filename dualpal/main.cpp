/*
ID: prakash35
TASK: dualpal
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 28 September 2022
PROBLEM ID      : dualpal
DESCRIPTION     : Given an integer S indicating the minimum, print the next N numbers where they are palindromic in at least 2 bases it converts to
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>
using namespace std;

// function to check whether string is palindromic
bool isPal(string s)
{
    string rev = s;reverse(rev.begin(), rev.end());
    if(rev==s){
        return true;
    }
    return false;
}

// function to convert an int into a char in ascii
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// function to switch base using Division and Modulo method
string switchBases(int base, int num){
    string newNum = "";
    // Division and Modulo method
    while(num>0){
        // append ascii value of modulo to new Num
        newNum += reVal(num % base);
        num /= base;
    }
    // Reverse the string because of the way division and modulo
    reverse(newNum.begin(), newNum.end());
    return newNum;
}

int main()
{
  // file streams
  ofstream fout("dualpal.out");
  ifstream fin("dualpal.in");
  // amount of numbers to generate
  int num; fin >> num;
  // starting number
  int start; fin >> start;
  // while we have not generated all numbers wanted
  while(num>0){
      // increment by one
      start++;
      // check if palindromic in any base from 2-10
      int numPal = 0;
      for(int i=2; i<=10; i++){
          if(isPal(switchBases(i,start))){
              numPal++;
          }
      }
      // if is palindromic in at least two bases, print out
      if(numPal>=2){
          num--;
          fout << start << endl;
      }
  }
}