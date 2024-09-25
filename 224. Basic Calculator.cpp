/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2


Example 2:

Input: s = " 2-1 + 2 "
Output: 3


Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

*/

class Solution {
public:
    int calculate(string s) {
        //infix evaluation version
        //Complexity: O(n) - time, O(n) - space
        stack<int>st;
        int total = 0;
        int cur_val = 0, sign = 1;

        //go through each character
        for(char c : s)
        {
            //if we find digits we build the number in cur_val
            if(isdigit(c))
            {
                cur_val = 10 * cur_val + (c - '0');
            }
            //if we find a plus, we add our current value to the total knowing what sign it had
            //we also store the new sign as +1
            else if(c == '+')
            {
                total += cur_val * sign;
                cur_val = 0;
                sign = 1;
            }
            //if we find a minus, we add our current value to the total knowing what sign it had
            //we also store the new sign as -1
            else if(c == '-')
            {
                total +=  cur_val * sign;
                cur_val = 0;
                sign = -1;
            }
            //if we find the open bracket, we push the current result and the current sign to the stack
            //then we reset the total and the sign
            else if(c == '(')
            {
                st.push(total);
                st.push(sign);
                total = 0;
                sign = 1;
            }
            //if we find a closed bracket, we add our cur_val to the total
            //and get the previous total from the stack combining them
            else if(c == ')')
            {
                total += cur_val * sign;
                cur_val = 0;

                //multiply with sign
                total = total * st.top();
                st.pop();

                //add number
                total = total + st.top();
                st.pop();
            }
        }

        total += cur_val * sign;
        return total;
    }
};

//very slow according to lc
class Solution {
public:
//Infix to Postfix version
    int precedence(char c){
        if(c == '/' || c == '*')
            return 2;
        else if(c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    void infixToPostfix(string s, vector<string>&postfix){
        int n = s.size();

        stack<char> st; //stack with operators

        for(int i = 0; i < n; i++){

            char c = s[i];

            //handle whitespaces
            if(c == ' ') continue;

            //if we find an operand, we add it to the output string
            if(c >= '0' && c <= '9'){
                string temp = "";
                while(i < n and isdigit(s[i])){
                    temp += s[i];
                    i++;
                }
                i--;
                postfix.push_back(temp); //operand
            }
            else if(c == '('){

                //edge case 1 - ( - 3)
                if(i - 1 >= 0 && i + 1 < n){
                    int j = i - 1;
                    int k = i + 1;
                    while(j >= 0 && s[j] == ' ') j--;
                    while(k < n && s[k] == ' ') k++;

                    if( j >= 0 && k < n && (s[j] == '+' || s[j] == '-') && (s[k] == '+' || s[k] == '-' )){
                        st.pop();
                        st.push('(');
                        if(s[j] == '+' && s[k] == '+') st.push('+');
                        else if(s[j] == '-' && s[k] == '-') st.push('+');
                        else st.push('-');
                        i = k;
                    }
                    else
                        st.push(c);
                }
                else{
                    st.push(c);
                }
            }
            //if the character is an ) pop to output string until we find (
            else if(c == ')'){
                while(st.top() != '('){
                    postfix.push_back(string(1, st.top()));
                    st.pop();
                }
                st.pop(); //pop the open bracket
            }
            else//operator
            {
                while(!st.empty() and precedence(c) <= precedence(st.top())){
                    postfix.push_back(string(1, st.top()));
                    st.pop();
                }

                if(i == 0 && (s[i] == '+' || s[i] == '-') && st.empty()){
                    postfix.push_back("0"); //for edge case "-2+1", add 0 in front of -2
                }
                st.push(c);
            }
        }

        //pop all remaining operators
        while(!st.empty()){
            postfix.push_back(string(1, st.top()));
            st.pop();
        }
    }


    //evaluate postfix
    int evaluatePostfix(vector<string>&p){
        int n = p.size();
        int ans = 0;
        stack<int>st;

        for(int i=0;i<n;i++) {
            if(p[i]=="*" || p[i]=="-" || p[i]=="+" || p[i]=="/") {
                int val2 = st.top(); st.pop();
                int val1 = st.top(); st.pop();
                
                if(p[i]=="+")
                   ans = val1+val2;
                else if(p[i]=="-")
                    ans = val1-val2;
                else if(p[i]=="*")
                    ans = val1 * val2;
                else
                    ans = val1 / val2;

                st.push(ans);
            } else {
                st.push(stoi(p[i])); // can be a string "4325"
            }
        }
        return st.top();
    }


    int calculate(string s) {
        vector<string> postfix;
        infixToPostfix(s, postfix);
        return evaluatePostfix(postfix);
    }
};
