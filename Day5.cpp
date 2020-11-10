/* QUESTION: We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.

 

Example 1:


Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
Example 2:


Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.
Example 3:

Input: position = [1,1000000000]
Output: 1
*/

class Solution {
public:
	int minCostToMoveChips(vector<int>& position) {
		short oddNumbers = 0, evenNumbers = 0;
		for (std::vector<int>::iterator it = position.begin(); it != position.end(); ++it)
		{
			if (*it % 2 == 0)
			{
				++evenNumbers;
			}
			else
			{
			   ++oddNumbers; 
			}
		}
		if (oddNumbers >= evenNumbers)
		{
			return evenNumbers;
		}
		return oddNumbers;
	}
};
