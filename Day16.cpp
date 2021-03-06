/* QUESTION: You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
*/

class Solution {
public:
    int longestMountain(vector<int>& arr) { 
        bool dec = 0 , inc = 0 ;
        int ans = 0    ;
        int so_far = 0 ;
        for(int i = 1 ; i < arr.size() ; )
        {
            if( arr[i] == arr[i-1] && !dec){
                ans  =0 ;
                inc=0,dec=0;
            }
            else if( arr[i] > arr[i-1] && !inc && !dec )
            {
                ans += 2 ;
                inc = 1  ;
            }
            else if(arr[i] > arr[i-1] && inc )
            {
                ++ans ;
            }
            else if( arr[i] < arr[i-1] && inc ){
                inc = 0 ;
                dec = 1 ;
                ++ans   ;
            }
            else if (arr[i] < arr[i-1] && dec ){
                ++ans ;
            }
            else if( arr[i] >= arr[i-1] && dec ){
                inc = 0 ;
                dec = 0 ;
                so_far = max( so_far , ans ) ;
                ans = 0 ;
                continue ;
            }
            ++ i ; 
        }
        if( dec == 1 && inc == 0 ){
            so_far = max(so_far , ans ) ;
        }
        return so_far ;
    }
};
