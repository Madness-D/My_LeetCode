/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
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
        ListNode* Dummy=new ListNode(0);//哑节点
        Dummy->next=head;

        ListNode* curr=Dummy;
        while(curr->next!=nullptr && curr->next->next!=nullptr){
            ListNode* n1=curr->next;
            ListNode* n2=curr->next->next;
            //curr->next=n1->next
            //curr->next=n2;
            curr->next=curr->next->next;
            //顺序问题
            n1->next=n2->next;
            n2->next=n1;
            curr=n1;
       }

        return Dummy->next;

    }
};
// @lc code=end

