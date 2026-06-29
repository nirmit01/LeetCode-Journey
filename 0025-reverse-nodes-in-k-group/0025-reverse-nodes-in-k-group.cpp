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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next=head;
        ListNode *left=head, *right=head,*ans=head,*prevtail=&dummy;
        while(right)
        {
            int cnt=0;
            while(right && cnt<k)
            {
                right=right->next;
                cnt++;
            }
            if(cnt==k)
            {
                ListNode *prev=nullptr, *curr=left;
                while(curr!=right)
                {
                    ListNode* temp2=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=temp2;
                }
                left->next=right;
                prevtail->next=prev;
                prevtail=left;
                left=right;
            }
        }
        return dummy.next;
    }
};