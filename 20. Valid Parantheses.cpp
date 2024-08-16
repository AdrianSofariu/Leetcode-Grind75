/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true


Example 2:

Input: s = "()[]{}"
Output: true


Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
        //We will use a stack on which we will push each open parantheses we encounter.
        //When we find a closed one, we pop from the stack and check if they match
        //if they don't, or the stack is not empty at the end, return false
        //Complexity: O(n)
        stack<char> st;

        for(const char c : s)
        {
            if(c == '(' || c == '[' || c == '{') //push open parantheses
                st.push(c);
            else
            {
                if(st.empty()) //if stack is empty and we have a closed parantheses, return false
                    return false;

                //pop the first and compare if they match
                if(c == ')')
                {
                    char p = st.top();
                    st.pop();
                    if(p != '(')
                        return false;
                }
                else if(c == ']')
                {
                    char p = st.top();
                    st.pop();
                    if(p != '[')
                        return false;
                }
                else if(c == '}')
                {
                    char p = st.top();
                    st.pop();
                    if(p != '{')
                        return false;
                }
            }
        }

        //if at the end the stack is not empty, return false
        if(!st.empty())
            return false;
        return true;
    }
};
