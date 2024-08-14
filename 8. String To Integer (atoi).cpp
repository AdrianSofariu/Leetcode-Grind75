/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

 

Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^


Example 2:

Input: s = " -042"

Output: -42

Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^



Example 3:

Input: s = "1337c0d3"

Output: 1337

Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^



Example 4:

Input: s = "0-1"

Output: 0

Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
Example 5:

Input: s = "words and 987"

Output: 0

Explanation:

Reading stops at the first non-digit character 'w'.

 

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/


#include <limits.h>

class Solution {
public:
    int myAtoi(string s) {
        //We will process the string character by character and eliminate all starting whitespaces.
        //Then we will check for a sign and lastly for digits to build the number.
        //If the format is not ok, we will return 0.
        //Complexity: O(len)

      
        int len = s.size();  // Get the length of the input string
        int index = 0;       // Initialize an index to traverse the string
        long n = 0;          // Variable to store the resulting number
        int sgn = 1;         // Variable to store the sign of the number, default is positive

        // Skip any leading whitespace characters
        while(s[index] == ' ' && index < len)
            index++;
            
        // Check for a sign character ('-' or '+')
        if(s[index] == '-')
        {
            sgn = -1;  // If negative sign, set sign to -1
            index++;
        }
        else if(s[index] == '+')
        {
            sgn = 1;  // If positive sign, keep sign as 1
            index++;
        }

        // Process the numerical digits and construct the number
        while(s[index] >= '0' && s[index] <= '9' && index < len)
        {
            n = n * 10 + (s[index] - '0');  // Convert the character to an integer and add to the number
            index++;
            
            // Check for overflow and underflow conditions
            if(sgn * n < INT_MIN)
                return INT_MIN;  // If the number goes below INT_MIN, return INT_MIN
            if(sgn * n > INT_MAX)
                return INT_MAX;  // If the number exceeds INT_MAX, return INT_MAX
        }

        // Return the final converted integer with the correct sign
        return sgn * n;
    }
};
