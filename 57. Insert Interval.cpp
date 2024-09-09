/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end
of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that
represents the start and end of another interval. Insert newInterval into intervals such that intervals is still sorted in ascending order
by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.


Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]


Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^5
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 10^5

*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //Pretty similar to the interval merging problem. We go mostly with the same approach.
        //Complexity: O(n) - time
        
        vector<vector<int>> ans;

        //trivial solution
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }

        int i = 0, n = intervals.size();
        int aux;

        //search for the insertion point of the new interval
        //while doing it, push all intervals before it in the answer
        while(i < n && intervals[i][0] <= newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        //insert new interval by merging or not
        if(!ans.empty() && ans.back()[1] >= newInterval[0]){
            ans.back()[1] = max(ans.back()[1], newInterval[1]);
        }
        else{
            ans.push_back(newInterval);
        }

        //continue the merging/inserting
        while(i < n){

            //save most recent end time for execution speed
            aux = ans.back()[1];

            //if the intervals overlap
            if(aux >= intervals[i][0]){
                ans.back()[1] = max(aux, intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
            i++;
        }

        return ans;

    }
};
