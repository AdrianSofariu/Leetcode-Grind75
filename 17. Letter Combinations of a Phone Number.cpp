/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]


Example 2:

Input: digits = ""
Output: []


Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //We will use a vector in which at each position from 0 to 9
        //we will store the characters 
        //Then we could use backtracking to build the solutions, but here
        //i am gonna try to build them iteratively all at the same time using std::move().
        //Complexity: O(n4^n)

        if(digits.empty())
            return {};

        vector<string> ans{""};
        const vector<string> digitToLetter{"", "", "abc", "def", "ghi", "jkl",
                                             "mno", "pqrs", "tuv", "wxyz"};

        //for each digit
        for(const char d : digits)
        {
            //build a temporary answer
            vector<string> temp;

            for(const string& s : ans) //for each string in the answer
                for(const char c : digitToLetter[d - '0']) //for each possible letter corresponding
                    temp.push_back(s + c); // add it to the string
            ans = move(temp); //move the temporary answer to the main answer
        }
        return ans;
    }
};
