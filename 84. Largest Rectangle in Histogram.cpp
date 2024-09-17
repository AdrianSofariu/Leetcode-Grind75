/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.


Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //Complexity: O(n) - time, O(n) - space
        stack<int> s;
        int maxArea = 0;
        int area = 0;
        int i;

        for(i = 0; i < heights.size();){
            if(s.empty() || heights[s.top()] <= heights[i]){
                s.push(i++);
            }else{
                int top = s.top();
                s.pop();      
                //if stack is empty means everything till i has to be
                //greater or equal to heights[top] so get area by
                //heights[top] * i;
                if(s.empty()){
                    area = heights[top] * i;
                }
                //if stack is not empty then everything from i-1 to heights.top() + 1
                //has to be greater or equal to heights[top]
                //so area = heights[top]*(i - stack.top() - 1);
                else{
                    area = heights[top] * (i - s.top() - 1);
                }
                if(area > maxArea){
                    maxArea = area;
                }
            }
        }
        while(!s.empty()){
            int top = s.top();
            s.pop();
            //if stack is empty means everything till i has to be
            //greater or equal to heights[top] so get area by
            //heights[top] * i;
            if(s.empty()){
                area = heights[top] * i;
            }
            //if stack is not empty then everything from i-1 to height.top() + 1
            //has to be greater or equal to heights[top]
            //so area = heights[top]*(i - stack.top() - 1);
            else{
                area = heights[top] * (i - s.top() - 1);
            }
        if(area > maxArea){
                maxArea = area;
            }
        }
        return maxArea;
    }
};
