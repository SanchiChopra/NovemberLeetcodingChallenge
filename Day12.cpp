/* QUESTION: Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        string s = "";
        vector<vector<int>> v;
        int len = nums.size();
        for(int x : nums)
        {
            s += x +'0';
        }
        sort(s.begin(),s.end());
        unordered_map<string,int> m;
        do 
        {
            if(m[s]!=1)
            {
                vector<int> k;
                for(char c : s)
                {
                    
                    k.push_back(c -'0');
                    
                }v.push_back(k);
                m[s] = 1;
            }
        } 
        
        while ( next_permutation(s.begin(),s.end()) );
        return v;
    }
};
