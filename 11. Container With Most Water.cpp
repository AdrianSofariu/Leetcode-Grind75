/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        //We will use a 2 pointer approach starting left and right.
        //Thus at each step we compute the area of the zone
        //and we update the maximum and the lower value pointer accordingly in hope of finding a bigger area.
        //Complexity: O(n)

      
        int maxvol = 0;  // Variable to store the maximum volume (area) found
        int l = 0;       // Pointer to the left boundary of the container
        int r = height.size() - 1;  // Pointer to the right boundary of the container

        // Loop until the two pointers meet
        while(l < r)
        {
            // Calculate the minimum height between the two pointers
            const int minHeight = min(height[l], height[r]);
            // Calculate the area formed by the current left and right boundaries and update maxvol
            maxvol = max(maxvol, minHeight * (r - l));
            
            // Move the pointer corresponding to the shorter boundary inward
            // This is because the area is constrained by the shorter height, so to potentially
            // find a larger area, we try to find a taller boundary by moving the pointer inward
            if(height[l] < height[r])
                l++;  // Move left pointer rightward
            else
                r--;  // Move right pointer leftward
        }

        // Return the maximum area found
        return maxvol;
    }
};
