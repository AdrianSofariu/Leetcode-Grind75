/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".


Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 10^4
s and p consist of lowercase English letters.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //This problem is solved using a technique called "sliding window"
        //We use to frequency arrays: one for the string p and one for each substring of the
        //length of p in s.
        //At each step we compare the frequency arrays. If they are the same we have an anagram
        //To continue, just update the frequency array by removing first character and adding the next.
        //Complexity: O(len(s)) - time, O(1) - space
        int window = p.size();
        int len = s.size();

        //trivial solution
        if(window > len)
            return {};

        vector<int> freqP(26,0), freqS(26,0);


        //build "hashtables" for the string p and the first sequence in s
        for(int i = 0; i < window; i++){
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        vector<int> ans;

        //compare
        if(freqP == freqS)
            ans.push_back(0);

        //now, check the next sequences
        for(int i = window; i < len; i++){

            //remove previous letter
            freqS[s[i - window] - 'a']--;

            //add new letter
            freqS[s[i] - 'a']++;

            //compare
            if(freqS == freqP)
                ans.push_back(i - window + 1);
        }

        return ans;
    }
};
