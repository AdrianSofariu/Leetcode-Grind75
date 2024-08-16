/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]


Example 2:

Input: list1 = [], list2 = []
Output: []


Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //we will use a mock node as head, it will be removed at the end;
        //Complexity: O(n + m)

        ListNode* head = new ListNode;
        ListNode* current = head;
        ListNode* n1 = list1;
        ListNode* n2 = list2;

        while(n1 != NULL && n2 != NULL)
        {
            if(n1->val < n2->val)
            {
                current->next = n1;
                n1 = n1->next;
            }
            else
            {
                current->next = n2;
                n2 = n2->next;
            }
            current = current->next;
        }

        //finish list
        if(n1 != NULL)
        {
            current->next = n1;
        }

        if(n2 != NULL)
        {
            current->next = n2;
        }

        //remove mock node
        current = head;
        head = head->next;
        delete current;
        return head;
    }
};
