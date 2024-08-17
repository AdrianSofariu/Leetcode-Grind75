/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6


Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    //This problem can be solved using a heap or using divide and conquer.
    //I will solve it using a iterative divide and conquer, where we merge list 1 and 2,
    //3 and 4, etc.
    //Then we will merge these merged lists until we obtain 1 list.
    //Complexity: nlogk (n = total nr of nodes, k = nr of lists)


    //merge two lists
    ListNode* merge(ListNode* head1, ListNode* head2){
        if(!head1)
            return head2;
        if(!head2)
            return head1;

        ListNode* l1 = head1;
        ListNode* l2 = head2;
        ListNode* result = NULL;
        ListNode* tail = NULL;

        while(l1 && l2){
            if(l1->val < l2->val)
            {
                if(tail)//not the head node
                {
                    tail->next = l1;
                    tail = tail->next;
                }
                else//update head
                {
                    tail = l1;
                    result = l1;
                }
                //advance in the first list
                l1 = l1->next;
                tail->next = NULL;
            }
            else
            {
                if(tail)//not the head node
                {
                    tail->next = l2;
                    tail = tail->next;
                }
                else//update head
                {
                    tail = l2;
                    result = l2;
                }
                //advance in the second list
                l2 = l2->next;
                tail->next = NULL;
            }
        }

        //take care of the rest of the lists
        if(l1)
            tail->next = l1;
        else
            tail->next = l2;
        return result;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0)
            return {};
        if(n == 1)
            return lists[0];

        int lim = log2(n); //this shows how many time we loop to merge pairs of lists

        for(int i = 0; i <= lim; i++)
        {
            int step = 2 << i; //the step increases by powers of 2 with each iteration
            int next = step >> 1; //the distance between 2 lists is the step divided by 2
            for(int j = 0; j < n; j += step)
            {
                if(j + next < n)
                    lists[j] = merge(lists[j], lists[j + next]);
            }
        }
        return lists[0];
    }
};
