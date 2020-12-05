/* QUESTION: Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
*/

class Solution {
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        s = "+" + s;
        return calc(s, 0, 0);
    }
    
    int calc(string& s, long res, int i) {
        if (i == s.size())  return res;
        char op = s[i++];
        long temp = 0;
        while (i < s.size() && isdigit(s[i])) {
            temp = temp * 10 + s[i] - '0';
            i++;
        }
        if (op == '+') {
            return res + calc(s, temp, i);
        }
        else if (op == '-') {
            return res + calc(s, -temp, i);
        }
        else if (op == '*') {
            return calc(s, res * temp, i);
        }
        else
            return calc(s, res / temp, i);
    }
};
