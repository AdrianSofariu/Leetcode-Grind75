/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].


Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4

*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //This problem is very similar to the scheduling problem
        //Sort and then merge if needed
        //Complexity: O(nlogn) - time, O(1) - space

        //trivial solution
        if(intervals.empty()) return {};

        //Sort intervals by starting number
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        //Now go through all intervals and merge them
        vector<vector<int>> output;
        //add the first one
        output.push_back(intervals[0]);

        for(auto& interval : intervals){
            //save only end time for a balance between speed and space used
            int c = output.back()[1];

            //if the intervals overlap, update the limit (merge)
            if(c >= interval[0]){
                output.back()[1] = max(c, interval[1]);
            }
            //else, add the interval
            else{
                output.push_back(interval);
            }
        }
        return output;
    }
};
