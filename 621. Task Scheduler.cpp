/*
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

 

Constraints:

1 <= tasks.length <= 10^4
tasks[i] is an uppercase English letter.
0 <= n <= 100

*/

//Complexity: O(nlogn) - time, O(1) - space
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int>freq(26,0);

        //count frequency
        for(char t : tasks)
            freq[t - 'A']++;

        //sort descending
        sort(freq.rbegin(), freq.rend());
        int gaps = freq[0] - 1;
        int idle =  gaps * n;

        //check how many idles we can get rid of
        for(int i = 1; i < 26; i++){
            if(freq[i] == 0 || idle <= 0) break; //we ran out of tasks or we got rid of all idles
            idle -= min(freq[i], gaps); //if the freq[i] is large enough we can fill an idle in each gap, otherwise we can get rid freq[i] idles
        }

        idle = max(idle, 0);//make sure idle is 0 or above
        return tasks.size() + idle;
    }
};
