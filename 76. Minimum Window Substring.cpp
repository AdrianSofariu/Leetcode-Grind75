/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.


Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.


Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

*/

class Solution {
public:
    string minWindow(string s, string t) {
        //The idea is to maintain a count of the characters in t using a "hashtable"
        //which allows us to check what characters are needed as we traverse s.
        //We use 2 pointers start and j to expand the window in s, keeping track of the matched
        //characters. If all are matched, we then try to minimize the window by advancing the
        //start poinnter, ensuring that the needed characters are still matched
        //Complexity: O(lens + lent) - time, O(1) - space (hashtables are constant size)
        int lens = s.size();
        int lent = t.size();

        //check if length of s is smaller than that of t
        if(lens < lent) return "";

        //last letter is ascii code 122 so 123 is enough
        vector<int> hashS(123, 0);
        vector<int> hashT(123, 0);

        //build hashtable for the string t
        for(int i = 0; i < lent; i++) hashT[t[i]]++;

        int start = 0, start_idx = -1, min_len = INT_MAX;

        //count of matching charachters
        int matched = 0;

        //start traversing the string
        for(int j = 0; j < lens; j++){

            //count the occurence of its characters
            hashS[s[j]]++;

            //if S's char matches T's, increment matched
            if(hashS[s[j]] != 0 && hashS[s[j]] <= hashT[s[j]]){
                matched++;
            }

            //if all characters are matched
            if(matched == lent){

                //try minimizing the window
                while(hashS[s[start]] > hashT[s[start]] || hashT[s[start]] == 0){
                    if(hashS[s[start]] > hashT[s[start]]) 
                        hashS[s[start]]--;
                    start++;
                }

                //update minimum window size
                int len = j - start + 1;
                if(min_len > len){
                    min_len = len;
                    start_idx = start;
                }
            }
        }

        //if none was found, return empty string
        if(start_idx == -1) return "";

        //return the substring
        return s.substr(start_idx, min_len);
    }
};
