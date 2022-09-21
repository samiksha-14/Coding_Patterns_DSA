// Problem Statement
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated
// sequence of one or more dictionary words.Note that the same word in the dictionary may be reused multiple times in the segmentation.
/*
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/
// My code
///..................top-down dp....................
#include <bits/stdc++.h>
using namespace std;
bool helper(string &s, int pos, unordered_set<string> &st, vector<int> &dp)
{
    if (pos == s.size())
    {
        return true;
    }

    if (dp[pos] != -1)
        return dp[pos];

    for (int i = pos; i <= s.size(); i++)
    {
        string sub = s.substr(pos, i - pos + 1);
        if (st.count(sub) == 1 && helper(s, i + 1, st, dp))
        {
            dp[pos] = 1;
            return true;
        }
    }
    return dp[pos] = false;
}
int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    vector<int> dp(s.length(), -1);
    cout << helper(s, 0, st, dp);
}

/*
So in the above problem we are given a dictonary containing words and a string and we have to break down the string into words(segments)
such that each segment appears in the dictonary and we can use the words in the dictionary multiple times
The segmented word must fall in our dictonary else it will not be a valid word
So try to partition at each possible partition points (each character is a partition point) and only consider it as a valid partition if the word
it is forming is present in the dictionary else it would be a useless partition. So try partition at those words which are already present in the
dictionary....and while doing the partiotions if you reach the end that means your all partitions are valid partitions
So at evey word we have a choice of including the word in partition
Whenever you find a valid word recur for the rest of the string because whenever we make recursive call we are making sure that whatever word was
created was a valid word.....so in this way we will have total of 2^n combinations
And the partions will be overlapping so we will use dynamic programming to improve time complexity
Time Complexity --> O(n^2 * n) (rec calls+ substring comp)
Space Complexity --> O(n)
*/
//
