/*
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
class Solution {
public:
    string longestPalindrome(string s) {

        //We will search palindromes by using 2 pointers and expanding outwards.
        //For each position i we need to search even and odd length palindromes.
        //When a new maximum is found we keep in a variable the starting position and the length.
        //Complexity: O(n^2)
     
        int left, right;
        int len = s.length();
        int start = 0, maxlength = 1;

        // Iterate over each character in the string
        for(int i = 0; i < len; i++)
        {
            // Check for even-length palindromes centered between i and i-1
            left = i - 1;
            right = i;

            // Expand outwards from the center
            while(left >= 0 && right < len && s[left] == s[right])
            {
                // Update start position and maximum length if a longer palindrome is found
                if(right - left + 1 > maxlength)
                {
                    start = left;
                    maxlength = right - left + 1;
                }
                left--;
                right++;
            }

            // Check for odd-length palindromes centered at i
            left = i - 1;
            right = i + 1;

            // Expand outwards from the center
            while(left >= 0 && right < len && s[left] == s[right])
            {
                // Update start position and maximum length if a longer palindrome is found
                if(right - left + 1 > maxlength)
                {
                    start = left;
                    maxlength = right - left + 1;
                }
                left--;
                right++;
            }
        }

        // Return the longest palindrome substring found
        string result = s.substr(start, maxlength);
        return result;
    }
};
