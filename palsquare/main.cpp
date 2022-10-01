/*
ID: prakash35
TASK: palsquare
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 28 September 2022
PROBLEM ID      : palsquare
DESCRIPTION     : Given an integer and a list of names determine what valid names can be formed using the integer and a phone number conversion system
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
    {
        return (char)(num + '0');
    }
    else
    {
        return (char)(num - 10 + 'A');
    }
}

// function to switch base using Division and Modulo method
string switchBases(int base, int num)
{
    string newNum = "";
    // Division and Modulo method
    while(num>0)
    {
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
  ofstream fout("palsquare.out");
  ifstream fin("palsquare.in");
  int base; fin >> base;
  // from 1-300 in decimal
  for(int i = 1;i<=300; i++)
  {
      // if the base is valid palindrome
      if(isPal(switchBases(base, pow(i, 2))))
      {
          // print switched base and square
          fout << switchBases(base, i) << ' ' << switchBases(base, pow(i, 2)) << endl;
      }
  }
}