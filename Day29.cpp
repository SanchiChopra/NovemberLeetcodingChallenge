/* QUESTION: Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            if(arr[pos] == 0)
                return true;
            int next = pos + arr[pos];
            int prev = pos - arr[pos];
            if(prev >= 0 && visited.count(prev) == 0){
                visited.insert(prev);
                q.push(prev);
            }
            
            if(next < arr.size() && visited.count(next) == 0){
                visited.insert(next);
                q.push(next);
            }
        }
        return false;
    }
};
