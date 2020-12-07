/* QUESTION: You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> res;
        deque<int> list;
        int n = arr.size();
        int i = 0;
        int j = 0;

        while(j < n){

            while(!list.empty() && list.back() < arr[j]){
                // cout << "popping from the list... " << list.back() << endl;
                list.pop_back();
            }
            
            // cout << "pushing to the list... " << arr[j] << endl;
            list.push_back(arr[j]);
            // cout << "front of the list... " << list.front() << endl;
            
            if(j-i+1 < k){
                j++;
            }

            else if(j-i+1 == k){ //actual window
                res.push_back(list.front());
                if(list.front() == arr[i]){ 
                    //just checking 'going to be popped' element is not the maximum of 
                    //the subarray of the current window before sliding it
                    list.pop_front();
                }
                
                i++;
                j++;
            }
        }
        // cout << "j went to " << j << endl;

        return res;
    }
};
