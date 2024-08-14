/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 
Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 10^5
ransomNote and magazine consist of lowercase English letters.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //We will just go through the magazine and keep track of the available characters.
        //Then we will go through the ransom note and check if we can build it character by character
        //with the tracked information.
        //Complexity: O(lenMag + lenRansomNote)

        // Create a vector to store the frequency of each character in the magazine
        vector<int> m(26);

        // Iterate through each character in the magazine
        // Increment the corresponding position in the vector for each character
        for(const char &letter : magazine )
            m[letter - 'a']++;

        // Iterate through each character in the ransom note
        for(const char &letter : ransomNote)
        {
            // Check if the character is available in the magazine (frequency > 0)
            if(m[letter - 'a'] == 0)
                return false; // If not, it's not possible to construct the ransom note

            // Decrement the frequency of the character as it is used
            m[letter - 'a']--;
        }

        // If all characters in the ransom note can be constructed from the magazine, return true
        return true;
    }
};
