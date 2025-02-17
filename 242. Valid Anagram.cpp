/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
//Complexity: O(n) - time, O(n) - space, n = length of strings
class Solution {
public:
    bool isAnagram(string s, string t) {

        //solution valid for strings with all unciode chars available
        unordered_map<char, int> dict;

        if(s.size() != t.size()) return false;

        //add all characters of s and their counts
        for(int i = 0; i < s.size(); ++i){
            dict[s[i]]++;
            dict[t[i]]--;
        }

        //add all characters of t but also check for them to be only updates not insertions
        for(char c: t){
            
        }

        for(auto it : dict)
            if(it.second != 0)
                return false;
        return true;
    }
};
