/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
*/

//solution 1 transforms the string
//Complexity: O(n) - time, O(n) - space
class Solution {
public:
    bool isPalindrome(string s) {
        string aux;

        for(char c : s)
            if(isalnum(c))
                aux += tolower(c);

        int left = 0, right = aux.length() - 1;

        while(left < right){
            if(aux[left] != aux[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
};



//solution 2 works directly on given string and is the better solution imo
//Complexity" O(n) - time, O(1) - space
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while(left < right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};
