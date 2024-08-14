/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //Use a dynamic programming approach.
        //We use an array where f[i] signals if the string can be split
        //into words until position i (including i).
        //Complexity: O(n^2 + k) (considering the slicing takes k time where k is the maximum length of a word)

        //Fristly transform the vector into a set for better search complexity
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        int length = s.size();
        bool f[length + 1];

        //set f[i] to false
        memset(f, false, sizeof(f));
    
        //A string with no characters can always be split
        f[0] = true;

        //Iterate through all positions and build the array
        for(int i = 0; i <= length; ++i)
        {
            //Check if substrings for a j from 0 to i-1 are words in the dictionary
            for(int j = 0; j < i; ++j)
            {
                //If s[0...j-1] and s[j..i-1] is a valid word, we set f[i] to true
                if(f[j] && words.count(s.substr(j, i - j)))
                {
                    f[i] = true;
                    break; //if we found a valid segmentation we can stop this iteration 
                }
            }
        }

        //return true if the whole string can be segmented, false otherwise
        return f[length];
    }
};
