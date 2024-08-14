/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //We will use a two pointer approach.
        //We start with both of them on the first position and we initialize a bool vector for the characters.
        //While we can still go right, we move the right pointer one position and check if the character
        //was already found in the current subsequence. If yes we will move the left pointer to the right until we 
        //no longer have the duplicate in the current subsequence.
        //For each subsequence we will compare it to the maxlength and update that variable.
        //Complexity: O(n)
      
        int maxlength = 0;
        int right = 0, left = 0;
        bool visited[256] = {false};

        //Special cases
        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;

        //While we are in the string's bounds
        while(right < s.length())
        {
            //If a character is a duplicate
            if(visited[s[right]] == true)
            {
                //Remove the first appearance from the current substr
                while(visited[s[right]] == true)
                {
                    visited[s[left]] = false;
                    left++;
                }
            }

            //Mark the character as contained in the substr
            visited[s[right]] = true;

            //Compute length and update max
            int len = right - left + 1;
            maxlength = max(maxlength, len);
            right++;
        }

        return maxlength;
    }
};
