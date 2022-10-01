/*
ID: prakash35
TASK: namenum
LANG: C++
*/

/*
NAME            : Prakash Shekhar
GROUP           : Discrete Math
LAST MODIFIED   : 28 September 2022
PROBLEM ID      : namenum
DESCRIPTION     : Given an integer and a list of names determine what valid names can be formed using the integer and a phone number conversion system
PEOPLE I HELPED : None
SOURCES/HELPERS : None
*/

#include <bits/stdc++.h>
using namespace std;

// convert the numerical name to string using telephone conversion
string getchars(int i)
{
  char lst[3];
  // first in key(A)
  lst[0] = "ABCDEFGHIJKLMNOPRSTUVWXY"[((i-2)*3)];
  // second in key(B)
  lst[1] = "ABCDEFGHIJKLMNOPRSTUVWXY"[((i-2)*3)+1];
  // third in key(C)
  lst[2] = "ABCDEFGHIJKLMNOPRSTUVWXY"[((i-2)*3)+2];
  return lst;
}

int main()
{
  // general input streams
  ofstream fout("namenum.out");
  ifstream fin("namenum.in");
  // input stream to dict.txt
  ifstream dictin("dict.txt");
  // the numerical name
  long long id;fin>> id;
  // length of numerical name
  int len = to_string(id).length();
  // vector to store all possible names
  vector<string> namevec;
  // current name in file
  string str;
  // read till end of file
  while (getline(dictin, str))
  {
    // build name
    if(str.size()==len)
    {
      // bool flag = true;
      // iterate for every character in name
      for(int i = 0; i<len; i++)
      {
        // convert int to a string representation of name
        string s = getchars(to_string(id)[i]-48);
        // if any of the names match with the ones in the file set flag on
        if(str[i]==s[0]||str[i]==s[1]||str[i]==s[2])
        {
          flag = true;
        }
        else{
          flag = false;
          break;
        }
      }
      // push back in vector of names
      if(flag)
      {
        namevec.push_back(str);
      }
    }
  }
  // print out all compatible names
  for(string a:namevec)
  {
    fout << a << endl;
  }
  // print NONE if no compatible names
  if(namevec.size()==0)
  {
    fout << "NONE" << endl;
  }
}