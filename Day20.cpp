/* QUESTION: Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

class Solution {
public:
    bool IsFluctuated(vector<int> & a, int l, int r) {
        for (int i = l+1; i < r; i++) 
             if (a[i] != a[i-1]) return true;
        return false;
    }
    bool search(vector<int>& a, int target) {
       int l = 0;
       int r = a.size()-1;
       while (l <= r) {
           int mid = (l+r)/2;
           
           if (target == a[mid]) return true;
           
           if (a[l] < a[mid]) {
               if (a[l] == target) return true;
               if (target < a[mid] && a[l] < target) r = mid-1;
               else l = mid + 1;
           } 
           
           else if (a[l] > a[mid]) {
               if (a[r] == target || a[l] == target) return true;
               if (target > a[mid] && a[r] > target) l = mid+1;
               else r = mid - 1;
           }
           
           else {
               if (IsFluctuated(a, l, mid)) r = mid - 1;
               else l = mid + 1;
           }
       }
      return false;
    }
};
