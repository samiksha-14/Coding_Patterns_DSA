// Problem Statement
/* 
Given two strings s and t, return true if they are equal when both are typed into empty text editors.
'#' means a backspace character.
Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
*/
// My code

#include <bits/stdc++.h>
using namespace std;
 bool backspaceCompare(string s, string t) {
        int b1=0,b2=0;
        //applying bacKspaces to string s
        for(int i=0;i<s.size();i++)
        {
            if(b1<0) b1=0; 
            if(s[i]=='#')
            {
                b1--;
            }
            
           else
           {
               s[b1]=s[i];
               b1++;
           }
        }
        //applying backspaces to string t
        for(int i=0;i<t.size();i++)
        {
            if(b2<0) b2=0;
            if(t[i]=='#')
            {
                b2--;
                
            }
            
           else
           {
               t[b2]=t[i];
               b2++;
           }
        }
        if(b1!=b2)
            return false;//if no of characters are not equal
        else
        {
            //compare the characters in the string
            for(int i=0;i<b2;i++)
            {
                if(s[i]!=t[i])
                    return false;
            }
            return true;
        }
  }
int main()
{
    
    string s,t;
    cin>>s>>t;
    cout<<backspaceCompare(s,t);
    
   
}
/*
This problem can be solved by using two pointers approach,First apply back space to first string then to the second string
now after applying backspaces (copying the characters to the backspace charachter (#)  to make the character appear before #)
compare both the strings if they are equal then return true else return false
Time Complexity --> O(N)
Space Complexity --> O(1)
*/