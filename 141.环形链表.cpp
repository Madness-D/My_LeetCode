/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        //哈希
        // unordered_map<ListNode*, int> mp;
        // // ListNode* preHead=new ListNode(0,head);
        // // ListNode* cur=preHead;
        // while(head!=nullptr){
        //     if(mp[head]){return true;}
        //     else{
        //     mp[head]++;
        //     head=head->next;
        // }
        // }
        // return false;


        //快慢指针 相遇表明有环
        ListNode* slow=new ListNode(0,head);
        ListNode* fast=head;
        while(slow!=fast){
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
// @lc code=end

