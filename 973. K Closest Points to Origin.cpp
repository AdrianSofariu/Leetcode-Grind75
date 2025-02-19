/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √((x1 - x2)^2 + (y1 - y2)^2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].


Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 10^4
-10^4 <= xi, yi <= 10^4
*/

//Quickselect solution
//LeetCode hates it for some reason allthough it may be the expected solution
//Complexity: O(n) - average, O(n^2) - worst case if already sorted, O(1) - space
class Solution {
private:

int distance(int x, int y){

    return x*x + y*y;
}

//lomuto partition helps us fix the pivot in the correct location while doing quickselect
//can also use hoare
int partition(vector<vector<int>>& arr, int low, int high){
    int pivot = distance(arr[high][0], arr[high][1]);
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(distance(arr[j][0], arr[j][1]) <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    //swap pivot into correct place
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

//modified hoare to also return the index of the pivot but it performs worse than lomuto at the time i was testing
//may improve it in the future
int partition(vector<vector<int>>& arr, int low, int high){
    vector<int> piv = arr[low];
    int pivot = distance(arr[low][0], arr[low][1]);

    while(low < high){
        while(low < high && distance(arr[high][0], arr[high][1]) >= pivot) high--;
        arr[low] = arr[high];
        while(low < high && distance(arr[low][0], arr[low][1]) <= pivot) low++;
        arr[high] = arr[low];
    }
    arr[low] = piv;
    return low;
}

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;

        while(left <= right){
            int idx = partition(points, left, right);

            //if we have an array beginning with the k closest points return it
            if(idx + 1 == k){
                vector<vector<int>> ans(points.begin(), points.begin() + idx + 1);
                return ans;
            }

            //if we have less elements continute right
            if(idx + 1 < k)
                left = idx + 1;
            //if we have more continue left
            else
                right = idx - 1;
        }

        return vector<vector<int>>();
        
    }
};


//Heap solution using MaxHeap
//Complexity: O(NlogK) - time, O(K) - space
class Solution {
private:

int distance(int x, int y){

    return x*x + y*y;
}

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        //pq is a maxheap
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ans;
        int n = points.size();

        //go through all points
        for(int i = 0; i < n; i++){
            int d = distance(points[i][0], points[i][1]);

            //if heap has less than k points, add it
            if(pq.size() < k)
                pq.push({d, {points[i][0], points[i][1]}});
            //otherwise compare the biggest element and replace if the new one is smaller
            else{
                if(d < pq.top().first){
                    pq.pop();
                    pq.push({d, {points[i][0], points[i][1]}});
                }
            }
        }

        //add all points of the heap in an array to return the answer
        while(!pq.empty()){
            auto [d, point] =  pq.top();
            ans.push_back({point.first, point.second});
            pq.pop();
        }

        return ans;
    }
};
