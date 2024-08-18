/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.


Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        //We build a frequency map for each character.
        //Then for each one we add the largest even number less than or equal to the frequency
        //If we have a charcter with an odd frequency we use it as middlepoint and add 1.
        //Complexity: O(n)
        unordered_map<char, int> map;
        int length = 0;
        for(char c : s)
        {
            map[c]++;
        }
        int n = s.size();
        for(auto pair : map)
            if(pair.second > 1)
                length += pair.second - (pair.second % 2);
        if(length < n)
            length += 1;
        return length;
    }
};
