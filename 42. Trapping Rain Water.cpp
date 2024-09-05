/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5

*/

class Solution {
public:
    int trap(vector<int>& height) {
        //We need to find at each position the amount of water than can be trapped.
        //To do this we find the maximum height to the left and to the right.
        //Because we will exceed the time limit if we compute the maximums the traditional way,
        //we will use a 2 pointer approach. While going through each position of the array we compare it
        //to the current maximums and update the total. To progress we advance the pointer of the side
        //with the lower maximum.
        //The amount of water trapped is min(max(left), max(right)) - height current position
        //Complexity: O(n)

        //use for maximums
        int total = 0;
        int i = 0, j = height.size() - 1;
        int leftMax = height[0], rightMax = height[j];


        while(i < j){

            //if right limit is greater
            if(leftMax <= rightMax){

                //add trapped water
                total += (leftMax - height[i]);

                //advance left
                i++;

                //update max
                leftMax = max(leftMax, height[i]);
            }
            else{
                
                //add trapped water
                total += (rightMax - height[j]);

                //decrement right
                j--;

                //update max
                rightMax = max(rightMax, height[j]);
            }
        }

        return total;
    }
};
