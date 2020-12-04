/* QUESTION: Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.

 

Example 1:

Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
Example 2:

Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.
Example 3:

Input: digits = ["7"], n = 8
Output: 1
*/

class Solution {
public:
    int __at_most(vector<int> &digits, int order, int n) {
        int highest, residual;
        int mask, full_res;
        int res;

        mask = full_res = 1;
        for (int i = 0; i < order - 1; i++) {
            mask *= 10;
            full_res *= digits.size();
        }
        
        highest = n / mask;
        residual = n % mask;

        res = 0;
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] > highest)
                continue;
            
            if (digits[i] < highest)
                res += full_res;
            else
                if (order == 1)
                    res += 1;
                else
                    res += __at_most(digits, order-1, residual);
        }
        return res;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int i, j;
        vector<int> d;
        int order, t;
        int res;

        for (i = 0; i < digits.size(); i++)
            d.push_back(stoi(digits[i])); 

        order = 0;
        t = n;
        while (t) {
            t /= 10;
            order += 1;
        }

        res = 0;
        t = 1;
        for (i = 0; i < order - 1; i++) {
            t *= d.size();
            res += t;
        }
        
		res += __at_most(d, order, n);
        return res;
    }
};
