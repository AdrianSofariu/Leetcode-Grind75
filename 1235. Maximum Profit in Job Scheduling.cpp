/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:


Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.


Example 2:

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.


Example 3:

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
1 <= startTime[i] < endTime[i] <= 10^9
1 <= profit[i] <= 10^4
*/


//sorting by starting time
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        //We need to sort all events by starting time.
        //Then we use bottom-up dynamic programming starting from the smallest problem
        //until we solve the main problem.
        //Complexity: O(nlogn) - time, O(n) - space


        //sort all events by starting time
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> events;
        for(int i = 0; i < n; i++){
            events.push_back(make_pair(startTime[i], make_pair(endTime[i], profit[i])));
        }
        sort(events.begin(), events.end());

        //reorder the initial vectors
        for(int i = 0; i < n; i++){
            startTime[i] = events[i].first;
            endTime[i] = events[i].second.first;
            profit[i] = events[i].second.second;
        }

        //dynamic programming
        vector<int>dp(n + 1, 0);

        //This version starts with only the last job
        //and expands the range towards the first one
        //searching the job that begins after the one with index i
        for(int i = n - 1; i >= 0; i--){

            //use binary search to get next index for dp
            int nextJob = lower_bound(startTime.begin() + i, startTime.end(), endTime[i]) - startTime.begin();

            //choose maximum from including/excluding the current job
            dp[i] = max(profit[i] + dp[nextJob], dp[i + 1]);
        }

        return dp[0];
        
    }
};



//variant that sorts by end time
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {


        //sort all events by starting time
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> events;
        for(int i = 0; i < n; i++){
            events.push_back(make_pair(endTime[i], make_pair(startTime[i], profit[i])));
        }
        sort(events.begin(), events.end());

        //reorder the initial vectors
        for(int i = 0; i < n; i++){
            endTime[i] = events[i].first;
            startTime[i] = events[i].second.first;
            profit[i] = events[i].second.second;
        }

        //dynamic programming
        vector<int>dp(n + 1, 0);

        //This one starts with only the first job
        //and expands the range towards the last
        //searching the job that finished before the one with index i
        for(int i = 0; i < n; i++){

            //use binary search to get next index for dp
            int previousJob = upper_bound(endTime.begin(), endTime.begin() + i, startTime[i], [&](int time, const auto& job) -> bool { return time < job; }) - endTime.begin();

            //choose maximum from including/excluding the current job
            dp[i + 1] = max(profit[i] + dp[previousJob], dp[i]);
        }

        return dp[n];
        
    }
};

//very optimized solution I found (NOT BY ME) - Credit: Vivekkrsk
//Instead of saving all three variables in a new array for sorting it only saves the starting time and the initial position saving the space for n integers.
class Solution {
public:

    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
       
        int n = s.size(); 
        vector<pair<int, int>> st(n);
        for(int i = 0; i < n; i++) st[i] = {s[i], i};
        sort(st.begin(), st.end());
        vector<int> dp(n+1, 0); 
        for(int i = n-1; i > -1; i--)
            dp[i] += max(dp[i+1], p[st[i].second] + dp[lower_bound(st.begin() + i, st.end(), make_pair(e[st[i].second], 0)) - st.begin()]);
        return dp[0];
    }
};
