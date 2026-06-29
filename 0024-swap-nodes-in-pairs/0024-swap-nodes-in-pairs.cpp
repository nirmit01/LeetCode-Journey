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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        dummy.next=head;
        ListNode* left=head, *prevtail=&dummy;
        while(left && left->next)
        {
            ListNode* temp=left->next;
            left->next=left->next->next;
            temp->next=left;
            prevtail->next=temp;
            prevtail=left;
            left=left->next;
        }
        return dummy.next;
    }
};