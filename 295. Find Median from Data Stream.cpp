/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-10^5 <= num <= 10^5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 10^4 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution? - use an array
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution? - use an array for the 0-100 interval and a hashmap for the rest
*/

class MedianFinder {
//We will use a 2 heap approach, keeping a min and a maxheap.
//The maxheap will contain the lower half of the data set (if it was sorted)
//and the minheap the other half.
private:

    //define the 2 heaps
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:


    MedianFinder() {

    }
    
    void addNum(int num) {
    
        //push to maxHeap if it is empty or the number is smaller than the top
        if(maxHeap.size() == 0 || maxHeap.top() >= num)
            maxHeap.push(num);
        else minHeap.push(num);
       
       //balance the heaps
       if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
       }
       //keep the maxheap greater if we have an odd number of entries
       else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
       }

    }
    //Complexity: O(logn)
    
    double findMedian() {
        //if the maxheap is larger, the median is the top
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        
        //else, the median is the mean of the tops of the heaps
        return (double) (maxHeap.top() + minHeap.top()) / 2;

    }
    //Complexity: O(1)

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
