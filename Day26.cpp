/* QUESTION: Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if ((n == 0) && (k > n))
            return 0;
        
        unordered_map<char, int> counter;
        for (auto letter : s)
            counter[letter]++;
        
        int sub1, sub2;
        
        for (int i=0; i<n; i++) {
            if (counter[s[i]] < k) {
                sub1 = longestSubstring(s.substr(0, i), k);
                sub2 = longestSubstring(s.substr(i+1), k);
                break;
            }
            if (i == n-1)
                return n;
        }
        
        return max(sub1, sub2);
    }
};
